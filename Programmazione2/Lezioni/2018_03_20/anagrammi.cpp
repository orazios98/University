#include <iostream>
#include <fstream>
using namespace std;

void anagramma(char *v,int n);

int main()
{
    char s[]= "itopinonavevanonipoti";
    anagramma(s,21);
    return 0;
}

void anagramma(char *v,int n)
{
    if(n==1)
    {
        cout<<v[0];
        return;
    }
    anagramma(v+1,n-1);
}