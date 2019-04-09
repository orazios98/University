#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <class N> class Nodo
{
    private:
        N *key;
        Nodo<N> *right,*left,*parent;
        char flag;

    public:

        Nodo(N key)
        {
            this->key=new N(key);
            left = right = parent = NULL;
            flag = 0;
        }

        void setKey(N x) {this->key=new N(x);}
        void setRight(Nodo<N> *right) {this->right=right;}
        void setLeft(Nodo<N> *left) {this->left=left;}
        void setParent(Nodo<N> *parent) {this->parent=parent;}
        void setFlag(char f) { this->flag=f; }

        N getKey() { return *key; }
        Nodo<N>* getRight() {return right;}
        Nodo<N>* getLeft() {return left;}
        Nodo<N>* getParent() {return parent;}
        char getFlag() { return flag; }
};

template <class H> class BST
{
    private:
        int n;
        Nodo<H> *root,*current;

        int max(int a, int b)
        {
            if(a>b)
                return a;
            return b;
        }

        void _inorder(Nodo<H> *x, ofstream& f)
        {
            if(x)
            {
                _inorder(x->getLeft(),f);
                f<<x->getKey()<<" ";
                _inorder(x->getRight(),f);
            }
        }

        void _preorder(Nodo<H> *x, ofstream& f)
        {
            if(x)
            {
                f<<x->getKey()<<" ";
                _preorder(x->getLeft(),f);
                _preorder(x->getRight(),f);
            }
        }

        void _postorder(Nodo<H>*x, ofstream& f)
        {
            if(x)
            {
                _postorder(x->getLeft(),f);
                _postorder(x->getRight(),f);
                f<<x->getKey()<<" ";
            }
        }

        int _altezza(Nodo<H>* tmp)
        {
            if(!tmp) return 0;
            return max(_altezza(tmp->getLeft()),_altezza(tmp->getRight()))+1;
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

		Nodo<H>* _successore(Nodo<H>* tmp) {
			if(tmp->getRight())
				return _minimo(tmp->getRight());
			Nodo<H> *p = tmp->getParent();
			while(p!=NULL && p->getKey()<tmp->getKey())
				p = p->getParent();
			return p;
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
            n=0;
            root=current=NULL;
        }

        BST<H>* insert(H x)
        {
            Nodo<H> *node=root;
            Nodo<H> *p=NULL;

            while(node!=NULL)
            {
                p=node;
                if(x>node->getKey())
                    node=node->getRight();
                else
                    node=node->getLeft();
            }

            Nodo<H> *newn = new Nodo<H>(x);
            n++;
            if(p==NULL)
            {
                root=newn;
                return this;
            }

            if(x>p->getKey())
                p->setRight(newn);
            else
                p->setLeft(newn);
            newn->setParent(p);
            return this;



        }

        void inorder(ofstream& f)
        {
            _inorder(root, f);
            f<<endl;
        }

        void preorder(ofstream& f)
        {
            _preorder(root, f);
            f<<endl;
        }

        void postorder(ofstream& f)
        {
            _postorder(root, f);
            f<<endl;
        }

        void canc(H x)
        {
            _canc(root,x);
            return;
        }

        int altezza()
        {
            return _altezza(root);
        }

        int prof(H x)
        {
            Nodo<H> *tmp=_rsearch(root, x);
            if(!tmp) return -1;
            int p=0;
            while(tmp!=root)
            {
                tmp=tmp->getParent();
                p++;
            }
            return p;
        }

        void reset()
        {
            current=_minimo(root);
        }

        Nodo<H>* next()
        {
            Nodo<H>* tmp=current;
            current=_successore(current);
            return tmp;
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
        iss>>tipo>>n;
        if(tipo=="int")
        {
            BST<int>* alb=new BST<int>();
            int st;
            for(int i=0;i<n;i++)
            {
                iss>>st;
                alb->insert(st);
            }
            alb->reset();
            for(int i=0;i<n;i++)
            {
                iss>>st;
                alb->next()->setKey(st);
            }
            alb->postorder(of);

        }
        if(tipo=="double")
        {
            BST<double>* alb=new BST<double>();
            double st;
            for(int i=0;i<n;i++)
            {
                iss>>st;
                alb->insert(st);
            }
            alb->reset();
            for(int i=0;i<n;i++)
            {
                iss>>st;
                alb->next()->setKey(st);
            }
            alb->postorder(of);
        }
    }
}


