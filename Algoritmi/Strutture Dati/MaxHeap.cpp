#include <iostream>

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

        void print()
        {
            cout<<"HEAP : ";
            for(int i=1;i<=heapsize;i++)
                cout<<*A[i]<<" ";
            cout<<endl;
        }

        void buildMaxHeap()
        {
            for(int i=heapsize/2;i>0;i--)
                heapify(i);
        }
};

int main()
{
    MaxHeap <int> *M = new MaxHeap<int>(10);
    M->enqueue(50)->enqueue(5)->enqueue(15);
    M->print();
    M->buildMaxHeap();
    M->print();
    return 1;
}