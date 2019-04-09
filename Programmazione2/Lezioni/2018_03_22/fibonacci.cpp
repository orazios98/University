#include <iostream>
#include <fstream>
#include <time.h>
#include <string.h>
using namespace std;

int fib1(int n)
{
    if(n<=2) return 1;
    return fib1(n-1)+fib1(n-2);
}


//uso questa funzione per risparmiare tempo in quanto uso gia i valori se li conosco
int FIB[1000]={0};
int fib2(int n)
{
    if(n<=2) return 1;
    if(FIB[n-1]==0)  FIB[n-1] = fib2(n-1);
    if(FIB[n-2]==0)  FIB[n-2] = fib2(n-2);
    return FIB[n-1]+FIB[n-2];
}


//procedura iterativa che usa l'array 
int fib3(int n)
{
    FIB[1]=FIB[2]=1;
    for(int i=3; i<=n; i++)
    {
        FIB[i]=FIB[i-1]+FIB[i-2];
    }
    return FIB[n];
}

//procedura iterativa che usa solo tre variabili
int fib4(int n)
{
    int a,b,c; // a= fib(n-1), b=fib(n-2), c=fib()
    a = b = 1;
    for(int i=3; i<=n; i++)
    {
        c=a+b;
        b=a;
        a=c;
    }
    return c;
}


//fibonacci aureo: calcola il numero di fibonacci usando il numero aureo che e' un decimale infinito, la sua approssimazione ci
//portera' a degli errori soprattutto con numeri molto grandi

int main()
{
        cout << fib2(233);
}