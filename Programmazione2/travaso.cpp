#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;


template <class F> class Coda
{
private:
    int n,len,head,tail;
    F **v;
public:
    Coda(int t)
    {
        n=0;
        len=t;
        head=tail=0;
        v=new F*[len];
    }

    Coda<F>* enqueue(F x)
    {
        v[tail]=new F(x);
        tail++;
        n++;
        return this;
    }

    F dequeue()
    {
        if(n==0) return NULL;
        F tmp=*v[head];
        head++;
        n--;
        return tmp;
    }

    void stampa(ofstream& f)
    {
        cout<<head<<" "<<tail<<endl;
        for(int i=head;i<tail;i++)
        {
            f<<*v[i]<<" ";
        }
        f<<endl;
    }
};

template <class H> class Stack
{
private:
    int n,len,head;
    H** v;
public:
    Stack(int t)
    {
        n=head=0;
        len=t;
        v=new H*[len];
    }

    Stack<H>* Push(H x)
    {
        v[head]=new H(x);
        head++;
        n++;
        return this;
    }

    H Pop()
    {
        if(n==0) return NULL;
        head--;
        n--;
        return *v[head];
    }

    void stampa(ofstream& f)
    {
        for(int i=head-1;i>=0;i--)
        {
            f<<*v[i]<<" ";
        }
        f<<endl;
    }

    void travasa(Coda<H> *c)
    {
        H x=Pop();
        while(x)
        {
            c->enqueue(x);
            x=Pop();
        }
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
        int n;
        istringstream iss(l);
        iss>>tipo>>n;
        if(tipo=="int")
        {
            Stack<int> *st=new Stack<int>(n);
            Coda<int> *cd=new Coda<int>(n);
            for(int i=0;i<n;i++)
            {
                string t;
                iss>>t;
                if(t[0]=='e')
                {
                    t=t.substr(2);
                    int tmp=stoi(t);
                    cd->enqueue(tmp);
                }
                if(t[0]=='p')
                {
                    if(t[1]==':')
                    {
                        t=t.substr(2);
                        int tmp=stoi(t);
                        st->Push(tmp);
                    }
                    if(t[1]=='o')
                    {
                        st->Pop();
                    }
                }
                if(t[0]=='d')
                {
                    cd->dequeue();
                }
                if(t[0]=='t')
                {
                    st->travasa(cd);
                }
            }
            cd->stampa(of);
        }
        if(tipo=="double")
        {
            Stack<double> *st=new Stack<double>(n);
            Coda<double> *cd=new Coda<double>(n);
            for(int i=0;i<n;i++)
            {
                string t;
                iss>>t;
                if(t[0]=='e')
                {
                    t=t.substr(2);
                    double tmp=stod(t);
                    cd->enqueue(tmp);
                }
                if(t[0]=='p')
                {
                    if(t[1]==':')
                    {
                        t=t.substr(2);
                        double tmp=stod(t);
                        st->Push(tmp);
                    }
                    if(t[1]=='o')
                    {
                        st->Pop();
                    }
                }
                if(t[0]=='d')
                {
                    cd->dequeue();
                }
                if(t[0]=='t')
                {
                    st->travasa(cd);
                }
            }
            cd->stampa(of);
        }
        if(tipo=="bool")
        {
            Stack<bool> *st=new Stack<bool>(n);
            Coda<bool> *cd=new Coda<bool>(n);
            for(int i=0;i<n;i++)
            {
                string t;
                iss>>t;
                if(t[0]=='e')
                {
                    char c=t[2];
                    bool b;
                    if(c=='0')
                        b=false;
                    else
                        b=true;
                    cd->enqueue(b);
                }
                if(t[0]=='p')
                {
                    if(t[1]==':')
                    {
                        char c=t[2];
                        bool b;
                        if(c=='0')
                            b=false;
                        else
                            b=true;
                        st->Push(b);
                    }
                    if(t[1]=='o')
                    {
                        st->Pop();
                    }
                }
                if(t[0]=='d')
                {
                    cd->dequeue();
                }
                if(t[0]=='t')
                {
                    st->travasa(cd);
                }
            }
            cd->stampa(of);
        }
        if(tipo=="char")
        {
            Stack<char> *st=new Stack<char>(n);
            Coda<char> *cd=new Coda<char>(n);
            for(int i=0;i<n;i++)
            {
                string t;
                iss>>t;
                if(t[0]=='e')
                {
                    char c=t[2];
                    cd->enqueue(c);
                }
                if(t[0]=='p')
                {
                    if(t[1]==':')
                    {
                        char c=t[2];
                        st->Push(c);
                    }
                    if(t[1]=='o')
                    {
                        st->Pop();
                    }
                }
                if(t[0]=='d')
                {
                    cd->dequeue();
                }
                if(t[0]=='t')
                {
                    st->travasa(cd);
                }
            }
            cd->stampa(of);
        }
    }
}
