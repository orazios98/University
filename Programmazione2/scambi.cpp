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
        string s,t;
		istringstream iss(l);
		iss >> s >>t;
        int n1=s.length();
        int n2=t.length();
        int n3=n2-n1;
        for(int i=0;i<=n3; i++)
        {
            int count=0;
            string c=t.substr(i,n1);
            cout<<" la substr �: "<<c<<endl;
            for(int k=0;k<n1;k++)
            {
                    if(c[k]==s[k])
                    {
                        count++;
                        cout<<c[k]<<" � uguale a "<<s[k]<<endl;
                    } else if(c[k]==s[k+1] && c[k+1]==s[k])
                    {
                        count++;
                        count++;
                        k++;
                        cout<<c[k]<<" � uguale a "<<s[k]<<endl;
                    } else {
                        cout<<" ho trovato lettere diverse ";
                        break;
                    }


//                    if(c[k]==s[k] || (c[k]==s[k+1] && c[k+1]==s[k]) || (c[k]==s[k-1] && c[k-1]==s[k]))
//                    {
//                        count++;
//                        cout<<c[k]<<" � uguale a "<<s[k]<<endl;
//                    }
//                    else
//                    {
//                        cout<<" ho trovato lettere diverse ";
//                        break;
//                    }
            }
            if(count==n1)
            {
                cout<<" cont � "<<count<<endl;
                cout <<"- ------------------cosa importante: ---------- "<< i <<endl;
                of<<i<<" ";
            }
            cout<<"cambio substring"<<endl<<endl;
        }
        of<<endl;

	}
}


