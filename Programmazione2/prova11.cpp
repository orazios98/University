#include <iostream>

using namespace std;

int main()
{
    float numero;
    cin>>numero;
    int condizione;
    cin>>condizione;


    if(condizione==1)
    {
        numero=numero*2;
    }
    else
    {
        numero=numero/2;
    }

    cout<<numero<<endl;


    return 0;
}
