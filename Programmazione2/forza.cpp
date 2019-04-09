#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>    // std::is_permutation
#include <cmath>

using namespace std;

int main()
{
	ifstream inf("input.txt");
    ofstream of("output.txt");
	string l;
	while(getline(inf, l))
    {
        int n,m;
		istringstream iss(l);
		iss >> n >>m;
        int tot=n+m;
        int *f=new int[tot];
        for(int i=0;i<tot;i++)
            iss>>f[i];
        sort(f,f+tot);
        for(int i=0;i<tot;i++)
            of<<f[i]<<" ";
        of<<endl;

	}
}


