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
        float t=0;
		istringstream iss(l);  
		iss >> N;
        for(int i=0;i<N;i++)
        {
            float p=0;
            cout<<"t: "<<t<<"p: "<<p<<endl;
            iss>>p;
            t=t+p;
        }
		outfile<<t<<endl;
	}
	return 0;
}