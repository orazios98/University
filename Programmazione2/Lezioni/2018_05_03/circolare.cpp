#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
using namespace std;

class Coppia
{
    private:
        int x,y;
        Coppia(){};
    public:
        Coppia(int x,  int y)
        {
            this->x=x;
            this->y=y;
        }
        void SetX(int x) { this->x=x;}
        void SetY(int y) {this->y=y;}
        int getX() const  {return x;}
        int getY() const {return y;}
};

ostream &operator<<(ostream& stream,  const Coppia& c)
{
    stream<<"("<<c.getX()<<" , "<<c.getY()<<")";
    return stream;
}

bool operator>(const Coppia& c, const Coppia& d)
{
    if(c.getX()>d.getX())
        return true;
    else if(c.getX()==d.getX() && c.getY()>d.getY())
        return true;
    return false;
}

bool operator==(const Coppia& c, const Coppia& d)
{
    if(c.getX()==d.getX() && c.getY()==d.getY())
        return true;
    return false;
}

bool operator<(const Coppia& c, const Coppia& d)
{
    if(c.getX()<d.getX())
        return true;
    else if(c.getX()==d.getX() && c.getY()<d.getY())
        return true;
    return false;
}


template <class H> class Set
{
    public:

    private:
        virtual Set<H>* insert(H)=0;
        virtual Set<H>* canc(H)=0;
        virtual int search(H)=0;
        virtual int size()=0;
};

template <class T> class Nodo
{
    private:
        T* key;
        Nodo<T> *next, *prev;
        Nodo ();
     
    public:
        Nodo(T* key) {
            this->key=key; 
            //creo nuovo T con costruttore di copia
            next = prev = NULL;
        }
        Nodo(T key) {
            this->key=new T(key); 
            //creo nuovo T con costruttore di copia
            next = prev = NULL;
        }
        void setKey(T key) {this->key=new T(key);}
        void setNext(Nodo<T> *n) {next=n;}
        void setPrev(Nodo<T> *n) {prev=n;}
        T getKey() {return (*key);}
        Nodo<T>* getNext() {return next;}
        Nodo<T>* getPrev() {return prev;}
};


template <class F> class DList:public Set<F>
{
    private:
        int n;
        Nodo<F> *current;
        Nodo<F> *header, *trailer;
        Nodo<F> *_search(F e)
        {
            Nodo<F> *tmp=header->getNext();
            while(tmp!=trailer && tmp->getKey()<e)
                tmp=tmp->getNext();
            if(tmp!=trailer && tmp->getKey()==e) //devo fare attenzione quando uso == con oggetti non primitivi
                return tmp;
            return NULL;
        }

        Nodo<F> *r_search(F e, Nodo<F> *x)
        {
            if(x==trailer) return NULL;
            if(x->getKey()==e) return x;
            return r_search(e, x->getNext());
        }

        DList<F> *r_insert(F e, Nodo<F>* x)
        {
            //devo mettere i test in quest'ordine cosi se ho il trailer non controllo il successivo
            if(x==trailer || x->getKey()>e)
            {
                Nodo<F> *node = new Nodo<F>(e);
                node->setNext(x);
                node->setPrev(x->getPrev());
                x->getPrev()->setNext(node);
                x->setPrev(node);
                return this;
            }           
            return r_insert(e, x->getNext());
        }

        void r_print(Nodo<F> *x)
        {
            if(x->getPrev()==header) cout<<"{";
            if(x==trailer)
            {
                             cout<<"}"<<endl;
                             return;
            } else{
                cout<<x->getKey();
                if(x->getNext()!=trailer)
                    cout<<" ";
            }
            r_print(x->getNext());
        }
    
    public:
        DList()
        {
            n=0;
            F *tmp = NULL;
            header = new Nodo<F>(tmp);
            trailer = new Nodo<F>(tmp);
            header->setNext(trailer);
            trailer->setPrev(header);
            current=NULL;
        }

        void print()
        {
            // cout<<"{";
            // Nodo<F>* tmp=header->getNext();
            // while(tmp!=trailer) //finche' non incontro null quindi ho finito la lista
            // {

            //     cout<<tmp->getKey();
            //     if(tmp->getNext()!=trailer) cout<<" ";
            //     tmp=tmp->getNext();
            // }
            // cout<<"}"<<endl;
            r_print(header->getNext());
        }

        DList<F> *insert(F e)
        {
            // Nodo<F> *i = header->getNext();
            // while(i!=trailer && i->getKey()<e)
            //     i=i->getNext();
            // Nodo<F> *node=new Nodo<F>(e);
            // Nodo<F> *prev=i->getPrev();
            // prev->setNext(node);
            // node->setPrev(prev);
            // node->setNext(i);
            // i->setPrev(node);
            // n++;
            // return this;
            n++;
            return r_insert(e,header->getNext());
            
        }

        DList<F> *canc(F e)
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
            Nodo<F> *i = r_search(e, header->getNext());
            if(!i) return this;
            i->getPrev()->setNext(i->getNext());
            i->getNext()->setPrev(i->getPrev());
            n--;
            return this;
        }

        // int search(F e)
        // {
        //     // return (_search(e)!=trailer);
        //     return (r_search(e, header->getNext()));
        // }

        int search(F e)
        {
            return 0;
        }

        void reset() { current = header->getNext();}

        F *next()
        {
            if(current && current!=trailer)
            {
                Nodo<F> *tmp=current;
                current=current->getNext();
                return new F(tmp->getKey());
            }
            return NULL;
        }

        int has_next() { return ((current!=NULL) && (current!=trailer));}

        int size() { return n;}

};

int main()
{
    // DList<Coppia> *l = new DList<int>();
    // l->insert(5)->insert(6)->insert(2)->insert(10)->insert(8);
    // l->print();
    // l->reset();
    // while(l->has_next())
    // {
    //     int *i = l->next();
    //     cout <<(*i)*2 << " ";

    // }
    // cout<<endl;
    // l->canc(4)->print();
    // l->canc(6)->print();
    // l->canc(2)->print();
    // l->canc(10)->print();
    DList<Coppia> *l = new DList<Coppia>();
    l->insert(Coppia(5,2));
    l->print();
    l->r_search(Coppia(5,2));
    l->r_search(Coppia(5,3));
    return 0;
}