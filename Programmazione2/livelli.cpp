#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

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

    Nodo<H>* _minimo(Nodo<H>* tmp)
    {
        while(tmp->getLeft()!=NULL)
            tmp=tmp->getLeft();
        return tmp;
    }

    Nodo<H>* _successore(Nodo<H>* tmp)
    {
        if(tmp->getRight())
            return _minimo(tmp->getRight());
        Nodo<H>* p=tmp->getParent();
        while(p!=NULL && p->getKey()<tmp->getKey())
            p=p->getParent();
        return p;
    }

    void _canc(Nodo<H>* r, H x)
    {
        Nodo<H>* tmp=_rsearch(r, x);
        if(!tmp) return;
        if(!tmp->getLeft() || !tmp->getRight())
        {
            n--;
            Nodo<H>* figlio=tmp->getLeft();
            if(tmp->getRight()) figlio=tmp->getRight();
            Nodo<H> *parent=tmp->getParent();
            if(!parent)
                root=figlio;
            else
            {
                if(tmp==parent->getLeft()) parent->setLeft(figlio);
                else parent->setRight(figlio);
            }
            if(figlio) figlio->setParent(parent);
        }
        else
        {
            Nodo<H> *succ=_successore(tmp);
            tmp->setKey(succ->getKey());
            _canc(tmp->getRight(),succ->getKey());
        }
        return;
    }

    Nodo<H>* _rsearch(Nodo<H>* tmp, H x)
    {
        if(!tmp) return NULL;
        if(tmp->getKey()==x) return tmp;
        if(tmp->getKey()<x) return _rsearch(tmp->getRight(),x);
        return _rsearch(tmp->getLeft(),x);
    }


public:
    BST()
    {
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
        Nodo<H> *newn=new Nodo<H>(x);
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

    void canc(H x)
    {
        _canc(root, x);
        return;
    }
};


int main()
{
    ifstream inf("input.txt");
    ofstream of("output.txt");
    string l;
    while(getline(inf,l))
    {
        string tipo;
        int n,m;
        istringstream iss(l);
        iss>>tipo>>n>>m;
        if(tipo=="int")
        {
            BST<int> *al=new BST<int>();
            for(int i=0;i<n;i++)
            {
                string t;
                iss>>t;
                if(t[0]=='i')
                {
                    t=t.substr(4);
                    int tm=stoi(t);
                    al->insert(tm);
                }
                if(t[0]=='c')
                {
                    t=t.substr(5);
                    int tm=stoi(t);
                    al->canc(tm);
                }
            }
            for(int i=0;i<m;i++)
            {
                int t;
                iss>>t;
                of<<al->prof(t)<<" ";

            }
            of<<endl;

        }
        if(tipo=="double")
        {
            BST<double> *al=new BST<double>();
            for(int i=0;i<n;i++)
            {
                string t;
                iss>>t;
                if(t[0]=='i')
                {
                    t=t.substr(4);
                    double tm=stod(t);
                    al->insert(tm);
                }
                if(t[0]=='c')
                {
                    t=t.substr(5);
                    double tm=stod(t);
                    al->canc(tm);
                }
            }
            for(int i=0;i<m;i++)
            {
                double t;
                iss>>t;
                of<<al->prof(t)<<" ";

            }
            of<<endl;
        }

    }
}
