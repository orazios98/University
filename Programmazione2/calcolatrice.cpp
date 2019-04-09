#include <iostream>

using namespace std;

int main()
{
    int num1;
    int num2;
    int scelta;
    int totale=0;
    do{
        cout<<"Inserisci:"<<endl<<"1. Somma"<<endl<<"2. Sottrazione";
        cout<<endl<<"3. Prodotto"<<endl<<"0. ESCI"<<endl;
        cin>>scelta;

        switch(scelta)
        {
            case 1:
                cout<<"Inserisci i due numeri: "<<endl;
                cin>>num1>>num2;
                totale=num1+num2;
                cout<<"Totale: "<<totale<<endl<<endl;
                break;
            case 2:
                cout<<"Inserisci i due numeri: "<<endl;
                cin>>num1>>num2;
                totale=num1-num2;
                cout<<"Totale: "<<totale<<endl<<endl;
                break;
            case 3:
                cout<<"Inserisci i due numeri: "<<endl;
                cin>>num1>>num2;
                totale=num1*num2;
                cout<<"Totale: "<<totale<<endl<<endl;
                break;
            case 0:
                cout<<"ciao!"<<endl;
                break;
            default:
                cout<<"ERRORE"<<endl;
        }
    }while(scelta!=0);
    return 0;
}
