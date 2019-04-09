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
    int M;
	while(getline(inf, l))
    {
        int cont=0;
		istringstream iss(l);
		iss >> N;
		iss >> M;
        int *poss=new int[N];
        int *rich=new int[M];
        for(int i=0;i<N;i++)
        {
            iss>>poss[i];
        }
        for(int i=0;i<M;i++)
        {
            iss>>rich[i];
        }
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(rich[i]==poss[j])
                {
                    cont += 5;
                    break;
                }
            }
        }
        of<<cont<<endl;
	}
	return 0;
}
