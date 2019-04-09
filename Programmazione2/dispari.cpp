#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main()
{
	ifstream infile("input.txt");
	ofstream outfile("output.txt");
	string l;
	int N;
	while(getline(infile, l))
    {
		istringstream iss(l);  
		iss >> N;
        for(int i=0;i<N;i++)
        {
            int t=0;
            iss>>t;
            if(t%2!=0)
                outfile<<t<<" ";
        }
		outfile<<endl;
	}
	return 0;
}