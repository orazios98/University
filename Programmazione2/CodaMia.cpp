#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

template <class G> class Coda
{
private:
    int len, n, tail, head;
    G **v;
public:
    Coda(int len)
    {
        n=0;
        this->len = len;
        v=new G*[len];
        tail = head = 0;
    }

    Coda<G>* enqueue(G x)
    {
        if(n==len) return this;
        v[tail] = new G(x);
        tail++;
        n++;
        return this;
    }

    G dequeue()
    {
        if(n==0) return -1;
        G r = *v[head];
        head++;
        n--;
        return r;
    }

};

int main()
{
    ifstream inf("input.txt");
    ofstream of("output.txt");
    string l;
    int n;
    string tipo;
    while(getline(inf, l))
    {
        istringstream iss(l);
        iss>>tipo>>n;
        if(tipo=="int")
        {
            Coda<int> *q=new Coda<int>(n);
            int t;
            for(int i=0;i<n;i++)
            {
                iss>>t;
                q->enqueue(t);
            }
            for(int i=0;i<n;i++)
            {
                t=q->dequeue();
                of<<t<<" ";
            }
            of<<endl;
        }
        if(tipo=="double")
        {
            Coda<double> *q=new Coda<double>(n);
            double t;
            for(int i=0;i<n;i++)
            {
                iss>>t;
                q->enqueue(t);
            }
            for(int i=0;i<n;i++)
            {
                t=q->dequeue();
                of<<t<<" ";
            }
            of<<endl;
        }
        if(tipo=="bool")
        {
            Coda<bool> *q=new Coda<bool>(n);
            bool t;
            for(int i=0;i<n;i++)
            {
                iss>>t;
                q->enqueue(t);
            }
            for(int i=0;i<n;i++)
            {
                t=q->dequeue();
                of<<t<<" ";
            }
            of<<endl;
        }
        if(tipo=="char")
        {
            Coda<char> *q=new Coda<char>(n);
            char t;
            for(int i=0;i<n;i++)
            {
                iss>>t;
                q->enqueue(t);
            }
            for(int i=0;i<n;i++)
            {
                t=q->dequeue();
                of<<t<<" ";
            }
            of<<endl;
        }
    }

    return 0;
}
