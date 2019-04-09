 #include <iostream>
#include <fstream>

using namespace std;

template <class T> class Nodo
{
    private:
        T* key;
        Nodo<T> *next, *prev;
    public:
        Nodo(T key)
        {
            this->key = new T(key);
            next = prev = NULL;
        }

        Nodo(T* key)
        {
            this->key = key;
            next = prev = NULL;
        }

        void setChiave (T key) { this->key = new T(key); }
        void setNext(Nodo<T> *x) { this->next = x; }
        void setPrev(Nodo<T> *x) { this->prev = x; }

        T getKey() {return *(key);}
        Nodo<T>* getNext() {return next;}
        Nodo<T>* getPrev() {return prev;}
};

template <class F> class List
{
    protected:
        int n;
        Nodo<F> *current, *header, *trailer;

        //funzione per inserire un nodo prima di un altro nodo x
        void _insert(F e, Nodo<F>* x)
        {
            Nodo<F> *prev = x->getPrev(); //salvo il precedente del nodo x
            Nodo<F> *nodo = new Nodo<F>(e); //creo il nuovo nodo
            prev->setNext(nodo);
            nodo->setPrev(prev);
            nodo->setNext(x);
            x->setPrev(nodo);
            n++;
        }

    public:
        List()
        {
            n=0;
            F *tmp=NULL;
            header=new Nodo<F>(tmp);
            trailer=new Nodo<F>(tmp);
            header->setNext(trailer);
            trailer->setPrev(header);
            current=NULL;
        }

        List<F> *insO(F x)
        {
            Nodo<F> *t=header->getNext();
            while(t!=trailer && x>t->getKey())
            {
                t=t->getNext();
            }
            _insert(x,t);
            return this;
        }

        List<F> *ins(F x)
        {
            Nodo<F> *t=header->getNext();
            _insert(x,t);
            return this;
        }

        List<F> *canc(F x)
        {
            Nodo<F> *t=header->getNext();
            while(t!=trailer)
            {
                if(x==t->getKey())
                {
                    t->getPrev()->setNext(t->getNext());
                    t->getNext()->setPrev(t->getPrev());
                    n--;
                    return this;
                }
                t=t->getNext();
            }
            return this;
        }

        F* search(F x)
        {
            Nodo<F> *t=header->getNext();
            while(t!=trailer)
            {
                if(x==t->getKey())
                    return new F(t->getKey());
                t=t->getNext();
            }
            return NULL;
        }

        void print()
        {
            Nodo<F> *tmp = header->getNext();
            for(int i=0;i<n;i++)
            {
                cout<<tmp->getKey()<<" ";
                tmp=tmp->getNext();
            }

        }

        void reset()
        {
            current=header;
        }

        bool hasNext()
        {
            if(current->getNext()!=trailer)
                return true;
            return false;
        }

        F* next()
        {
            if(hasNext())
            {
                current=current->getNext();
                return new F(current->getKey());
            }
        }

};

int main()
{
    List<int> *p = new List<int>();
    p->insO(5)->insO(6)->insO(1)->insO(12)->insO(9)->insO(3);
    p->canc(12);
    cout<<*(p->search(3))<<endl;
    cout<<p->search(0)<<endl;
    p->reset();
    cout<<*(p->next())<<endl;
    cout<<*(p->next())<<endl;
    p->print();
    return 0;
}
