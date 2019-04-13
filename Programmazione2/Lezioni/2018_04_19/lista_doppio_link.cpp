#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
using namespace std;

class Nodo
{
    private:
        int key;
        Nodo *next, *prev;
        Nodo ();
    public:
        Nodo(int key) {
            this->key=key;
            next = prev = NULL;
        }
        void setKey(int key) {this->key=key;}
        void setNext(Nodo *n) {next=n;}
        void setPrev(Nodo *n) {prev=n;}
        int getKey() {return key;}
        Nodo* getNext() {return next;}
        Nodo* getPrev() {return prev;}
};

class DList
{
    private:
        int n;
        Nodo *current;
        Nodo *header, *trailer;
        Nodo *_search(int e)
        {
            Nodo *tmp=header->getNext();
            while(tmp!=trailer && tmp->getKey()<e)
                tmp=tmp->getNext();
            if(tmp!=trailer && tmp->getKey()==e)
                return tmp;
            return NULL;
        }
    
    public:
        DList()
        {
            n=0;
            header = new Nodo(0);
            trailer = new Nodo(0);
            header->setNext(trailer);
            trailer->setPrev(header);
            current=NULL;
        }

        void print()
        {
            cout<<"{";
            Nodo* tmp=header->getNext();
            while(tmp!=trailer) //finche' non incontro null quindi ho finito la lista
            {

                cout<<tmp->getKey();
                if(tmp->getNext()!=trailer) cout<<" ";
                tmp=tmp->getNext();
            }
            cout<<"}"<<endl;
        }

        DList *insert(int e)
        {
            Nodo *i = header->getNext();
            while(i!=trailer && i->getKey()<e)
                i=i->getNext();
            Nodo *node=new Nodo(e);
            Nodo *prev=i->getPrev();
            prev->setNext(node);
            node->setPrev(prev);
            node->setNext(i);
            i->setPrev(node);
            n++;
            return this;
        }

        DList *canc(int e)
        {
            // Nodo *prev, *i;
            // prev = NULL;
            // i = header->getNext();
            // while(i!=NULL && i->getKey()<e)
            // {
            //     prev = i;
            //     i=i->getNext();
            // }
            // if(!i || i->getKey()!=e) return this;
            // if(prev!=NULL) prev->setNext(i->getNext()); 
            // else head = i->getNext();
            // n--;
            Nodo *i = _search(e);
            if(!i) return this;
            i->getPrev()->setNext(i->getNext());
            i->getNext()->setPrev(i->getPrev());
            n--;
            return this;
        }

        int search(int e)
        {
            return (_search(e)!=trailer);
        }

        void reset() { current = header->getNext();}

        int *next() // perche' torno un puntatore ad intero? perch
        {
            if(current && current!=trailer)
            {
                Nodo *tmp=current;
                current=current->getNext();
                return new int(tmp->getKey());
            }
            return NULL;
        }

        int has_next() { return ((current!=NULL) && (current!=trailer));}

};

int main()
{
    DList *l = new DList;
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