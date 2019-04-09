#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string.h>
#include <algorithm>

using namespace std;



ifstream inf("input.txt");
ofstream of("output.txt");

int main()
{
	
	string l;
    int N;
	while(getline(inf, l))
    {
		istringstream iss(l);
		iss >> N;
        char *num=new char[N];
        int *poss=new int[N];
        char *arr=new char[N];
        int *wild=new int[N];
        int indice=N;
        char *effective=new char[N];
        string app;
        for(int i=0;i<N;i++)
        {
            iss>>num[i];
        }
        iss>>app;

        int cont=0;
        int wildcont=0;
        for(int i=0;i<N;i++)
        {
            if(app[i]!='*')
            {
                poss[cont]=i;
                arr[cont]=app[i];
                cont++;
            }
            else
            {
                wild[wildcont]=i;
                wildcont++;
            }
        }

        for(int i=0;i<cont;i++)
        {
            char temp=arr[i];
            for(int j=0;j<N;j++)
            {
                if(temp==num[j])
                {
                    indice--;
                    for(int k=j;k<N;k++) num[k] = num[k+1];
                }
            }
        }
        
        sort(num,num+indice);
        do {
            int contatore=0;
            for(int j=0;j<wildcont;j++)
            {
                app[wild[j]]=num[contatore];
                contatore++;
            }
            of<<app<<" ";
        } while ( next_permutation(num,num+indice) );

        of<<endl;
	}
	return 0;
}

