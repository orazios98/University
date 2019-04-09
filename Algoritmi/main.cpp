#include <iostream>
#include <math.h>

using namespace std;


//Implementazione dello heap con interi

const int N=6;

class Heap
{
    int *A;
    int length;
    int heapsize;
    int left(int i) {return (2*i)+1; }
    int right(int i) {return (2*i)+2;}
    int parent(int i) {return floor((i-1)/2);}
    void swap(int i, int j);
    void heapify(int i);

public:
    Heap (int size);
    void insert(int x); //caricare l'array;
    void buildHeap();
    void print(int y);
    int size() {return length;}
    int heap_size() {return heapsize;}
};

int main()
{
    Heap B=Heap(N);
    int x;
    for(int i=0; i<N; i++)
    {
        cin>>x;
        B.insert(x);
    }
    B.print(B.size());
    B.buildHeap();
    B.print(B.size());
    return 0;
}


Heap::Heap(int size)
{
    A = new int [size];
    length = 0;
    heapsize = 0;
}

void Heap::swap(int i,int j)
{
    int tmp=A[i];
    A[i]=A[j];
    A[j]=tmp;
}

void Heap::heapify(int i)
{
    int l=left(i);
    int r=right(i);
    int v=i; //contiene il valore piu grande
    if(l<heapsize && A[l]>A[v]) v=l;
    if(r<heapsize && A[r]>A[v]) v=r;
    if(v!=i)
    {
        swap(i,v);
        heapify(v);
    }
}

void Heap::buildHeap()
{
    heapsize=length;
    for(int i=floor((heapsize-1)/2); i>=0; i--)
        heapify(i);
}

void Heap::insert(int x)
{
    if(length<N)
    {
        A[length]=x;
        length++;
    }
}

void Heap::print(int y)
{
    cout << "Heap Costruito: " << endl;
    for(int i=0; i<y; i++)
        cout<< A[i] << "\t";
    cout<<endl;
}
