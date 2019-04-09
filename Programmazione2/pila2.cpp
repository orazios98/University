#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


template <class G> class Pila
{
private:
    int n, len, head;
    G **v;
public:
    Pila(int t)
    {
        n=0;
        head=0;
        len=t;
        v=new G*[len];
    }

    Pila<G>* Push(G x)
    {
        v[head]=new G(x);
        head++;
        n++;
        return this;
    }

    G Pop()
    {
        if(n==0) return NULL;
        head--;
        n--;
        return *v[head];
    }

    int getN()
    {
        return n;
    }

    G getG(int i)
    {
        return *v[i];
    }

};

int main()
{
    ifstream inf("input.txt");
    ofstream of("output.txt");
    string l;
    string tipo;
    int n;
    while(getline(inf,l))
    {
        istringstream iss(l);
        iss>>tipo;
        iss>>n;
        if(tipo=="int")
        {
            Pila<int> *cd=new Pila<int>(n);
            string tmp;
            for(int i=0;i<n;i++)
            {
                iss>>tmp;
                if(tmp=="pop")
                    cd->Pop();
                if(tmp[0]=='i')
                {
                    string ins="";
                    for(int i=1;i<tmp.length();i++)
                    {
                        ins+=tmp[i];
                    }
                    int i=stoi(ins);
                    cd->Push(i);
                }

            }
            int dim=cd->getN();
            for(int i=dim-1;i>=0;i--)
            {
                of<<cd->getG(i)<<" ";
            }
            of<<endl;
        }
        //fine tipo int
        //start tipo double
        if(tipo=="double")
        {
            Pila<double> *cd=new Pila<double>(n);
            string tmp;
            for(int i=0;i<n;i++)
            {
                iss>>tmp;
                if(tmp=="pop")
                    cd->Pop();
                if(tmp[0]=='i')
                {
                    string ins="";
                    for(int i=1;i<tmp.length();i++)
                    {
                        ins+=tmp[i];
                    }
                    double i=stod(ins);
                    cd->Push(i);
                }

            }
            int dim=cd->getN();
            for(int i=dim-1;i>=0;i--)
            {
                of<<cd->getG(i)<<" ";
            }
            of<<endl;
        }
        //fine tipo double
        //inizio tipo char
        if(tipo=="char")
        {
            Pila<char> *cd=new Pila<char>(n);
            string tmp;
            for(int i=0;i<n;i++)
            {
                iss>>tmp;
                if(tmp=="pop")
                    cd->Pop();
                if(tmp[0]=='i')
                {
                    cd->Push(tmp[1]);
                }

            }
            int dim=cd->getN();
            for(int i=dim-1;i>=0;i--)
            {
                of<<cd->getG(i)<<" ";
            }
            of<<endl;
        }
        //fine tipo char
        //start tipo bool
        if(tipo=="bool")
        {
            Pila<bool> *cd=new Pila<bool>(n);
            string tmp;
            for(int i=0;i<n;i++)
            {
                iss>>tmp;
                if(tmp=="pop")
                    cd->Pop();
                if(tmp[0]=='i')
                {
                    char c=tmp[1];
                    bool b;
                    if(c=='0')
                        b=0;
                    else
                        b=1;
                    cd->Push(b);
                }

            }
            int dim=cd->getN();
            for(int i=dim-1;i>=0;i--)
            {
                of<<cd->getG(i)<<" ";
            }
            of<<endl;
        }
    }
}
