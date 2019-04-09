#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

template <class F> class Nodo
{
private:
    F *key;
    Nodo<F> *parent,*right,*left;
    int mol;
public:
    Nodo(F x)
    {
        key=new F(x);
        parent = right = left = NULL;
        mol=1;
    }

    void setKey(F x) { key= new F(x); }
    void setParent(Nodo<H>* x) { parent=x; }
    void setLeft(Nodo<H>* x) {left=x;}
    void setRight(Nodo<H>* x) {right=x;}
    void increment() {mol++;}
    void decrement() {mol--;}


    F getKey() { return *key;}
    Nodo<H>* getParent() { return parent; }
    Nodo<H>* getLeft() { return left; }
    Nodo<H>* getRight() { return right; }
    int getMol() { return mol; }
};


template <class H> class BST
{
private:
    int n;
    Nodo<H>* root;

    Nodo<H>* _minimo(Nodo<H>* tmp)
    {
        while(tmp->getLeft()!=NULL)
        {
            tmp=tmp->getLeft();
            return tmp;
        }
    }

    Nodo<H>* _successore(Nodo<H>* tmp)
    {
        if(tmp->getRight())
            return _minimo(tmp->getRight());
        Nodo p=tmp->getParent();
        while(p!=NULL && p->getKey()<tmp->getKey())
        {
            p=p->getParent();
        }
        return p;
    }

    Nodo<H>* _rsearch(Nodo<H>* tmp, H x)
    {
        if(!tmp) return NULL;
        if(x==tmp->getKey())
            return tmp;
        if(x>tmp->getKey())
            return _rsearch(tmp->getRight(),x);
        return _rsearch(tmp->getLeft(),x);
    }

    int getMol() { return getMol();}

    void _canc(Nodo<H>* tmp, H x)
    {
        Nodo<H>* tmp=_rsearch(root,x);
        if(!tmp) return;
        if(tmp->getMol()>1)
        {
            tmp->decrement();
            return;
        }
        if(!tmp->getLeft !! !tmp->getRight())
        {
            Node<H>* figlio=tmp->getLeft();
            if(tmp->getRight()) figlio=tmp->getRight();
            Nodo<H>* parent=tmp->getParent();
            if(!parent) root=figlio;
            else
            {
                if(tmp==parent->getLeft()) parent->setLeft(figlio);
                else parent->setRight(figlio);
            }
            if(figlio) figlio->setParent(parent);
        }
        else
        {
            Nodo<H>* succ=_successore(tmp);
            tmp->setKey(succ->getKey());
            _canc(tmp->getRight(),succ->getKey());
        }
        return;
    }
    void increment() {increment();}



public:
    BST()
    {
        n=0;
        root=NULL;
    }

    BST<H>* insert(H x)
    {
        Nodo<H>* r=_rsearch(root,x);
        if(!r)
        {
            Nodo<H>* node=root;
            Nodo<H>* p=NULL;
            while(p!=NULL)
            {
                p=node;
                if(x>node->getKey())
                    node=node->getRight();
                else
                    node=node->getLeft();
            }
            Nodo<H>* newn=new Nodo<H>(x);
            n++;
            if(!p)
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
        else
            r->increment();
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

    }
}
