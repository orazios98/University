#include <iostream>

using namespace std;

int main()
{
    cout<<"Inserisci un numero: "<<endl;
    float numero;
    cin>>numero;

    while(numero>2)
    {
        numero=numero/2;
        cout<<numero<<endl;
    }
    cout<<"alla fine numero vale "<<numero<<endl;

    return 0;
}
