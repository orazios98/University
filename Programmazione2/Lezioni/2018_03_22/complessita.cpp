#include <iostream>
#include <fstream>
#include <time.h>
#include <string.h>
using namespace std;

//qualsiasi sia n la funzione fara' lo stesso numero di computazioni
void costante(int n)
{
    int a = n;
    n =n*2;
}

//la logaritmica cresce piu lentamente per n che tende a infinito
void log(int n)
{
    for(int i=1;i<n;i*=2)
    {
        a=a+i;
    }
}

//la complessita' computazionale di due cicli for e' pari al prodotto tra le due 
void log2(int n)
{
    int a=0;
    for(int j=1;j<n;j++)
    {
        for(int i=1; i<n; i*=2)
        {
            a=a+1;
        }
    }
}


//la funzione varia in base ad n, piu esso cresce piu la funziona ci stara
void lineare(int n)
{
    int a=0;
    for(int i=0;i<n;i++)
    {
        a=a+i    
    }
}




int main()
{

}