#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;
int mossa=0;
int count=0;
ofstream of("output.txt");
void hanoi(int n, char A, char B, char C)
{
    
    //A = sorgente
    //B = destinazione
    //C = appoggio
    if(n==1)
    {
        count++;
        cout<<"Sono nella mossa n°: "<<count<<"\t";
        cout<< " Sorg: " << A << " Dest: " << B<<" App: "<<C<<endl;
        if(count==mossa)
        {
            of << A <<" "<<B<<"\n";
        }
        return;
    }
    hanoi(n-1, A,C,B);
    hanoi(1,A,B,C);
    hanoi(n-1,C,B,A);
}

int main()
{
	ifstream inf("input.txt");
	string l;
    int N,m;
	while(getline(inf, l))
    {
        count=0;
		istringstream iss(l);
		iss >> N >> mossa;
        cout <<"m:"<<mossa<<endl;
        char A = '1';
        char B = '3';
        char C = '2';
        hanoi(N,A,B,C);
	}
	return 0;
}