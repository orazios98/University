#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;
class Quadrato
{
    double *lato;
    double *perimetro;
    double *area;
    Quadrato() {}

    public:

        double *getLato() { return new double(*lato);}
        
        static Quadrato fromLato(double *lato)
        {
            Quadrato q;
            q.lato=new double(*lato);
            q.perimetro= new double((*lato)*4);
            q.area=new double((*lato)*(*lato));
            return q;
        }

        void print()
        {
            cout<<"lato: "<<*lato<<" per: "<<*perimetro<<" area: "<<*area<<endl;
        }
};

int main()
{
    double *v = new double(6);
    Quadrato p = Quadrato::fromLato(v);
    p.print();

    Quadrato 

}