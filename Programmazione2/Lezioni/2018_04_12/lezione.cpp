#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace std;
class Quadrato
{
    double lato;
    double perimetro;
    double area;
    Quadrato() {}

    public:
        // Quadrato(double lato)
        // {
        //     this->lato=lato;
        //     this->perimetro=lato*4;
        // }

        // Quadrato(double perimetro) 
        // {
        //     this->lato=perimetro/4;
        //     this->perimetro=perimetro; 
        // }

        // Quadrato(double val, int cod) -> implementazione con uso di codice ma poco intuitiva
        // {
        //     if(cod==0)
        //     {
        //         lato=val;
        //         perimetro=val*4;
        //     }
        //     else
        //     {
        //         lato=val/4;
        //         perimetro=val;
        //     }
        // }


        static Quadrato fromLato(double lato)
        {
            Quadrato q;
            q.lato=lato;
            q.perimetro=lato*4;
            q.area=lato*lato;
            return q;
        }

        static Quadrato fromPerimetro(double perimetro)
        {
            Quadrato q;
            q.lato=perimetro/4;
            q.perimetro=perimetro;
            q.area=q.lato*q.lato;
            return q;
        }

        static Quadrato fromArea(double area)
        {
            Quadrato q;
            q.lato=sqrt(area);
            q.perimetro=q.lato*4;
            q.area=area;
            return q;
        }

        void print()
        {
            cout<<"lato: "<<lato<<" per: "<<perimetro<<" area: "<<area<<endl;
        }

        void setLato(double l)
        {
            lato=l;
            perimetro=l*4;
            area=l*l;
        }
};

using namespace std;

int main()
{
    Quadrato q = Quadrato::fromLato(6);
    q.print();
    // Quadrato p = Quadrato::fromPerimetro(5);
    // p.print();
    // Quadrato s = Quadrato::fromArea(9);
    // s.print();
}