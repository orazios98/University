#include <iostream>
#include <fstream>
#include <time.h>
#include <string.h>
#include <stdlib.h>  
using namespace std;

int find_min(int *v, int n);
void selectionSort(int *v, int n);
void insertionSort(int *v, int n);
void rec_insertionSort(int *v,int i, int n);
void rec_selectionSort(int *v,int n);
void print(int *v, int n);
void swap(int *v, int i, int j);
void mySort(int *v, int n);
void natural_merge(int *A, int n, int *B, int m, int *C);
int partition(int *v, int b, int e);
void _QuickSort(int *v, int b, int e);
void QuickSort(int *v, int n);
void randomInit(int *v, int n);
void QuickSort2(int *v, int b, int e);
void QuickSort2(int *v, int n);
int naive_selection(int *v, int n, int i);
int smart_selection(int *v, int n, int i);

int main()
{
    clock_t inizio, fine;
    int n=10;
    int *A=new int[n];
    randomInit(A,n);
    print(A,n);
    inizio=clock();
    int pi=naive_selection(A,n,3);
    QuickSort(A,n);
    fine=clock();
    float n_clock=fine-inizio;
    cout <<"clock: "<<n_clock<<endl;
    cout << pi << endl;
    print(A,n);
}

//riceve un vettore, b rapprenta begin, e rappresenta end
//ritorna il punto di divisione dell'array
int partition(int *v, int b, int e)
{
    int i=b-1;
    int j=e+1;
    int p=v[b]; //pivot
    while(1)
    {
        do i=i+1; while(v[i]<p); //aumento l'indice i finche' non trovo un elemento piu' grande del pivot
        do j=j-1; while(v[j]>p); //diminuisco l'indice j finche' trovo elementi piu' grandi del pivot
        if(i<j) swap(v,i,j); //se l'indice i e' minore della j scambio i due elementi
        else return j;
    }

}

int smart_selction(int *v, int n, int i)
{
    if(i>n)
    {
        cout << "errore";
        return -1;
    } 
    if(n==1) return v[0];
    int j=partition(v,0,n-1);
    if(i<=j) smart_selction(v, j+1, i);
    else return smart_selction(v+j+1,  n-j-1,i-j-1);
}

int naive_selection(int *v, int n, int i)
{
    QuickSort(v,n);
    return v[i];
}

void _QuickSort(int *v, int b, int e)
{
    if(b>=e) return; //se contiene piu' di due elementi vado avanti
    int j=partition(v,b,e);
    _QuickSort(v,b,j);
    _QuickSort(v,j+1,e);
}

void QuickSort2(int *v, int b, int e)
{
    while(b<e)
    {
        int j=partition(v,b,e);
        QuickSort2(v,b,j);
        b=j+1;
    }
    
}
void QuickSort2(int *v, int n)
{
    QuickSort2(v,0,n-1);
}

void QuickSort(int *v, int n)
{
    _QuickSort(v,0,n-1);
}

void print(int *v, int n)
{
    for(int i=0; i<n; i++) cout<<v[i]<<"\t";
    cout << endl;
}

void rec_selectionSort(int *v, int n)
{
    if(n==1) return;  //abbiamo raggiunto l'ultimo elemento e completato l'ordinamento
    int m=find_min(v,n); //trovo il minimo e creo il buco
    v[0]=m; //sposto il minimo nel buco creato
    rec_selectionSort(v+1, n-1); //accorcio l'array e richiamo la funzione
}

void selectionSort(int *v, int n)
{
    for(int i=0; i<n-1; i++) //l'ultima iterazione e' inutile poiche fatta su un solo elemento
    {
        int m=find_min(v+i,n-1);
        v[i] = m;
    }
}

//ritorna l'indice del minimo nell'array v e sposta gli elementi
// shiftandoli a destra in modo da "coprire l'elemento minimo"
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

void swap(int *v, int i, int j)
{
    int tmp=v[j];
    v[j]=v[i];
    v[i]=tmp;
}

void insertionSort(int *v, int n)
{
    for(int i=1; i<n; i++)
    {
        int j=i-1;
        while(j>=0 && v[j]>v[j+1]) 
        {
            swap(v, j, j+1);
            j--;
        }

    }
}

void rec_insertionSort(int *v,int i, int n)
{
    if(i==n) return;
    int j = i-1;
    while(j>=0 && v[j]>v[j+1]) 
        {
            swap(v, j, j+1);
            j--;
        }
    rec_insertionSort(v, i+1, n);
}
void mySort(int *v, int n)
{
    if(n<=1) return; //un array con un elemento o meno e' gia' ordinato
    int j = n/2-1; //divido l'array a meta'
    mySort(v,j+1); //ordino meta' array, la parte sinistra contiene j+1 elementi
    mySort(v+j+1,n-j-1); //ordino meta' array 
    int *C=new int[n]; //istanzio un array dinamico da usare come appoggio visto che la funzione non lavora in loco
    natural_merge(v, j+1, v+j+1, n-j-1, C); //chiamo il natural merge
    for(int i=0; i<n; i++) v[i]=C[i]; //copio tutto dall'array C al mio array
}

void natural_merge(int *A, int n, int *B, int m, int *C)
{
    int i=0;
    int j=0;
    int k=0;
    while(i<n && j<m)
    {
        if(A[i]<B[j]) C[k++]=A[i++];
        else C[k++]=B[j++];
    }
    while(i<n) C[k++] = A[i++];
    while(j<m) C[k++] = B[j++];

}

void randomInit(int *v, int n)
{
    srand (time(NULL));
    for(int i=0;i<n;i++)
    {
        v[i]=rand() + 1;
    }
}