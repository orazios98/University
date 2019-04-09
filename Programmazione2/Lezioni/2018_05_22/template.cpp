#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

template <class F> class Nodo
{
    private:
        F* chiave;

    public:
        Nodo(F x) { this->chiave=new F(x); }
        F* getKey() {return chiave;}
        void setKey(F x) {this->chiave = new F(x);}
};


int main()
{
    Nodo<int> *n = new Nodo<int>(5);
    cout <<*(n->getKey()) << endl;
    Nodo<float> *f = new Nodo<float> (30.4);
    cout <<*(f->getKey()) << endl;
    return 0;
}