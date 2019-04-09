/*
 Implementazione di una lista doppiamente linkata:
 Classe Set: interfaccia
 Classe List: lista linkata non ordinata
 Classe OList: lista linkata ordinata
 ---
 Prof. Simone Faro
 Corso di Laurea in Informatica
 Dipartimento di Matematica e Informatica, UnivesitÃ  degli studi di Catania
 */


#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
using namespace std;


/* Interfaccia */
template <class M> class Set {
public:
    virtual Set<M>* insert()=0;
    virtual Set<M>* canc(M)=0;
    virtual int search(M)=0;
    virtual int size()=0;
};

/*
 Classe Nodo
 rappresenta il nodo di una lista doppiamente linkata
 */
template <class T> class Nodo {
private:
    T* key;
    Nodo<T> *next, *prev;
    Nodo();

public:
    Nodo(T *key) {
        this->key = key;
        next = prev = NULL;
    }

    Nodo(T key) {
        this->key = new T(key);
        next = prev = NULL;
    }
    void setKey(T key) {this->key = new T(key);}
    void setNext(Nodo<T> *x) {next = x;}
    void setPrev(Nodo<T> *x) {prev = x;}
    T getKey() {return (*key);}
    Nodo<T>* getNext() {return next;}
    Nodo<T>* getPrev() {return prev;}
};


/*
 Classe List
 rappresenta il nodo di una lista doppiamente linkata
 */
template <class F> class List: public Set<F>{
protected:
    int n;
    Nodo<F> *current; //utilizzato per l'iteratore della lista
    Nodo<F> *header, *trailer; //nodi sentinella posizionati all'inizio e alla fine della lista

    Nodo<F> *_search(F e) {
        // funzione di servizio utilizzata per la ricerca del nodo contenente la chiave e
        Nodo<F> *tmp = header->getNext();
        while(tmp!=trailer) tmp=tmp->getNext();
        if(tmp!=trailer && tmp->getKey()==e) return tmp;
        return NULL;
    }

    Nodo<F> *r_search(F e, Nodo<F> *x) {
        // funzione (ricorsiva) di servizio utilizzata per la ricerca del nodo contenente la chiave e a partire dal nodo x
        if(x==trailer) return NULL;
        if(x->getKey()==e) return x;
        return r_search(e, x->getNext());
    }

    void r_print(Nodo<F> *x) {
        // funzione (ricorsiva) di servizio per la stampa della lista, a paertire dal nodo x
        if(x->getPrev()==header) cout << "{";
        if(x==trailer) {
            cout << "}"<< endl;
            return;
        }
        else {
            cout << x->getKey();
            if(x->getNext()!=trailer) cout << " ";
        }
        r_print(x->getNext());
    }

     void _insert(F e, Nodo<F>* x) {
        //funzione di servizio per l'inserimento di un elemento e prima del nodo x
        Nodo<F> *prev = x->getPrev();
        Nodo<F> *node = new Nodo<F>(e);
        prev->setNext(node);
        node->setPrev(prev);
        node->setNext(x);
        x->setPrev(node);
        n++;
    }

public:
    List() {
        // costruttore di dafault
        n = 0;
        F *tmp = NULL;
        header = new Nodo<F>(tmp);
        trailer = new Nodo<F>(tmp);
        header->setNext(trailer);
        trailer->setPrev(header);
        current = NULL;
    }

    int size() {
        // restituisce la il numero di elementi presenti nella lista
        return n;
    }

    int getSize() const {
        // restituisce la il numero di elementi presenti nella lista
        return n;
    }

    int search(F e) {
        // funzione pubblica di ricerca
        // restituisce un valore booleano per indicare se l'elemento Ã¨ Ã¨ presente o meno nella lista
        return (r_search(e,header->getNext())!=NULL);
    }


    /*void print() {

         cout << "{";
         Nodo<F>* tmp = header->getNext();
         while(tmp!=trailer) {
         cout << tmp->getKey();
         if(tmp->getNext()!=trailer) cout << " ";
         tmp=tmp->getNext();
         }
         cout << "}" << endl;

        r_print(header->getNext());
    }*/

    List<F> *insertFront(F e) {
        //inserimento in testa dell'elemento e
        _insert(e, header->getNext());
        return this;
    }

    List<F> *insertBack(F e) {
        //inserimento in coda dell'elemento e
        _insert(e, trailer);
        return this;
    }

    List<F> *insert(F e) {
        //inserimento dell'elemento e (di default avviene in testa)
        return insertFront(e);
    }

    void reset() {
        // inizializzazione dell'iteratore
        current = header->getNext();
    }

    F *next() {
        // funzione di iterazione:
        // restituisce l'elemento successivo della lista
        if(current && current!=trailer) {
            Nodo<F> *tmp = current;
            current = current->getNext();
            return new F(tmp->getKey());
        }
        return NULL;
    }

    int has_next() {
        // funzione di iterazione:
        // restituisce un valore booleano indicante la presenza o meno di un elemento successivo nella lista
        return (current!=NULL && current!=trailer);
    }

    List<F> *canc(F e) {
        // funzione di camcellazione dell'elemento e dalla lista
        Nodo<F> *i = r_search(e, header->getNext());
        if(!i) return this;
        i->getPrev()->setNext(i->getNext());
        i->getNext()->setPrev(i->getPrev());
        n--;
        return this;
    }
};

template <class H> ostream &operator<<(ostream& out, const List<H>& l1) {
	List<H> l = l1;
	l.reset();
	out << "{[" << l.size() << "] ";
	while(H *i = l.next()) {
		out << *i;
		if(l.has_next()) out << ", ";
	}
	out << "}";
	return out;
}

template <class H>
bool operator==(const List<H>& c, const List<H>& d) {
	List<H> l = c;
	List<H> m = d;
	if(l.size() != m.size()) return false;
	l.reset();
	while(H* i = l.next()) {
		if(! m.search(*i)) return false;
	}
	return true;
}




/*
 Classe OList, implementa una lista ordinata doppiamente Linkata. L'ordine Ã¨ non decrescente.
 I metodi principali sono ereditati dall calsse List
 */
template <class F> class OList: public List<F>{
private:
    Nodo<F> *_search(F e) {
        // funzione di servizio utilizzata per la ricerca del nodo contenente la chiave e
        // specializza la funzione presente nella classe List
        Nodo<F> *tmp = List<F>::header->getNext();
        while(tmp!=List<F>::trailer && tmp->getKey()<e) tmp=tmp->getNext();
        if(tmp!=List<F>::trailer && tmp->getKey()==e) return tmp;
        return NULL;
    }

    OList<F> *r_insert(F e, Nodo<F>* x) {
        // funzione (ricorsiva) di servizio per l'inserimento di un elemento e, a partire de un nodo x
        if(x==List<F>::trailer || x->getKey()>e) {
            Nodo<F> *node = new Nodo<F>(e);
            node->setNext(x);
            node->setPrev(x->getPrev());
            x->getPrev()->setNext(node);
            x->setPrev(node);
            return this;
        }
        return r_insert(e, x->getNext());
    }

public:
    int search(F e) {
        // funzione pubblica di ricerca
        // restituisce un valore booleano per indicare se l'elemento Ã¨ Ã¨ presente o meno nella lista
        // specializza la funzione presente nella classe List
        return (List<F>::r_search(e,List<F>::header->getNext())!=NULL);
    }

    OList<F> *insert(F e) {
        // specializza la funzione presente nella classe List

        /*
         //versione non ricorsiva di inserimento
         Nodo<F> *i = header->getNext();
         while(i!=trailer && i->getKey()<e) i=i->getNext();
         _insert(e,i);
         n++;
         return this;
         */

        // inserimento ricorsivo
        List<F>::n++;
        return r_insert(e, List<F>::header->getNext());
    }
};


template <class F> class CList: public List<F>{
private:
	Nodo<F>*  cursor;

public:
	CList() {
		cursor = NULL;
	}

	CList<F> *insertBefore(F e) {
		if(cursor==NULL) {
			List<F>::_insert(e,List<F>::trailer);
			cursor = List<F>::header->getNext();
		}
		else List<F>::_insert(e, cursor);
		return this;
	}

	CList<F> *insertAfter(F e) {
		if(cursor==NULL) {
			List<F>::_insert(e,List<F>::trailer);
			cursor = List<F>::header->getNext();
		}
		else List<F>::_insert(e, cursor->getNext());
		return this;
	}

	CList<F> *insert(F e) {
		insertAfter(e);
		return this;
	}

	CList<F> *canc(F e) {
        Nodo<F> *i = List<F>::r_search(e, List<F>::header->getNext());
        if(!i) return this;
        i->getPrev()->setNext(i->getNext());
        i->getNext()->setPrev(i->getPrev());
        List<F>::n--;
        if(cursor==i) {
        	cursor = cursor->getPrev();
        	if(cursor==List<F>::header)
        		cursor = List<F>::trailer->getPrev();
        	if(cursor==List<F>::header)
        		cursor = NULL;
        }
        return this;
	}

	void reset() {
        // inizializzazione dell'iteratore
        List<F>::current = cursor;
    }

    F *next() {
        if(List<F>::current!=NULL) {
            Nodo<F> *tmp = List<F>::current;

            List<F>::current = List<F>::current->getNext();
            if(List<F>::current==List<F>::trailer)
            	List<F>::current= List<F>::header->getNext();

            if(List<F>::current == cursor) List<F>::current=NULL;
            return new F(tmp->getKey());
        }
        return NULL;
    }

    int has_next() {
        // funzione di iterazione:
        // restituisce un valore booleano indicante la presenza o meno di un elemento successivo nella lista
        return (List<F>::current!=NULL);
    }

    void moveRight() {
    	if(!cursor) return;
    	cursor = cursor->getNext();
    	if(cursor == List<F>::trailer)
    		cursor = List<F>::header->getNext();
    }

    void moveLeft() {
    	if(!cursor) return;
    	cursor = cursor->getPrev();
    	if(cursor == List<F>::header)
    		cursor = List<F>::trailer->getPrev();
    }

};
