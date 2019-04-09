#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

template <class H> class Coda
{
private:
    int n,len, tail, head;
    H **v;

public:
    Coda(int t)
    {
        n=0;
        len=t;
        tail=head=0;
        v=new H*[len];
    }

    Coda<H>* enqueue(H x)
    {
        v[tail]=new H(x);
        tail++;
        n++;
        return this;
    }

    H dequeue()
    {
        H x=*v[head];
        head++;
        n--;
        return x;
    }
};

template <class H> class Pila()
{
private:
    int n,len,head;
    H **v;
public:
    Pila(int t)
    {
        n=0;
        len=t;
        head=0;
        v=new H*[len];
    }

    Pila<H>* push(H x)
    {
        v[head]=new H x;
        head++;
        n++;
        return this;
    }

    H pop()
    {
        head--;
        n--;
        return *v[head];
    }
};

template <class H> class Nodo
{
private:
    H *key;
    Nodo<H> *parent,*right,*left;
public:
    Nodo(H x)
    {
        key=new H(x);
        parent=right=left=NULL;
    }

    void setKey(N x) {this->key=new N(x);}
    void setRight(Nodo<N> *right) {this->right=right;}
    void setLeft(Nodo<N> *left) {this->left=left;}
    void setParent(Nodo<N> *parent) {this->parent=parent;}

    N getKey() { return *key; }
    Nodo<N>* getRight() {return right;}
    Nodo<N>* getLeft() {return left;}
    Nodo<N>* getParent() {return parent;}
};

template <class H> class BST
{
private:
    int n;
    Nodo<H>* root;


    Nodo<H>* _minimo(Nodo<H>* tmp)
    {
        while(tmp!=NULL)
        {
            tmp=tmp->getLeft();
        }
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

    Nodo<H>* _rsearch(Nodo<H>* tmp, H x)
    {
        if(!tmp) return NULL;
        if(x==tmp->getKey()) return tmp;
        if(x>tmp->getKey()) return _rsearch(tmp->getRight(),x);
        return _rsearch(tmp->getLeft(),x);
    }

    void _canc(Nodo<H>* r, H x)
    {
        Nodo<H>* tmp=_rsearch(r,x);
        if(!r) return;
        Nodo<H>* p=tmp->getParent();
        if(!tmp->getLeft()||!tmp->getRight())
        {
            n--;
            Nodo<H>* figlio=tmp->getLeft();
            if(tmp->getRight()) figlio=tmp->getRight();
            if(!p)
            {
                root=figlio;
            }
            else
            {
                if(tmp==p->getRight()) p->setRight(figlio);
                else p->setLeft(figlio);
            }
            if(figlio) figlio->setParent(p);
        }
        else
        {
            Noddo<H>*succ=_successore(tmp);
            tmp->setKey(succ->getKey());
            _canc(tmp->getRight(),succ->getKey());
        }
    }

public:
    BST()
    {
        n=0;
        root=NULL;
    }

    BST<H>>* insert(H x)
    {
        Nodo<H>* node=root;
        Nodo<H>* p=NULL;
        while(node!=NULL)
        {
            p=node;
            if(x>node->getKey())
                node=node->getRight();
            else
                node=node->getLeft();
            Nodo<H>* newn=new Nodo<H>(x);
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
    }

};

