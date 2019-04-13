#include <iostream>
#include <fstream>
using namespace std;
//
/*
    il fattoriale e' il problema per eccellenza che si risolve con la ricorsione
    n!=(n-1)!*n se n!=0     caso generico
    n=1 => n!=1     caso base
    
    Come funziona?
             ---------------------------|
             |   1          se n=1      |
    fatt(n)= |                          |
             |   fatt(n-1)  se n>1      |
            ----------------------------| 


    Ricorsione con gli array

    Possiamo vedere gli array come delle concatenazioni di celle con array
    Es. se abbiamo un array con una sola cella siamo nel caso base e abbiamo una cella ed un sottoarray vuoto
        se abbiamo array con piu' celle possiamo vederlo come una cella concatenta con un array non vuoto

    */

int sommau(int *v, int n);
int sommap(int *v, int n);
int sommanonricorsiva(int *v, int n);
int somma2(int *v, int n);
int sommadoppia(int *v, int n);
int is_palindroma(char *v, int n);

int main()
{
    cout << "Oggi studiamo la ricorsione"<<endl;
    /*
    int v[]= {2,6,7,1,5,2,8,9,3,4};
    int n=10;
    int s=sommau(v,n);
    int t=sommau(v,n);
    int d=sommanonricorsiva(v,n);
    int f=somma2(v,n);
    int z=sommadoppia(v,n);
    cout << s <<"\t"<<z<<endl;
    */
    char s[]= "itopinonavevanonipoti";
    cout << is_palindroma(s, 21)<<endl;
    return 0;
}


//effettua la somma degli elementi di un array in modo ricorsivo partendo dall'ultimo
int sommau(int *v, int n)
{
    if(n==0) return 0;
    return v[n-1] + sommau(v,n-1);
}

//effettua la somma degli elementi di un array in modo ricorsivo partendo dal primo
//ricorsione di coda: la chiamata ricorsiva e' alla fine della procedura
int sommap(int *v, int n)
{
    if(n==0) return 0;
    return v[0] + sommap(v+1,n-1);
}

//effettua la somma senza usare la ricorsione
int sommanonricorsiva(int *v, int n)
{
    int s=0;
    while(n>0)
    {
        s+=v[0];
        v++;
        n--;
    }
    return s;
}

//si riduce di 2 ad ogni chiamata ricorsiva
int somma2(int *v, int n)
{
    if(n==0) return 0;
    if(n==1) return v[0];
    return v[0] + v[n-1] + somma2(v+1,n-2);
}

/*
usiamo la ricorsione doppia:
dividiamo ricorsivamente il problema in due sottoproblemi e risolvo ricorsivamente entrambi
dividiamo l'array sempre in 2 ottendendo degli array progressivamente piu' piccoli fino al caso base
di un array composto da una sola cella
*/

int sommadoppia(int *v, int n)
{
    if(n==0) return 0;
    if(n==1) return v[0];
    int j = n/2-1;
    return sommadoppia(v, j+1) + sommadoppia(v+j+1, n-j-1);

}

int is_palindroma(char *s, int n)
{
    if(n<=1) return 1;
    return (s[0]==s[n-1]) &&  is_palindroma(s+1,n-2);
}