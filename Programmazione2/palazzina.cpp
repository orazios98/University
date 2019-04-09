#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

void print(int n, int *v)
{
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return;
}

int main()
{
	ifstream infile("input.txt");
	ofstream outfile("output.txt");
	string l;
	int N;
	while(getline(infile, l))
    {
        int tot=0;
		istringstream iss(l);
		iss >> N;
        int *pal=new int[N];
        int *salvi=new int[N];
        int cont_pal=N;
        int cont_salvi=0;
        for(int i=0;i<N;i++)
        {
            iss>>pal[i];
        }

        while(true)
        {
            if(cont_pal!=0)
            {
                cout<<"tot: "<<tot<<" pal: "<<cont_pal<<" salv: "<<cont_salvi<<endl;
                cout<<"-------PRIMO PASSO-------"<<endl;
                sort(pal, pal+cont_pal);
                salvi[cont_salvi]=pal[0];
                cont_salvi++;
                salvi[cont_salvi]=pal[1];
                cont_salvi++;
                tot+=pal[1];
                for(int i=2;i<cont_pal;i++)
                    pal[i-2]=pal[i];
                cont_pal=cont_pal-2;
                print(cont_pal,pal);
                print(cont_salvi, salvi);
                cout<<"-------FINE PRIMO PASSO---------"<<endl;
            } else { break; }
            if(cont_pal!=0)
            {
                cout<<"tot: "<<tot<<" pal: "<<cont_pal<<" salv: "<<cont_salvi<<endl;

                cout<<"-----INIZIO SECONDO PASSO----"<<endl;
                sort(salvi, salvi+cont_salvi);
                pal[cont_pal]=salvi[0];
                tot+=salvi[0];
                cont_pal++;
                for(int i=1;i<cont_salvi;i++)
                    salvi[i-1]=salvi[i];
                cont_salvi--;
                sort(pal, pal+cont_pal);
                sort(salvi, salvi+cont_salvi);
                print(cont_pal,pal);
                print(cont_salvi, salvi);
                cout<<"------FINE SECONDO PASSO-----"<<endl;
            } else { break; }
            if(cont_pal!=0)
            {
                 cout<<"tot: "<<tot<<" pal: "<<cont_pal<<" salv: "<<cont_salvi<<endl;
                cout<<"-----INIZIO TERZO PASSO----"<<endl;
                salvi[cont_salvi]=pal[cont_pal-2];
                cont_salvi++;
                salvi[cont_salvi]=pal[cont_pal-1];
                cont_salvi++;
                tot+=pal[cont_pal-1];
                cont_pal=cont_pal-2;
                sort(pal, pal+cont_pal);
                sort(salvi, salvi+cont_salvi);
                print(cont_pal,pal);
                print(cont_salvi, salvi);
                cout<<"-------FINE TERZO PASSO---------"<<endl;
            } else { break; }
            if(cont_pal!=0)
            {
                cout<<"tot: "<<tot<<" pal: "<<cont_pal<<" salv: "<<cont_salvi<<endl;
                cout<<"-------INIZIO QUARTO PASSO------"<<endl;

                pal[cont_pal]=salvi[0];
                tot+=salvi[0];
                cont_pal++;
                for(int i=1;i<cont_salvi;i++)
                    salvi[i-1]=salvi[i];
                cont_salvi--;
                sort(pal, pal+cont_pal);
                sort(salvi, salvi+cont_salvi);
                print(cont_pal,pal);
                print(cont_salvi, salvi);
                cout<<"------FINE QUARTO PASSO-----"<<endl;

                cout<<"tot: "<<tot<<" pal: "<<cont_pal<<" salv: "<<cont_salvi<<endl;
            } else { break; }
        }
        cout <<endl<<"ho finito il risultato è: "<<tot<<endl;
        outfile << tot<<endl;	    
	}
	return 0;
}