#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

template <class F> class Nodo
{
private:
    F* key;
    Nodo<F> *right,*left,*parent;
    char flag;

public:
    Nodo(F x)
    {
        this->key=new F(x);
        right=left=parent=NULL;
        flag=0;
    }

    void setKey(F x) {this->key=new F(x);}
    void setRight(Nodo<F> *right) {this->right=right;}
    void setLeft(Nodo<F> *left) {this->left=left;}
    void setParent(Nodo<F> *parent) {this->parent=parent;}
    void setFlag(char f) { this->flag=f; }

    F getKey() { return *key; }
    Nodo<F>* getRight() {return right;}
    Nodo<F>* getLeft() {return left;}
    Nodo<F>* getParent() {return parent;}
    char getFlag() { return flag; }

};

template <class H> class BST
{
    private:
        int n;
        Nodo<H> *root;

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
			cout<<p<<endl<<endl;
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
            root=NULL;
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

        Nodo<H>* minimo()
        {
            return _minimo(root);
        }

        Nodo<H>* successore(Nodo<H>* tmp)
        {
            return _successore(tmp);
        }

        Nodo<H>* rsearch(H x)
        {
            return _rsearch(root,x);
        }

};

int main()
{
    ifstream inf("input.txt");
    ofstream of("output.txt");
    string l;
    while(getline(inf,l))
    {
        istringstream iss(l);
        string tipo;
        int n;
        iss>>tipo>>n;
        if(tipo=="int")
        {
            BST<int> *al=new BST<int>();
            for(int i=0;i<n;i++)
            {
                int tmp;
                iss>>tmp;
                al->insert(tmp);
            }
            Nodo<int>* t=al->minimo();
            for(int i=0;i<n;i++)
            {
                cout<<n<<endl;
                int tmp;
                iss>>tmp;
                t->setKey(tmp);
                cout<<t<<endl;
                t=al->successore(t);
                cout<<t<<endl;
            }
            al->postorder(of);
        }
        else
            of<<endl;


    }
}
