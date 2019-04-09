#include <iostream>
#include <fstream>
#include <time.h>
#include <string.h>
using namespace std;

/*
Realizziamo gli anagrammi di "arco"
Si tratta di permutazioni di un insieme di caratteri
Per risolvere il problema in modo ricorsivo blocco il primo carattere in modo
ricorsivo.
*/

void swap(char *s, int i, int j)
{
    char tmp=s[i];
    s[i]=s[j];
    s[j]=tmp;
}
void anagramma(char *s);
//overloading della funzione cosi da poter chiamare nel main una funzione piu elegante
void anagramma(char *s, int i,int n);
int main()
{
    char s[]="1123837938692";
    anagramma(s);

}
void anagramma(char *s)
{
    int n=strlen(s);
    anagramma(s,0,n);
}
void anagramma(char *s, int i,int n)
{
    if(i==n)
    {
        cout << s << endl;
        return;
    }
    for(int j=i;j<n;j++)
    {
        swap(s,i,j);
        anagramma(s,i+1,n);
        swap(s, i, j);
    }
}