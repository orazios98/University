#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


template <class H> class Coda
{
private:
    int n,len,tail,head;
    H **v;
public:
    Coda(int len)
    {
        this->len=len;
        n=0;
        tail = head = 0;
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
        H t=*v[head];
        head++;
        n--;
        return t;
    }

    void printa(ofstream& f)
    {
        for(int i=head;i<n+head;i++)
        {
            f<<*v[i]<<" ";
        }
        f<<endl;
    }
};

int main()
{
    ifstream inf("input.txt");
    ofstream of("output.txt");
    string tipo;
    int n;
    string l;
    while(getline(inf,l))
    {
        istringstream iss(l);
        iss>>tipo;
        iss>>n;
        if(tipo=="int")
        {
            Coda<int> *cd=new Coda<int>(n);
            string op;
            for(int i=0;i<n;i++)
            {
                iss>>op;
                if(op[0]=='i')
                {
                    string vt="";
                    for(int i=1;i<op.length();i++)
                    {
                        vt+=op[i];
                    }
                    int in=stoi(vt);
                    cd->enqueue(in);
                }
                if(op=="dequeue")
                {
                    cd->dequeue();
                }
            }
            cd->printa(of);
        }
        //fine int
        //start double
        if(tipo=="double")
        {
            Coda<double> *cd=new Coda<double>(n);
            string op;
            for(int i=0;i<n;i++)
            {
                iss>>op;
                if(op[0]=='i')
                {
                    string vt="";
                    for(int i=1;i<op.length();i++)
                    {
                        vt+=op[i];
                    }
                    double in=stod(vt);
                    cd->enqueue(in);
                }
                if(op=="dequeue")
                {
                    cd->dequeue();
                }
            }
            cd->printa(of);
        }
        //end double
        //start bool
        if(tipo=="bool")
        {
            Coda<bool> *cd=new Coda<bool>(n);
            string op;
            for(int i=0;i<n;i++)
            {
                iss>>op;
                if(op[0]=='i')
                {
                    char c=op[1];
                    bool b;
                    if(c=='0')
                        b=false;
                    else
                        b=true;
                    cd->enqueue(b);
                }
                if(op=="dequeue")
                {
                    cd->dequeue();
                }
            }
            cd->printa(of);
        }
        //fine bool
        //start char
        if(tipo=="char")
        {
            Coda<char> *cd=new Coda<char>(n);
            string op;
            for(int i=0;i<n;i++)
            {
                iss>>op;
                if(op[0]=='i')
                {
                    cd->enqueue(op[1]);
                }
                if(op=="dequeue")
                {
                    cd->dequeue();
                }
            }
            cd->printa(of);
        }


    }
}
