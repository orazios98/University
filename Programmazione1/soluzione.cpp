#include<iostream>
#include<cmath>
#include<cstdlib>
#include<typeinfo>

using namespace std;

class MyArray {
	private:
		int dim;
		short *data;
	public:
		MyArray(int _dim) : dim(_dim) {
			data = new short[dim];

			for(int i=0;i<dim; i++)
				data[i] = (short) (dim*sin(dim+i));
		}

		float avg() {
			float somma = 0;
			for(int i=0; i<dim; i++)
				somma+=data[i];
			return somma/dim;
		}

		int greater(int arg) {
			int contatore = 0;
			for(int i=0; i<dim; i++)
				if(data[i]>arg)
					contatore++;
			return contatore;
		}

		ostream &put(ostream &stream) const{
			stream << "[";
			for(int i=0; i<dim-1;i++)
				stream<<data[i]<<", ";
			stream<<data[dim-1]<<"]";
			return stream;
		}

};

ostream& operator<<(ostream &stream, const MyArray &m) {
	return m.put(stream);
}

class A {
	private:
		int dim;
	protected:
		MyArray *x;
	public:
		A(int _dim) : dim(_dim) {
			x = new MyArray(dim);
		}

		virtual float f() const = 0;

		virtual ostream& put(ostream &stream) const {
			stream << "Class "<<typeid(*this).name()<<", dim="<<dim << " "<<*x;
		}

};

ostream& operator<<(ostream &stream, const A &a) {
	return a.put(stream);	
}

class B : public A {
	public:
		B(int dim) : A(dim) {}
		float f() const {
			return x->avg();
		}

		ostream& put(ostream &stream) const {
			A::put(stream);
			stream << "\t\tf()="<<f();
			return stream;
		}
};

class C : public A {
	private:
		double w;
	public:
		C(int dim, double _w) : A(dim), w(_w) {}
		float f() const {
			return x->greater((int) w);
		}

		float f(int x) const {
			return w*x;
		}

		ostream &put(ostream& stream) const {
			A::put(stream);
			stream<<"\tw="<<w<<"\tf()="<<f()<<"\tf(4)="<<f(4);
		  	return stream;
		}
};

int main() {
	const int DIM = 30;
	A* vett[DIM];

	float somma = 0;
	int conta_c = 0;

	int indice_c;
	float f4;

	srand(833274768);
	for(int i=0; i<DIM; i++) {
		int x=1+rand()%5;
		switch(x%2) {
			case 0: vett[i] = new B(x);
					break;
			case 1: vett[i] = new C(x,x/(double)RAND_MAX*10000);
		}

		somma+=vett[i]->f();

		if(typeid(*vett[i])==typeid(C)) {
			conta_c++;
			if(conta_c==5){
				indice_c=i;
				f4 = ((C*)vett[i])->f(4);
			}
		}

		cout<<i<<") "<<*vett[i]<<endl;
	}

	cout << "punto 1 : sum="<<somma<<"\t\t punto 2 : f(4)="<<f4<<" di indice "<<indice_c<<endl;
}
	
