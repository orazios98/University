#include <iostream>
#include <ctime>
#include <math.h>

using namespace std;

template <class H> class MinHeap 
{
    private:
		H **A;
		int heapsize;
		int len;
		int left(int i) {return i<<1;}
        int right(int i) {return (i<<1)|1;}
        int parent(int i) {return i>>1; }

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
            int min=i;
            if(l<=heapsize && *A[l]<*A[min]) min=l;
            if(r<=heapsize && *A[r]<*A[min]) min=r;
            if(min==i) return;
            swap(i,min);
            heapify(min);
        }

    public:

        MinHeap (int size)
        {
            A=new H*[size];
            len=size;
            heapsize=0;
        }

        H* extractMax()
        {
            if(heapsize==0) return NULL;
            swap(1, heapsize);
            heapsize--;
            heapify(1);
            return A[heapsize+1];
        }

        MinHeap <H>* enqueue (H x)
        {
            heapsize++;
            A[heapsize] = new H(x);
            int i= heapsize;
            while(i>1 && A[i]<A[parent(i)])
            {
                swap(i,parent(i));
                i=parent(i);
            }
            return this;
        }

        MinHeap <H>* increaseKey(int i, H *x)
        {
            if(i>heapsize) return this;
			if(i<1) return this;
            if( *A[i]>= *x) return this;
            *A[i]=*x;
            while(i>1 && A[i]<A[parent(i)])
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

        void buildMinHeap()
        {
            for(int i=heapsize/2;i>0;i--)
            {
                cout<<heapsize<<endl;
                cout<<i<<endl;
                heapify(i);
            }
        }
};

int main() {
	MinHeap <int> *B = new MinHeap <int>(100);
	B->enqueue(10)->enqueue(5)->enqueue(23);
	B->print();
    B->buildMinHeap();
    B->print();
	return 1;
}

