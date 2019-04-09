#include <iostream>
#include <fstream>
#include <time.h>
#include <string.h>
using namespace std;


int main()
{
    clock_t inizio, fine;
    int j=0;
    inizio=clock();
    for(int i=0;i<100000000;i++) {}
    fine=clock();
    float n_clock=fine-inizio;
    cout <<n_clock<<endl;
}