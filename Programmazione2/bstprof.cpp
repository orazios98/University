#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
#include <sstream>

using namespace std;

int max(int a, int b) { return a>b?a:b; }

template <class F> class Nodo {
	private:
		F* key;
		Nodo<F> *left, *right, *parent;
		char flag;
	public:
		Nodo(F key) {
			this->key = new F(key);
			left = right = parent = NULL;
			flag = 0;
		}
		void setKey(F key) { this->key = new F(key); }
		void setLeft(Nodo<F>* left) { this->left = left; }
		void setRight(Nodo<F>* right) { this->right = right; }
		void setParent(Nodo<F>* parent) { this->parent = parent; }
		void setFlag(char flag) { this->flag = flag; }
		F getKey() { return *key; }
		char getFlag() { return flag; }
		Nodo<F>* getLeft() { return left; }
		Nodo<F>* getRight() { return right; }
		Nodo<F>* getParent() { return parent; }
};

template <class H> class BST {
	private:
		Nodo<H>* root, *current;
		int n;
		Nodo<H>* _search(H x) {
			Nodo<H>* tmp = root;
			while(tmp && tmp->getKey()!=x) {
				if(x < tmp->getKey()) tmp=tmp->getLeft();
				else tmp=tmp->getRight();
			}
			return tmp;
		}

		Nodo<H>* _rsearch(Nodo<H>* tmp, H x) {
			if(!tmp) return NULL;
			if(tmp->getKey()==x) return tmp;
			if(x<tmp->getKey()) return _rsearch(tmp->getLeft(),x);
			return _rsearch(tmp->getRight(),x);
		}

		Nodo<H>* _minimo(Nodo<H> *tmp) {
			while(tmp->getLeft()!=NULL)
				tmp=tmp->getLeft();
			return tmp;
		}

		Nodo<H>* _massimo(Nodo<H> *tmp) {
			while(tmp->getRight()!=NULL)
				tmp=tmp->getRight();
			return tmp;
		}

		Nodo<H>* _successore(Nodo<H>* tmp) {
			if(tmp->getRight())
				return _minimo(tmp->getRight());
			Nodo<H> *p = tmp->getParent();
			while(p!=NULL && p->getKey()<tmp->getKey())
				p = p->getParent();
			return p;
		}

		Nodo<H>* _predecessore(Nodo<H>* tmp) {
			if(tmp->getLeft())
				return _massimo(tmp->getLeft());
			Nodo<H> *p = tmp->getParent();
			while(p!=NULL && p->getKey()>tmp->getKey())
				p = p->getParent();
			return p;
		}

		void _inorder(Nodo<H> *x,ofstream& f) {
			if(x) {
				_inorder(x->getLeft(),f);
				f << x->getKey() << " ";
				_inorder(x->getRight(),f);
			}
		}

		void _preorder(Nodo<H> *x,ofstream& f) {
			if(x) {
				f << x->getKey() << " ";
				_preorder(x->getLeft(),f);
				_preorder(x->getRight(),f);
			}
		}

		void _postorder(Nodo<H> *x,ofstream& f) {
			if(x) {
				_postorder(x->getLeft(),f);
				_postorder(x->getRight(),f);
				f << x->getKey() << " ";
			}
		}

		int _altezza(Nodo<H> *tmp) {
			if(!tmp) return 0;
			return max(_altezza(tmp->getLeft()),
					   _altezza(tmp->getRight())
					) + 1;
		}

		void _canc(Nodo<H> *r, H x) {
			Nodo<H> *tmp = _rsearch(r, x);
			if(!tmp) return;
			Nodo<H> *parent = tmp->getParent();
			if(!tmp->getLeft() || !tmp->getRight()) {
				// caso 1 & caso 2
				n--;
				Nodo<H> *figlio = tmp->getRight();
				if(tmp->getLeft()) figlio = tmp->getLeft();
				// figlio punta all'unico figlio presente
				// se non sono presenti figli punta a NULL
				if(!parent) root=figlio;
				else {
					if(tmp==parent->getLeft()) parent->setLeft(figlio);
					else parent->setRight(figlio);
				}
				if(figlio) figlio->setParent(parent);
			}
			else {
				// caso 3
				Nodo<H> *succ = _successore(tmp);
				tmp->setKey(succ->getKey());
				_canc(tmp->getRight(),succ->getKey());
			}
			return;
		}
	public:
		BST() {
			root = NULL;
			n = 0;
			current = NULL;
		}

		BST<H>* insert(H x) {
			Nodo<H> *node = root;
			Nodo<H> *p = NULL;
			while(node!=NULL) {
				p = node;
				if(x > node->getKey()) node=node->getRight();
				else  node=node->getLeft();
			}
			Nodo<H>* newn = new Nodo<H>(x);
			n++;
			if(p==NULL) {
				root = newn;
				return this;
			}
			if(x < p->getKey())	p->setLeft(newn);
			else p->setRight(newn);
			newn->setParent(p);
			return this;
		}

		int search(H x) {
			if(_rsearch(root,x)) cout << "elemento " << x << " presente " << endl;
			else cout << "elemento " << x << " non presente " << endl;
			return ( _search(x)!=NULL );
		}

		H minimo() {
			return (_minimo(root))->getKey();
		}
		H massimo() {
			return (_massimo(root))->getKey();
		}
		H* successore(H x) {
			Nodo<H> *tmp = _search(x);
			if(!tmp) {
				cout << "nodo non presente!" << endl;
				return NULL;
			}
			Nodo<H> *s = _successore(tmp);
			if(!s) {
				cout << "successore non presente!" << endl;
				return NULL;
			}
			cout << "successore di " << x << " : " << s->getKey() << endl;
			return new H(s->getKey());
		}
		H* predecessore(H x) {
			Nodo<H> *tmp = _search(x);
			if(!tmp) {
				cout << "nodo non presente!" << endl;
				return NULL;
			}
			Nodo<H> *s = _predecessore(tmp);
			if(!s) {
				cout << "predecessore non presente!" << endl;
				return NULL;
			}
			cout << "predecessore di " << x << " : " << s->getKey() << endl;
			return new H(s->getKey());
		}

		void reset() {
			current = _minimo(root);
		}

		H* next() {
			if(current) {
				H *tmp = new H(current->getKey());
				current = _successore(current);
				return tmp;
			}
			return NULL;
		}

		int has_next() {
			return (current!=NULL);
		}

		void inorder(ofstream& f) {
			_inorder(root,f);
			f << endl;
		}

		void preorder(ofstream& f) {
			_preorder(root,f);
			f << endl;
		}

		void postorder(ofstream& f) {
			_postorder(root,f);
			f << endl;
		}


		int altezza() {
			return _altezza(root);
		}

		int prof(H x) {
			Nodo<H> *tmp = _search(x);
			if(!tmp) return -1;
			int p = 0;
			while(tmp!=root) {
				tmp = tmp->getParent();
				p++;
			}
			return p;
		}

		void canc(H x) {
			_canc(root, x);
		}
};

int main()
{
    ifstream inf("input.txt");
    ofstream of("output.txt");
    string l;
    string tipo, stampa;
    int n;
    while(getline(inf,l))
    {
        istringstream iss(l);
        iss>>tipo;
        iss>>n;
        iss>>stampa;
        cout<<tipo<<" "<<n<<" "<<stampa<<endl;

        if(tipo=="int")
        {
            BST<int>* t = new BST<int>();
            int tmp;
            for(int i=0;i<n;i++)
            {

                iss>>tmp;
                t->insert(tmp);
            }
            if(stampa=="postorder")
                t->postorder(of);
            if(stampa=="inorder")
                t->inorder(of);
            if(stampa=="preorder")
                t->preorder(of);
        }
        if(tipo=="double")
        {
            BST<double>* t = new BST<double>();
            double dbl;
            for(int i=0;i<n;i++)
            {
                iss>>dbl;
                t->insert(dbl);
            }
            if(stampa=="postorder")
                t->postorder(of);
            if(stampa=="inorder")
                t->inorder(of);
            if(stampa=="preorder")
                t->preorder(of);
        }
        if(tipo=="bool")
        {
            BST<bool>* t = new BST<bool>();
            bool tmp;
            for(int i=0;i<n;i++)
            {

                iss>>tmp;
                t->insert(tmp);
            }
            if(stampa=="postorder")
                t->postorder(of);
            if(stampa=="inorder")
                t->inorder(of);
            if(stampa=="preorder")
                t->preorder(of);
        }
        if(tipo=="char")
        {
            BST<char>* t = new BST<char>();
            char tmp;
            for(int i=0;i<n;i++)
            {
                iss>>tmp;
                t->insert(tmp);
            }
            if(stampa=="postorder")
                t->postorder(of);
            if(stampa=="inorder")
                t->inorder(of);
            if(stampa=="preorder")
                t->preorder(of);
        }

    }

}

