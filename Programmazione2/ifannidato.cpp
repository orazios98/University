#include <iostream>

using namespace std;

int main()
{
    int numero;
    cin>>numero;

    if(numero>10)
    {


        if(numero%2==0)
        {
          cout<<"OK"<<endl;
        }
        else
        {
            cout<<"numero dispari"<<endl;
        }


    }
    else
    {
        cout<<"numero piccolo"<<endl;
    }

    return 0;
}
