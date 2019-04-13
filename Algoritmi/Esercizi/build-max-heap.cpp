#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

template <class H> class MaxHeap
{
    private:
        H **A;
        int heapsize;
        int len;
        int left(int i){return i<<1;}
        int right(int i){return (i<<1)|1;}
        int parent(int i) {return i>>1;}

        void swap(int i, int j)
        {
            H* tmp=A[i];
            A[i]=A[j];
            A[j]=tmp;
        }

        void heapify(int i)
        {
            if(i>heapsize) return;
            int l=left(i);
            int r=right(i);
            int max=i;
            if(l<=heapsize && *A[l]>*A[max]) max=l;
            if(r<=heapsize && *A[r]>*A[max]) max=r;
            if(max==i) return;
            swap(i, max);
            heapify(max);
        }

    public:

        MaxHeap(int size)
        {
            A=new H*[size];
            heapsize=0;
            len=size;
        }

        H* extractMax()
        {
            if(heapsize==0) return this;
            swap(1,heapsize);
            heapsize--;
            heapify(1);
            return A[heapsize+1];
        }

        MaxHeap<H>* enqueue(int x)
        {
            heapsize++;
            A[heapsize]=new H(x);
            int i=heapsize;
            while(i>1 && A[i]>A[parent(i)])
            {
                swap(i,parent(i));
                i=parent(i);
            }
            return this;
        }

        MaxHeap<H>* increaseKey(int i, H* x)
        {
            if(i>heapsize && i<1) return this;
            if(*A[i]>=*x) return this;
            *A[i]=*x;
            while(i>1 && A[i]>A[parent(i)])
            {
                swap(i,parent(i));
                i=parent(i);
            }
            return this;
        }

        int size() { return heapsize; }

        void buildMaxHeap()
        {
            for(int i=heapsize/2;i>0;i--)
                heapify(i);
        }

        void print()
        {
            cout<<"HEAP : ";
            for(int i=1;i<=heapsize;i++)
                cout<<*A[i]<<" ";
            cout<<endl;
        }

        void printfile(ofstream& f)
        {
            for(int i=1;i<heapsize;i++)
                f<<*A[i]<<" ";
            f<<endl;
        }

        
};

int main()
{
    ifstream infile("input.txt");
    ofstream outfile("output.txt");
    string line;
    int n;
    string tipo;
    while(getline(infile,line))
    {
        istringstream iss(line);
        iss>>tipo>>n;
        if(tipo=="int")
        {
            int t;
            MaxHeap<int> *M=new MaxHeap<int>(n);
            for(int i=0;i<n;i++)
            {
                iss>>t;
                M->enqueue(t);
            }
            M->buildMaxHeap();
            M->printfile(outfile);
        }
        if(tipo=="double")
        {
            double t;
            MaxHeap<double> *M=new MaxHeap<double>(n);
            for(int i=0;i<n;i++)
            {
                iss>>t;
                M->enqueue(t);
            }
            M->buildMaxHeap();
            M->printfile(outfile);
        }
        if(tipo=="bool")
        {
            bool t;
            MaxHeap<bool> *M=new MaxHeap<bool>(n);
            for(int i=0;i<n;i++)
            {
                iss>>t;
                M->enqueue(t);
            }
            M->buildMaxHeap();
            M->printfile(outfile);
        }
        if(tipo=="char")
        {
            char t;
            MaxHeap<char> *M=new MaxHeap<char>(n);
            for(int i=0;i<n;i++)
            {
                iss>>t;
                M->enqueue(t);
            }
            M->buildMaxHeap();
            M->printfile(outfile);
        }
    }

}