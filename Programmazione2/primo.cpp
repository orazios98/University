#include <iostream>

using namespace std;

void stampa()
{
    cout<<"bravo!"<<endl;
}

int main() {
    stampa();
    int n1;
    int n2;
    int n3;
    stampa();
    cout<<"Inserisci i tre numeri"<<endl;
    cin>>n1;
    cin>>n2;
    cin>>n3;

    float somma;
    somma=n1+n2+n3;
    float media;
    media=somma/3;
    cout<<"la media e': "<<media<<endl;
    stampa();
    return 0;
}


