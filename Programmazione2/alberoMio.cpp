#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

template <class F> class Nodo
{
private:
    F* key;
    Nodo<F> *left,*right,*parent;
    char flag;
public:
    Nodo(F key)
    {
        this->key=new F(key);
        left = right = parent = NULL;
        flag = 0;
    }
    void setKey(F key) { this->key = new F(key); }
    void setLeft(Nodo<F>* left) { this->left = left;}
    void setRight(Nodo<F>* right) {this->right = right;}
    void setParent(Nodo<F>* parent) {this->parent=parent;}
    void setFlag(char flag) {this->flag=flag;}

    F getKey() {return *key;}
    char getFlag() {return flag;}
    Nodo<F>* getParent() {return parent;}
    Nodo<F>* getLeft() {return left;}
    Nodo<F>* getRight() {return right;}
};

template <class H> class BST
{
private:
    Nodo<H> *root;
    int n;

    void _inorder(Nodo<H> *x, ofstream& f)
    {
        if(x)
        {
            _inorder(x->getLeft(),f);
            f<<x->getKey()<<" ";
            _inorder(x->getRight(),f);
        }
    }

    void _postorder(Nodo<H> *x, ofstream& f)
    {
        if(x)
        {
            _postorder(x->getLeft(),f);
            _postorder(x->getRight(),f);
            f<<x->getKey()<<" ";
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

    v

public:
    BST()
    {
        root=NULL;
        n=0;
    }

    BST<H>* insert(H x)
    {
        Nodo<H> *node = root;
        Nodo<H> *p = NULL;
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
            root = newn;
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

    void postorder(ofstream& f)
    {
        _postorder(root, f);
        f<<endl;
    }

    void preorder(ofstream& f)
    {
        _preorder(root, f);
        f<<endl;

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
