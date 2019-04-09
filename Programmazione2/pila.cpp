#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

template <class G> class Pila
{
private:
    int n, head, len, current;
    G **v;
public:
    Pila(int x)
    {
        n=0;
        len=x;
        head=0;
        v=new G*[len];
    }

    Pila<G>* Push(G x)
    {
        v[head]=new G(x);
        head++;
        n++;
        return this;
    }

    G* Pop()
    {
        G x=*(v[head-1]);
        head--;
        n--;
        return x;
    }

    void reset()
    {
        current=head-1;
    }

    G next()
    {
        if(current<0) return NULL;
        G *t=v[current];
        current--;
        return *(t);
    }

    int hasNext(){return current>=0;}

    G getG(int i)
    {
        return *v[i];
    }

    void print()
    {
        for(int i=0;i<n;i++)
        {
            cout<<*(v[i])<<" ";
        }
        cout<<endl;
    }

};

int main()
{
    ifstream inf("input.txt");
    ofstream of("output.txt");
    string l;
    int n;
    string tipo;
    while(getline(inf,l))
    {
        istringstream iss(l);
        iss>>tipo;
        iss>>n;
        cout<<tipo<<" "<<n;
        if(tipo=="int")
        {
            Pila<int> *c=new Pila<int>(n);
            int t;
            for(int i=0;i<n;i++)
            {
                iss>>t;
                c->Push(t);
            }
            for(int i=n-1;i>=0;i--)
            {
                of<<c->getG(i)<<" ";
            }
            of<<endl;

        }
        if(tipo=="bool")
        {
            Pila<bool> *c=new Pila<bool>(n);
            bool t;
            for(int i=0;i<n;i++)
            {
                iss>>t;
                c->Push(t);
            }
            for(int i=n-1;i>=0;i--)
            {
                of<<c->getG(i)<<" ";
            }
            of<<endl;
        }
        if(tipo=="double")
        {
            Pila<double> *c=new Pila<double>(n);
            double t;
            for(int i=0;i<n;i++)
            {
                iss>>t;
                c->Push(t);
            }
            for(int i=n-1;i>=0;i--)
            {
                of<<c->getG(i)<<" ";
            }
            of<<endl;
        }
        if(tipo=="char")
        {
            Pila<char> *c=new Pila<char>(n);
            char t;
            for(int i=0;i<n;i++)
            {
                iss>>t;
                c->Push(t);
            }
            for(int i=n-1;i>=0;i--)
            {
                of<<c->getG(i)<<" ";
            }
            of<<endl;
        }

    }
}
