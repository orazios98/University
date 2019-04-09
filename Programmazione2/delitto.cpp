#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>

using namespace std;



int endmatch(int **campo)
{
    if((campo[0][0]!=0)&&(campo[0][0]==campo[0][1])&&(campo[0][0]==campo[0][2]))
        return campo[0][0];
    else if((campo[1][0]!=0)&&(campo[1][0]==campo[1][1])&&(campo[1][0]==campo[1][2]))
        return campo[1][0];
    else if((campo[2][0]!=0)&&(campo[2][0]==campo[2][1])&&(campo[2][0]==campo[2][2]))
        return campo[2][0];
    else if((campo[0][0]!=0)&&(campo[0][0]==campo[1][0])&&(campo[0][0]==campo[2][0]))
        return campo[0][0];
    else if((campo[0][1]!=0)&&(campo[0][1]==campo[1][1])&&(campo[0][1]==campo[2][1]))
        return campo[0][1];
    else if((campo[0][2]!=0)&&(campo[0][2]==campo[1][2])&&(campo[0][2]==campo[2][2]))
        return campo[0][2];
    else if((campo[0][0]!=0)&&(campo[0][0]==campo[1][1])&&(campo[0][0]==campo[2][2]))
        return campo[0][0];
    else if((campo[0][2]!=0)&&(campo[0][2]==campo[1][1])&&(campo[0][2]==campo[2][0]))
        return campo[0][2];
    return -1;
}

void azzeracampo(int **v)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            v[i][j]=0;
        }
    }
}

void stampacampo(int **v)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

void segna(int **v, int a, int b, int c)
{
    v[a][b]=c;
}

int main()
{
	ifstream inf("input.txt");
    ofstream of("output.txt");
	string l;
    int count=0;
    int numpartite;
    int **campo;
    campo = new int*[3];
        for(int i=0; i<3; i++)
        {
            campo[i]=new int[3];
        }
	while(getline(inf, l))
    {
		istringstream iss(l);
        cout<<"sono all riga numero "<<count<<endl;
        count++;
		iss >> numpartite;
        int punt1=0;
        int punt2=0;   
        
        string mossa="";
        for(int p=0;p<numpartite;p++)
        {
            bool pari=true;
            cout<<endl<<"HO INIZIATO LA PARTITA "<<p<<endl;
            azzeracampo(campo);
            int contamosse=0;
            while(((endmatch(campo))<0)&&(contamosse<9)){
                mossa="NULL";
                iss>>mossa;
                if(mossa!="NULL")
                {
                    contamosse++;
                    int a=mossa[1] - '0';
                    int b=mossa[3] - '0';
                    int c;
                    if(pari)
                        c=1;   
                    else
                        c=2;
                    pari = !pari;
                    segna(campo,a,b,c);
                    stampacampo(campo);
                    if((endmatch(campo))==1)
                        punt1++;
                    else if((endmatch(campo))==2)
                        punt2++;
                    cout<<endmatch(campo);
                    cout<<endl;
                }  
            };

        }
        cout <<endl<<"punteggio a: "<<punt1<<" punteggio b:"<<punt2<<endl;
        
        cout<<endl;
        of<<punt1<<" "<<punt2<<endl;
	}
	return 0;
}