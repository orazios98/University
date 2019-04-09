#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

class Set
{
    private:
        int n;
        int len;
        int *v;
        int current;


        int _search(int x) //funzione molto "tecnica" quindi la rendiamo "di servizio"
        {
            for(int i=0; i<n; i++)
                if(v[i]==x) return i;
            return -1;
        }

        void duplica()
        {
            int *newv = new int[2*len];
            for(int i=0; i<n; i++) newv[i] = v[i];
            len = 2*len;
            v = newv;
        }
    
    public:
        Set()
        {
            n=0;
            len=1;
            v = new int[len];
            current=0;
        }

        int size() { return n; }

        Set* insert(int x) //rito
        {
            if(n==len)
                duplica();
            v[n]=x;
            n++;
            return this;
        }

        int search(int x) //funzione piu' semplice per l'utente
        {
            if(_search(x)>=0) return 1;
            return 0;
        }

        void cancFirst(int x)
        {
            int pos = _search(x);
            if(pos>=0)
            {
                v[pos] = v[--n];
            }
        }

        void cancAll(int x)
        {
            int pos = _search(x);
            while(pos>=0)
            {
                v[pos] = v[--n];
                pos = _search(x);
            }
        }

        void print()
        {
            cout<<"{";
            for(int i=0;i<n-1; i++)
            {
                cout << v[i] << " ";
            }
            if(n>0)
                cout << v[n-1];
            cout << "}";
        }

        void reset() { current = 0;}
        int *next() 
        {
            if(current>=n)
                return NULL;
            int *tmp = &v[current];
            current++;
            return tmp;
        }
        int has_next() {return (current<n);}
        
};



int main()
{
    Set *s = new Set();

    // s->insert(4);
    // s->insert(2);
    // s->insert(7);
    // s->print();

    //voglio implementare l'inserimento a cascata

    s->print();
    s->insert(4)->insert(2)->insert(7)->insert(2)->insert(2)->insert(2)->print();
    s->cancFirst(2);
    s->print();
    s->cancAll(2);
    s->print();
    s->reset();
    cout<<endl;
    while(s->has_next())
    {
        int *t = s->next();
        cout << *t << " ";
    }
    cout<<endl;
    for(s->reset();s->has_next();)
    {
        int *t = s->next();
        cout << *t << " ";    
    }
    cout<<endl;
    return 0;
}