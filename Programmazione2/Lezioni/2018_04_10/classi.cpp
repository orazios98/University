#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

class Contatore
{
    private: //e' di default cosi'
        int val;
    
    public:
        Contatore();
        Contatore(int); //overloading del costruttore

        void inc(); //incrementa il contatore
        void dec(); //decrementa il contatore
        int isZero(); 
        int isLessThan(int);
        int isEqual(int);
        int get();
};

Contatore::Contatore() { val = 0; }
Contatore::Contatore(int val) {this->val = val;}
void Contatore::inc() {val++;}
void Contatore::dec() 
{
    if(val>0)
    val--;
}
int Contatore::isZero() { return(!val);}
int Contatore::isLessThan(int x) { return (val<x);}
int Contatore::isEqual(int x) { return (val==x);}
int Contatore::get() {return val;}

int main()
{
    // Contatore cont(6);
    // cont.inc();
    // cont.inc();
    // cout<< cont.get()<<endl;
    
    // Contatore *p=new Contatore(0);
    // p->inc();
    // p->inc();
    // cout<< p->get()<<endl;
    // int v[]={2,6,8,1,4,9,23,5};
    // int n=8;

    // for(Contatore c; c.isLessThan(n); c.inc())
    // {
    //     cout<<v[c.get()]<<" ";
    // }
    // cout<<endl;

    // for(Contatore c(n); !c.isZero(); c.dec())
    // {
    //     cout<<v[c.get()-1]<<" ";
    // }

    return 0;
}