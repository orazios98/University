#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void swap(int *v, int i, int j)
{
    int tmp=v[j];
    v[j]=v[i];
    v[i]=tmp;
}

int insertionSort(int *v, int n)
{
    int cont=0;
    for(int i=1; i<n; i++)
    {
        int j=i-1;
        while(j>=0 && v[j]>v[j+1])
        {
            cont++;
            int t=v[j];
            v[j]=v[j+1];
            v[j+1]=t;
            j--;
        }

    }
    return cont;
}

int main()
{
    ifstream inf("input.txt");
    ofstream of("output.txt");
    string l;
    int n;
    while(getline(inf,l))
    {
        istringstream iss(l);
        iss>>n;
        int *vett=new int[n];
        int t;
        for(int i=0;i<n;i++)
        {
            iss>>t;
            vett[i]=t;
        }
        of<<insertionSort(vett,n)<<endl;
    }
    return 0;
}
