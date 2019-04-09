#include <iostream>
#include <fstream>
#include <time.h>
#include <string.h>
using namespace std;


void natural_merge(int *A, int n, int *B, int m, int *C)
{
    int i,j,k;
    i = j = k = 0;
    while(i<n && j<m)
    {
        if(A[i]<B[j]) C[k]=A[i++];
        else C[k++]=B[j++];
    }
    while(i<n) C[k++] = A[j++];
    while(j<m) C[k++] = B[j++];

}

int main()
{
    int A[]={3,7,9,10,15,16,17,23};
    int B[]={1,2,12,13,14};
    int n=8;
    int m=5;
    int C[13];
}