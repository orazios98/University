#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

class Coppia
{
    private:
        int x,y;        
    
    public:
        Coppia()
        {
            x = y = 0;
        }

        Coppia(int x, int y)
        {
            this->x=x;
            this->y=y;
        }

        Coppia(const Coppia& c)
        {
            this->x=c.x+1;
            this->y=c.y+1;
        }

        void setX(int x) {this->x=x;}
        void setY(int y) {this->y=y;}
        int getX() {return x;}
        int getY() {return y;}
        void print()
        {
            cout << "x: "<<x<<" y: "<<y<<endl;
        }
             
};

void printCoppia(Coppia x)
{
    cout<<x.getX()<<":"<<x.getY()<<endl;
}

Coppia Coppia00()
{
    Coppia *a=new Coppia(0,0);
    return *a;
}

int main()
{
    Coppia c(5,6);
    c.print();
    Coppia d(c);
    d.print();
    printCoppia(d); //attenzione perche' richiama nuovamente il costruttore di copia
    Coppia u = Coppia00();
    u->print(); // attenzione perche' anche in questo caso richiama il costruttore di copia
    return 0;
}