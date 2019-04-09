#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int selectionSort(int *v, int n)
{
    int c=0;
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(v[j]<v[min])
            {
                min=j;

            }
        }
        c=c+(min-i);
        int t=v[i];
        v[i]=v[min];
        v[min]=t;
    }
    return c;
}


int main()
{
    ifstream ing("input.txt");
    ofstream of("output.txt");
    string l;
    int n;
    while(getline(ing,l))
    {
        istringstream iss(l);
        iss>>n;
        int *v=new int[n];
        int t;
        for(int i=0;i<n;i++)
        {
            iss>>t;
            v[i]=t;
        }
        of<<selectionSort(v,n)<<endl;
    }
}
