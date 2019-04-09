#include <iostream>
#include <fstream>
#include <time.h>
#include <math.h>
#include "Coppia.h"
#include "LinkedList.cpp"
using namespace std;
#define DEFAULT_LEN 100

template <class G> class Queue {
	private:
		int len, n, tail, head, current;
		G **v;
	public:
		static G EMPTY;
		Queue() {
			n = 0;
			len = DEFAULT_LEN;
			v = new G*[len];
			head = tail = 0;
		}
		Queue(int len) {
			n = 0;
			this->len = len;
			v = new G*[len];
			head = tail = 0;
		}
		
		Queue<G>* enqueue(G x) {
			if(n==len) return this;
			v[tail] = new G(x);
			tail = (tail+1)%len;
			n++;
			return this;
		}
		
		G dequeue() {
			if(n==0) return EMPTY;
			G r = *v[head];
			head = (head+1)%len;
			n--;
			return r;
		}
		
		int size() {return n;}
		int isEmpty() { return (n==0); }
		
		void reset() {current = 0;}
		G* next() {
			if(current==n) return NULL;
			G* r=v[(head+current)%len];
			current++;
			return r;
		}
		int has_next() {
			return (current<n); 
		}
};

template <class H> ostream &operator<<(ostream& out, const Queue<H>& q1) {
	Queue<H> q = q1;
	q.reset();
	out << "{";
	while(H *i = q.next()) {
		out << *i;
		if(q.has_next()) out << ", ";
	}
	out << "}";
	return out;
}

template<> int Queue<int>::EMPTY = -1;


template <class G> class Stack {
	private:
		int len, n, top, current;
		G **v;
	public:
		static G EMPTY;
		Stack() {
			n = 0;
			len = DEFAULT_LEN;
			v = new G*[len];
			top = 0;
		}
		Stack(int len) {
			n = 0;
			this->len = len;
			v = new G*[len];
			top = 0;
		}
		
		Stack<G>* push(G x) {
			if(top==len) return this;
			v[top] = new G(x);
			top++;
			n++;
			return this;
		}
		
		G pop() {
			if(n==0) return EMPTY;
			top--;
			n--;
			return *v[top];
		}
		
		void reset() {current = top-1;}
		G* next() {
			if(current<0) return NULL;
			G* r=v[current];
			current--;
			return r;
		}
		int has_next() {
			return (current>=0); 
		}
		int size() {return n;}
		int isEmpty() { return (n==0); }		
};

template<> int Stack<int>::EMPTY = -1;

template <class H> ostream &operator<<(ostream& out, const Stack<H>& s1) {
	Stack<H> s = s1;
	s.reset();
	out << "{";
	while(H *i = s.next()) {
		out << *i;
		if(s.has_next()) out << ", ";
	}
	out << "}";
	return out;
}

template <class F> class SQueue {
	private:
		Stack<F> *s1;
		Stack<F> *s2;
	public:
		SQueue() {
			s1 = new Stack<F>();
			s2 = new Stack<F>();
		}
		
		int size() {return s1->size()+s2->size(); }
		int isEmpty() { return (s1->isEmpty() && s2->isEmpty());}
		
		SQueue<F> *enqueue(F x) { 
			s1->push(x); 
			return this;
		}
		
		F dequeue() {
			if(s2->isEmpty())
				while(!s1->isEmpty()) s2->push(s1->pop());
			return s2->pop();
		}
		
		void print() {
			Stack<F> *s3 = new Stack<F>();
			while(!s1->isEmpty()) s3->push(s1->pop());
			cout << "{ ";
			s2->reset();
			while(s2->has_next()) cout << *(s2->next()) << " ";
			s3->reset();
			while(s3->has_next()) cout << *(s3->next()) << " ";
			cout << "}" << endl;
			while(!s3->isEmpty()) s1->push(s3->pop());			
		}
};