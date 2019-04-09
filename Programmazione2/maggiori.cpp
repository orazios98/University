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
        int x=0;
        int cont=0;
		istringstream iss(l);  
		iss >> N >> x;
        int *num=new int[N];
        for(int i=0;i<N;i++)
        {
            int p;
            iss>>p;
            if(p>x)
            {
                num[cont]=p;
                cont++;
            }
                
        }
        outfile<<cont<<" ";
        for(int i=0;i<cont;i++)
        {
            outfile<<num[i]<<" ";
        }
		outfile<<endl;
	}
	return 0;
}