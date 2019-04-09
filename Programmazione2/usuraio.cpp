#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;


int find_min(int *v, int n) 
{
    int pos = 0;
    for(int j=1; j<n; j++)
    {
        if(v[j]< v[pos]) pos = j;
    }
    int min=v[pos];
    for(int j=pos-1; j>=0; j--) v[j+1] = v[j];
    return min;
}


void selectionSort(int *v, int n)
{
    for(int i=0; i<n-1; i++) //l'ultima iterazione e' inutile poiche fatta su un solo elemento
    {
        int m=find_min(v+i,n-1);
        v[i] = m;
    }
}

 void BubbleSort(int *array, int elemN)
 {
   /* elemN è il numero degli elementi del vettore da ordinare */

   int alto;
   for (alto = elemN - 1; alto > 0; alto-- )
     { 
         for (int i=0; i<alto; i++)
         {
           if (array[i]>array[i+1]) /* sostituire ">" con "<" per avere un ordinamento decrescente */
           { 
             int tmp = array[i]; 
             array[i] = array[i+1]; 
             array[i+1] = tmp;
           } 
         }
     }
 }

int main()
{
	ifstream inf("input.txt");
    ofstream of("output.txt");
	string l;
    int N,K;
	while(getline(inf, l))
    {
		istringstream iss(l);
		iss >> N >> K;
        int *locali=new int[N];
        for(int i=0;i<N;i++)
        {
            iss>>locali[i];
        }
        //selectionSort(locali,N);
        BubbleSort(locali, N);
        for(int i=0;i<N;i++)
        {
            //cout<<locali[i]<<" ";
        }
        //cout<<endl;
        int min=10000;
        for(int i=0;i<=N-K;i++)
        {
            cout<<"end: "<<N-K-1<<endl;
            cout<<"I: "<<i<<" i+k-1: "<<locali[i+K-1]<<" i: "<<locali[i];
            int dist=locali[i+K-1]-locali[i];
            cout<<" dist: "<<dist <<" min: "<<min;
            //cout<<locali[i+K-1]<<" "<<locali[i]<<" ";
            //cout<<dist;
            if(dist<min)
                min=dist;
            cout<<" min dopo: "<<min<<endl<<endl;
        }
        //cout<<endl;
        of<<min<<endl;
	}
	return 0;
}