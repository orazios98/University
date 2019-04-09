#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>

using namespace std;


int main()
{
	ifstream infile("input.txt");
	ofstream outfile("output.txt");
	string l;
    int N;
    string s;
	while(getline(infile, l))
    {
		istringstream iss(l);
		iss >> N >> s;
        for(int i=0;i<N;i++)
        {
            char c=s[i];
            c=c-3;
            if(c<97)
                c+=26;
            outfile<<c;
        }
        outfile<<endl;
	}
	return 0;
}