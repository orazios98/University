#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream infile("input.txt");
	ofstream outfile("output.txt");
	string l;
	int N;
    float f,max,tmp;
	while(getline(infile, l))
    {
		istringstream iss(l);
		iss >> N;
        float *prezzi=new float[N];
        for(int i=0;i<N;i++)
        {
            iss >> tmp;
            prezzi[i]=tmp;
        }
        max=0;
		for(int i=N-1;i>=1;i--)
        {
            for(int j=i-1;j>=0;j--)
            {
                float t=prezzi[i]-prezzi[j];
                if(t>0)
                {
                    if(t>max)
                    {
                        max=t;
                    }
                        
                }
            }
        }
	    outfile <<setprecision(4) << max << "\n";
	}
	return 0;
}