#include <iostream>
#include <ctime>
#include <math.h>
#include <fstream>
#include <sstream>

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

        void printfile(ofstream& f)
        {
            for(int i=1;i<=heapsize;i++)
                f<<*A[i]<<" ";
            f<<endl;
        }

        void buildMinHeap()
        {
            for(int i=heapsize/2;i>0;i--)
            {
                heapify(i);
            }
        }
};

int main(){
    
	ifstream infile("input.txt");
	ofstream outfile("output.txt");
	string line;
	int n;
    string tipo;
	while(getline(infile, line)){
		istringstream iss(line);
		iss >> tipo >> n;
        if(tipo=="int")
        {
            int t;
            MinHeap <int> *B = new MinHeap <int>(n);
            for(int i=0;i<n;i++)
            {
                iss>>t;
                B->enqueue(t);
            }
            B->buildMinHeap();
            B->printfile(outfile);
        }
        if(tipo=="double")
        {
            double db;
            MinHeap<double> *B=new MinHeap<double>(n);
            for(int i=0;i<n;i++)
            {
                iss>>db;
                B->enqueue(db);
            }
            B->buildMinHeap();
            B->printfile(outfile);
        }
        if(tipo=="bool")
        {
            bool db;
            MinHeap<bool> *B=new MinHeap<bool>(n);
            for(int i=0;i<n;i++)
            {
                iss>>db;
                B->enqueue(db);
            }
            B->buildMinHeap();
            B->printfile(outfile);
        }
        if(tipo=="char")
        {
            char db;
            MinHeap<char> *B=new MinHeap<char>(n);
            for(int i=0;i<n;i++)
            {
                iss>>db;
                B->enqueue(db);
            }
            B->buildMinHeap();
            B->printfile(outfile);
        }
	}
	return 0;
}