#include <iostream>
#include <time.h>
#include <math.h>
#include "stack.cpp"
using namespace std;

template <class F> class Nodo
{
    private:
        F* key;
        Nodo <F>* left, *right, *parent;
        char flag;
    public:
        Nodo(F key)
        {
            this->key = new F(key);
            left=right=parent=NULL;
            flag = 0;
        }

        void setFlag(char flag) { this->flag = flag;}
        void setKey(F key) { this->key = new F(key);}
        void setLeft(Nodo<F>* left) { this->left = left;}
        void setRight(Nodo<F>* right) { this->right = right;}
        void setParent(Nodo<F>* parent) { this->parent = parent;}

        F* getKey (){return key;}
        Nodo<F>* getLeft(){return left;}
        Nodo<F>* getRight(){return right;}
        Nodo<F>* getParent(){return parent;}
        char getFlag() {return flag;}
};

template <class H> class BST 
{


    private:
        Nodo <H>* root;
        Nodo <H>* current;
        int n;

        Nodo <H>* _search(H x)
        {
            Nodo<H> tmp = root;
            while(tmp && tmp->getKey()!=x)
            {
                if(x<tmp->getKey()) tmp=tmp->getLeft();
                else tmp=tmp->getRight();
            }
            return tmp;
        }

        Nodo<H>* _minimo(Nodo<H> *tmp)
        {
            while(tmp->getLeft()!=NULL)
                tmp=tmp->getLeft();
            return tmp;
        }

        Nodo<H>* _massimo(Nodo<H> *tmp)
        {
            while(tmp->getRight()!=NULL)
                tmp=tmp->getRight();
            return tmp;
        }

        Nodo<H>* _successore(Nodo<H>* tmp)
        {
            if(tmp->getRight())
                return _minimo(tmp->getRight());
            Nodo<H> *p = tmp->getParent();
            while(p && p->getKey()<tmp->getKey())
                p=p->getParent();
            return p;

        }

        Nodo<H>* _predecessore(Nodo<H>* tmp)
        {
            if(tmp->getLeft())
                return _minimo(tmp->getLeft());
            Nodo<H> *p = tmp->getParent();
            while(p && p->getKey()>tmp->getKey())
                p=p->getParent();
            return p;

        }

        int _altezza(Nodo<H> *tmp, int h)
        {
            if(!tmp) return 0;
            return max(_altezza(tmp->getLeft()),_altezza(tmp->getRight()))+1;
        }

        int max(int a, int b)
        {
            if(a>b) return a;
            return b;
        }

        _canc(Nodo<H> *r,H x)
        {
            //trovo il nodo da cancellare
            Nodo<H> *tmp = _rsearch(r, x);
            if(!tmp) return;
            Nodo<H> *parent = tmp->getParent();
            if(!tmp->getLeft() || !tmp->getRight()) 
            {
                n--; //va fatta solo qui perche' solo qui vi e' una cancellazione effettiva
                //caso 1 e caso 2
                Nodo<H> *figlio = tmp->getRight();
                if(tmp->getLeft()) figlio = tmp->getLeft();
                //figlio punta all'unico figlio presente o a NULL se non vi sono
                if(!parent) root=figlio;
                else
                {
                    if(tmp==parent->getLeft()) parent->setLeft(NULL); //figlio sinistro
                    else parent->setRight(NULL); //figlio destro
                }
                if(figlio)figlio->setParent(parent);
            }
            else //caso3
            {
                Nodo<H> *succ = _successore(tmp);
                tmp->setKey(succ->getKey());
                _canc(tmp->getRight(), succ->getKey())
            }
            return;

        }


    public:
        BST()
        {
            root = NULL;
            n =0;
            current = NULL;
        }

        BST <H>* insert (H x)
        {
            Nodo<H>* node = root;
            Nodo<H>* p = NULL;
            while(node!=NULL)
            {
                p = node;
                if(x > node->getKey()) node = node->getRight();
                else node = node->getLeft();
            }
            Nodo<H>* newn = new Nodo<H>(x);
            n++;
            if(p==NULL) {
                root = newn;
                return this;
            }
            if(x < p->getKey()) p->setLeft(newn);
            else p->setRight(newn);
            newn->setParent(p);
            return this;
        }

        int search(H x) { return (_search(x)!=NULL); }
        H minimo() { return (_minimo(root))->getKey();}
        H massimo() { return (_massimo(root))->getKey();}
        H* successore(H x) 
        {
            Nodo<H> *tmp = _search(x);
            if(!tmp)
            {
                cout << "nodo non presente!" <<endl;
                return NULL;
            }
            Nodo<H> *s = _successore(tmp);
            if(!s)
            {
                cout << "succ non presente!" <<endl;
                return NULL;
            }
            else
                return new H(s->getKey());
        }

        H* predecessore(H x) 
        {
            Nodo<H> *tmp = _search(x);
            if(!tmp)
            {
                cout << "nodo non presente!" <<endl;
                return NULL;
            }
            Nodo<H> *s = _predecessore(tmp);
            if(!s)
            {
                cout << "succ non presente!" <<endl;
                return NULL;
            }
            else
                return new H(s->getKey());
        }

        void _inorder(Nodo<H> *x)
        {
            if(x)
            {
                _inorder(x->getLeft());
                cout<<x->getKey()<<" ";
                _inorder(x->getRight());
            }
        }

        void _preorder(Nodo<H> *x)
        {
            if(x)
            {
                cout<<x->getKey()<<" ";
                _preorder(x->getLeft());
                _peorder(x->getRight());
            }
        }

        void _postorder(Nodo<H> *x)
        {
            if(x)
            {
                _postorder(x->getLeft());
                _postorder(x->getRight());
                cout<<x->getKey()<<" ";
            }
        }

        void inorder()
        {
            _inorder(root);
            cout<<endl;
        }
        void preorder()
        {
            _preorder(root);
            cout<<endl;
        }

        void postorder()
        {
            _postorder(root);
            cout<<endl;
        }

        Nodo<H>* _rsearch(Nodo<H>* tmp, H x)
        {
            if(!tmp) return NULL;
            if(tmp->getKey()==x) return tmp;
            if(x<tmp->getKey()) return _rsearch(tmp->getLeft(),x);
            return _rsearch(tmp->getRight(),x)
        }

        void it_inorder()
        {   
            if(!root)  return;
            Stack<Nodo<H>> *st = new Stack<Nodo<H>>();
            st->push(*root);
            while(!st->isEmpty())
            {
                st->reset();
                Nodo<H> *tmp = st->next();
                if(tmp->getFlag=='0' && tmp->getLeft())
                {
                    st->push(*(tmp->getLeft());
                    tmp->setFlag('1');
                }    
                else
                {
                    cout<<tmp->getKey()<<" ";
                    st->pop();
                    if(tmp->getRight())
                        st->push(*(tmp->getRight());
                }
            }
            cout<<endl;
        }


        void it_preorder()
        {
            if(!root) return;
            Stack<Nodo<H> *st = new Stack<Nodo<H>> ();
            st->push(*root);
            while(!st->isEmpty())
            {
                st->reset();
                Nodo<H> *tmp = st->next();
                cout << tmp->getKey() << " ";
                st->pop();
                if(tmp->getRight()) st->push(*(tmp->getRight()));
                if(tp->getLeft()) st->push(*(tmp->getLeft()));
            }
        }

        void it_preorder()
        {
            if(!root) return;
            Stack<Nodo<H> *st = new Stack<Nodo<H>> ();
            st->push(*root);
            while(!st->isEmpty())
            {
                st->reset();
                Nodo<H> *tmp = st->next();
                if(tmp->getFlag()==0)
                {
                    if(tmp->getRight()) st->push(*(tmp->getRight()));
                    if(tp->getLeft()) st->push(*(tmp->getLeft()));
                    tmp->setFlag(1);
                }
                else
                {
                    st->pop();
                    cout << tmp->getKey() << " ";
                }
            }
        }


        void reset(){ current = _minimo(root); }

        H* next(){
            if(current){
                H* tmp = new H(current->getKey());
                current = _successore(current);
                return tmp;
            } 
            else return NULL;
        }

        int has_next(){
            return (current!=NULL)
        }

        int altezza()
        {
            return _altezza(root, 0);
        }

        int prof(H x)
        {
            Nodo<H> *tmp = _search(x);
            if(!tmp) return -1;
            int p = 0;
            while(tmp != root)
            {
                tmp = tmp->getParent();
                p++;
            }
            return p;
        }

        /* //cancella un nodo ricevendo una chiave
        void canc(H x)
        {
            //trovo il nodo da cancellare
            Nodo<H> *tmp = _search(x);
            if(!tmp) return;
            Nodo<H> *parent = tmp->getParent();
            n--;
            if(!tmp->getLeft() && !tmp->getRight()) //caso 1
            {
                if(!parent)
                {
                    root=NULL;
                }
                else
                {
                    if(tmp==parent->getLeft()) parent->setLeft(NULL); //figlio sinistro
                    else parent->setRight(NULL); //figlio destro
                }   
                n--;
                return;
            }
            if(!(tmp->getLeft() && tmp->getRight())) //caso 2, qui siamo sicuri che almeno un figlio c'e'
            {
                Nodo<H> *figlio = tmp->getRight();
                if(!parent)
                    root=figlio;
                else{
                    if(tmp->getLeft()) figlio = tmp->getLeft();
                    if(tmp==parent->getLeft()) parent->setLeft(figlio);
                    else parent->setRight(figlio);
                    
                }
                figlio->setParent(parent);
                n--;
                return;
            }
            else //caso 3: ha due figli
            {

            }

        } */


        void canc(H x)
        {
            _canc(root, x);
        }


};

template<> Nodo<int> Stack<Nodo<int>>::EMPTY = Nodo<int> 0;

int main()
{
    BST<int>* t = new BST<int>();
    t->insert(12)->insert(1)->insert(17)->insert(6)->insert(14)->insert(21);
    t->insert(5)->insert(10)->insert(23)->insert(7)->insert(11);

}



