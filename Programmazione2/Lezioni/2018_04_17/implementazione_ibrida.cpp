#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
using namespace std;

#define SIZE 100
#define KEY(i) v[i*2]
#define NEXT(i) v[i*2+1]

class ArrayList
{
    private:
        int *v;
        int len,n,head;
        int _search(int x)
        {
            int i=head;
            while(i!=-1 && KEY(i)<x) i = NEXT(i);
            if(KEY(i)==x) return i;
            return -1;
        }
    
    public:
        ArrayList()
        {
            v=new int[SIZE];
            len=SIZE;
            n=0;
            head=-1;
        }

        ArrayList *insert(int x)
        {
            if(n>len/2) return this;
            KEY(n) = x;
            if(n==0)
            {
                NEXT(0) = -1;
                head=0;
            }
            else
            {
                //scorro la lista fino a quando non trovo un elemento piu' grande di x, salvo questo e il precedente
                int prev=-1;
                int next=head;
                while(next!=-1 && KEY(next)<x)
                {
                    prev = next;
                    next = NEXT(next);
                }
                NEXT(n) = next;
                if(next==head)
                    head=n;
                else
                    NEXT(prev) = n;
            }
            n++;
            return this;
        }

        ArrayList *canc(int x)
        {
            //funzione per eliminare elemento dall array
            int prev=-1;
            int i=head;
            while(i!=-1 && KEY(i)<x) // non usiamo search perche' non ci da info sul prev
            {
                prev=i;
                i=NEXT(i);
            }
            if(i==-1 || KEY(i)>x) return this;
            int next = NEXT(i);
            if(prev!=-1) NEXT(prev) = next;
            else head = next;

            KEY(i)= KEY((n-1));
            NEXT(i)=NEXT((n-1));
            int j=0;
            while(j<n-1 && NEXT(j)!=n-1) j++;
            if(j<n-1) NEXT(j)=i;
            if(head==n-1) head = i;
            n--;
            return this;
        }

        int search(int x)
        {
            return (_search(x)!=-1);
        }

        void print()
        {
            cout<<"{";
            int i=head;
            while(i!=-1)
            {
                cout << KEY(i);
                if(NEXT(i)!=-1) cout<< " ";
                i = NEXT(i);
            }
            cout<<"}"<<endl;
        }

        void print_deb()
        {
            cout<<"head: "<<head<<" - ";
            for(int i=0;i<n;i++)
            {
                cout << "<";
                cout << KEY(i) <<" "<<NEXT(i)<<"> ";
            }
            cout<<endl;
        }
};


int main()
{
    ArrayList *l= new ArrayList();
    l->insert(3);
    l->insert(1);
    l->insert(2);
    l->print();
    l->canc(3);
    l->canc(1); 
    cout<<endl;
    

    l->print();
    return 0;
}