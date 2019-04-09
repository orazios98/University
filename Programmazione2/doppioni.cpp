#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	ifstream inf("input.txt");
    ofstream of("output.txt");
	string l;
    int N;
	while(getline(inf, l))
    {
        int doppioni=0;
        int prec;
        int count=0;
        bool find;
		istringstream iss(l);
		iss >> N;
        int *fum=new int[N];
        for(int i=0;i<N;i++)
        {
            iss>>fum[i];
        }
        sort(fum,fum+N);
        for(int i=0;i<N-1;i++)
        {
            if(fum[i]==fum[i+1])
            {
                doppioni++;
            }
        }
        of<<doppioni<<endl;
	}
	return 0;
}
