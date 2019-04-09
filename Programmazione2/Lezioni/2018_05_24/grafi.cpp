#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
#include "QueueStack.cpp"
#include "LinkedList.cpp"
using namespace std;
#define MAXLEN 100


template <class H> class Vector
{
    private:
        int n, len;
        int current;
        H** v;
    public:
        Vector()
        {
            v = new H*[MAXLEN];
            len = MAXLEN;
            n = 0;
            current = 0;
        }

        Vector <H>* insert(H x)
        {
            if(n==len) return this;
            v[n] = new H(x);
            n++;
        }

        int size() {return n;}

        H findKey(int index) { return *v[index]; }

        int findIndex (H x)
        {
            for(int i=0;i<n;i++)
                if(x==*v[i])
                    return i;
            return -1;
        }

        void reset()
        {
            current = 0;
        }

        H* next()
        {
            if(!hasNext()) return NULL;
            H* tmp = v[current];
            current ++;
            return tmp;
        }

        int hasNext() { return current>=n?0:1; }
};

template <class H> class Graph
{
    private:
        int m,len;
        Vector<H> *k;
        int** adj;

    public:
        Graph()
        {
            len=MAXLEN;
            k = new Vector<H>(len);
            adj = new int* [len];
            for(int i=0;i<len;i++)
            {
                adj[i] = new int[len];
                for(int j=0;j<len;j++){ adj[i][j] = 0;}
            }
        }

        Graph <H>* insertNode(H x)
        {
            k->insert(x);
            return this;
        }

        Graph<H>* insertEdge(H x,H y)
        {
            //i : chiave di x
            //j : chiave di y
            int i=k->findIndex(x);
            int j=k->findIndex(y);
            if(i<0 || j<0) return this;
            adj[i][j] = 1;
            //nel caso di un grafo non orientato
            adj[j][i] = 1;
            m++;
            return this;
        }

        void reset() {k->reset(); }
        H* next() {return k->next();}
        int hasNext() {return k->hasNext();}

        void printAdj(H x)
        {
            int i = k->findIndex(x);
            if(i<0) return;
            cout << "{ ";
            for(int j=0;j<k->size();j++)
            {
                if(adj[i][j]) cout << k->findKey(j) << " ";
            }
            cout << " }";
        }

        int hasEdge(H x, H y)
        {
            int i = k->findIndex(x);
            int j = k->findIndex(y);
            if(i<0||j<0) return 0;
            return adj[i][j];
        }

        int hasNode(H x)
        {
            int i = k->findIndex(x);
            return (i>=0);
        }
};

int main()
{
    Graph<char> *g = new Graph<char> ();
    return 0;

}
