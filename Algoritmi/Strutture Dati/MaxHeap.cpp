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
            A[j]=A[i];
        }

        void heapify(int i)
        {
            if(i>heapsize) return;
            int 
        }



};