#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
using namespace std;

class Nodo
{
    private:
        int key;
        Nodo *next;
        Nodo ();
    public:
        Nodo(int key) {this->key=key;}
        void setKey(int key) {this->key=key;}
        void setNext(Nodo *n) {next=n;}
        int getKey() {return key;}
        Nodo* getNext() {return next;}
};

class List
{
    private:
        int n;
        Nodo *head, *current;
        Nodo *_search(int e)
        {
            Nodo *tmp=head;
            while(tmp!=NULL && tmp->getKey()<e)
                tmp=tmp->getNext();
            if(tmp && tmp->getKey()==e)
                return tmp;
            return NULL;
        }
    
    public:
        List()
        {
            n=0;
            head=NULL;
            current=head;
        }

        void print()
        {
            cout<<"{";
            Nodo* tmp=head;
            while(tmp!=NULL) //finche' non incontro null quindi ho finito la lista
            {

                cout<<tmp->getKey();
                if(tmp->getNext()!=NULL) cout<<" ";
                tmp=tmp->getNext();
            }
            cout<<"}"<<endl;
        }

        List *insert(int e)
        {
            Nodo *prev, *i;
            prev = NULL;
            i = head;
            while(i!=NULL && i->getKey()<e)
            {
                prev = i;
                i=i->getNext();
            }
            Nodo *node=new Nodo(e);
            node->setNext(i);
            if(prev!=NULL) prev->setNext(node);
            else head=node;
            n++;
            return this;
        }

        List *canc(int e)
        {
            Nodo *prev, *i;
            prev = NULL;
            i = head;
            while(i!=NULL && i->getKey()<e)
            {
                prev = i;
                i=i->getNext();
            }
            
            if(!i || i->getKey()!=e) return this;
            if(prev!=NULL) prev->setNext(i->getNext()); // faccio scavalcare l'elemento da eliminare
            else head = i->getNext();
            n--;
            return this;
        }

        int search(int e)
        {
            return (_search(e)!=NULL);
        }

        void reset() { current = head;}

        int *next() // perche' torno un puntatore ad intero? perch
        {
            if(current!=NULL)
            {
                Nodo *tmp=current;
                current=current->getNext();
                return new int(tmp->getKey());
            }
            return NULL;
        }

        int has_next() { return (current!=NULL);}

};

int main()
{
    List *l = new List;
    l->insert(5)->insert(6)->insert(2)->insert(10)->insert(8);
    l->print();
    l->reset();
    while(l->has_next())
    {
        int *i = l->next();
        cout <<(*i)*2 << " ";

    }
    cout<<endl;
    l->canc(4)->print();
    l->canc(6)->print();
    l->canc(2)->print();
    l->canc(10)->print();
    return 0;
}