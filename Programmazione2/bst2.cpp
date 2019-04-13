#include <iostream>
#include <time.h>
#include <math.h>
#include "immintrin.h"
using namespace std;

template <class T> class BSTNodo {
	private:
		T key;
		BSTNodo<T> *left, *right, *parent;
	public:
		BSTNodo(T key, BSTNodo<T>* parent=NULL, BSTNodo<T>* left=NULL, BSTNodo<T>* right=NULL) { 
			this->key = key;
			this->parent = parent;
			this->left = left;
			this->right = right;
		}
		void setKey(T key) { this->key = key; }
		void setParent(BSTNodo<T>* parent) { this->parent = parent; }
		void setLeft(BSTNodo<T>* left) { this->left = left; }
		void setRight(BSTNodo<T>* right) { this->right = right; }
		T getKey() { return key; }
		BSTNodo<T>* getParent() { return parent; }
		BSTNodo<T>* getLeft() { return left; }
		BSTNodo<T>* getRight() { return right; }
		int isLeaf() { return (!right && !left); }
};

template <class T> class BST {
	private: 
		int n;
		BSTNodo<T> *root, *current;
		BSTNodo<T> *_search(BSTNodo<T>* t, T x) {
			if(!t) return NULL;
			if(t!=NULL && t->getKey()==x) return t;
			if( x<t->getKey() )
				return _search(t->getLeft(),x);
			else return _search(t->getRight(),x);
		}
		void _preOrder(BSTNodo<T>* t) {
			if(!t) return;
			cout << t->getKey() << " ";
			_preOrder(t->getLeft());
			_preOrder(t->getRight());
		}

		void _postOrder(BSTNodo<T>* t) {
			if(!t) return;
			_postOrder(t->getLeft());
			_postOrder(t->getRight());
			cout << t->getKey() << " ";
		}

		void _inOrder(BSTNodo<T>* t) {
			if(!t) return;
			_inOrder(t->getLeft());
			cout << t->getKey() << " ";
			_inOrder(t->getRight());
		}

		int _altezza(BSTNodo<T>* t) const {
			if(!t) return -1;
			int h1 = _altezza(t->getLeft());
			int h2 = _altezza(t->getRight());
			return (h1>h2 ? h1:h2)+1;
		}
		
		BSTNodo<T>* _min(BSTNodo<T>* t) {
			if(!t) return NULL;
			if(t->getLeft()) 
				return _min(t->getLeft());
			return t;
		}

		BSTNodo<T>* _max(BSTNodo<T>* t) {
			if(!t) return NULL;
			if(t->getRight()) 
				return _max(t->getRight());
			return t;
		}
		
		BSTNodo<T>* _succ(BSTNodo<T> *t) {
			if(!t) return NULL;
			if(t->getRight()) 
				return _min(t->getRight());
			BSTNodo<T> *p = t->getParent();
			while(p && p->getKey()< t->getKey())
				p = p->getParent();
			return p;
		}
		
	public:
		BST() {
			n = 0;
			root = NULL;
			current = NULL;
		}
		
		int search(T x) {
			if( _search(root, x) ) return 1;
			return 0;
		}
		
		BST<T>* ins(T x) {
			BSTNodo<T> *p = NULL;
			BSTNodo<T> *t = root;
			while(t!=NULL) {
				p = t;
				if(t->getKey()>x) 
					t = t->getLeft();
				else t = t->getRight();
			}
			BSTNodo<T> *newn = new BSTNodo<T>(x, p);
			if(!p) root = newn;
			else {
				if(p->getKey()>=x) p->setLeft(newn);
				else p->setRight(newn);
			}
			n++;
			return this;
		}	
		
		void preOrder() {
			_preOrder(root);
			cout << endl;
		}

		void postOrder() {
			_postOrder(root);
			cout << endl;
		}

		void inOrder() {
			_inOrder(root);
			cout << endl;
		}

		
		T* min2() {
			BSTNodo<T>* t = root;
			if(!t) return NULL;
			while(t->getLeft()) {
				t = t->getLeft();
			}
			return new T(t->getKey());
		}
		
		T* min() {
			BSTNodo<T>* t = _min(root);
			if(!t) return NULL;
			return new T(t->getKey());
		}

		T* max() {
			BSTNodo<T>* t = _max(root);
			if(!t) return NULL;
			return new T(t->getKey());
		}
		
		T* succ(T x) {
			BSTNodo<T>* t = _search(root, x);
			return new T(_succ(t)->getKey());
		}
		
		T* begin() {
			current = _min(root);
			if(current) return new T(current->getKey());
			else return NULL;
		}
		
		T* next() {
			current = _succ(current);
			return current? new T(current->getKey()):NULL;
		}
		
		int hasNext() {
			return _succ(current)?1:0;
		}

		int prof(T x) {
			BSTNodo<T>* t = _search(root, x);
			if(!t) return -1;
			int pr = 0;
			while( t!=root ) {
				t=t->getParent();
				pr++;
			}
			return pr;
		}
		
		int altezza() const {
			return _altezza(root);
		}
		
		BST<T>* del(T x) {
			BSTNodo<T>* t = _search(root, x);
			if(!t) return this;
			n--;
			BSTNodo<T>* p = t->getParent();
			BSTNodo<T>* y = t->getLeft();
			if(!y) y = t->getRight();

			if( t->getLeft() && t->getRight() ) { // caso 3
				BSTNodo<T>* x = _succ(t);
				t->setKey(x->getKey());
				t = x;
				y = x->getRight();
				p = x->getParent();
			}
			// caso 2 & caso 1
			if(p) {
				if( p->getKey() > t->getKey() )
					p->setLeft(y);
				else p->setRight(y);
			}
			else root = y;
			if(y) y->setParent(p);
			return this;
		}
};

template<class H>  BST<H> operator+(const BST<H>& t, const H& x) {
	BST<int> nt = t;
	nt.ins(x);
	return nt;
}

template<class H>  BST<H> operator-(const BST<H>& t, const H& x) {
	BST<int> nt = t;
	nt.del(x);
	return nt;
}

template<class H> BST<H> operator+(const BST<H>& t1, const BST<H>& t2) {
	BST<int> nt = t1;
	BST<int> t3 = t2;
	H* e = t3.begin();
	while(e) {
		nt = nt + *e;
		e = t3.next();
	}
	return nt;
}

template<class H> int operator<(const BST<H>& t1, const BST<H>& t2) {
	return t1.altezza() < t2.altezza();
}

template<class H> int operator>(const BST<H>& t1, const BST<H>& t2) {
	return t1.altezza() > t2.altezza();
}

template<class H> int operator==(const BST<H>& t1, const BST<H>& t2) {
	return t1.altezza() == t2.altezza();
}

template<class H> int operator!=(const BST<H>& t1, const BST<H>& t2) {
	return t1.altezza() != t2.altezza();
}

template<class H> int operator>=(const BST<H>& t1, const BST<H>& t2) {
	return t1.altezza() >= t2.altezza();
}

template<class H> int operator<=(const BST<H>& t1, const BST<H>& t2) {
	return t1.altezza() <= t2.altezza();
}


int main() {
	BST<int> *T = new BST<int>();
	T->ins(7)->ins(5)->ins(13)->ins(3)->ins(10)->ins(17);
	T->ins(8)->ins(11);
	T->preOrder();
	
	int* e = T->begin();
	while(e) {
		cout << *e << " ";
		e = T->next();
	}
	cout << endl;
	T->del(7)->del(8);
	T->inOrder();
	
	*T = *T + 6;
	T->inOrder();
	
	BST<int> *T2 = new BST<int>();
	*T2 = *T2 + 5+ 7+ 1+ 19 + 10 + 3; 
	
	cout << "Altezza di T : " << T->altezza() << endl;
	cout << "Altezza di T2: " << T2->altezza() << endl;
	if(*T+6 == *T2) cout  << "OK" << endl;
	
}