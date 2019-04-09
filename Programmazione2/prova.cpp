#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;


class Cofanetto
{
    public:
        int x,y,z;
        Cofanetto(int _x,int _y,int _z)
        {
            x=_x;
            y=_y;
            z=_z;
        }

        void print()
        {
            cout << " X:"<<x<<" Y:"<<y<<" Z:"<<z<<endl;
        }

        bool isMore(Cofanetto *c)
        {
            return ((x>c->x)&&(y>c->y)&&(z>c->z));
        }

        bool isLess(Cofanetto *c)
        {
            return ((x<c->x)&&(y<c->y)&&(z<c->z));
        }

        bool fit(Cofanetto *c)
        {
            return ((x<c->x)&&(y<c->y)&&(z<c->z));
        }

        bool isEqual(Cofanetto *c)
        {
            return ((x=c->x)&&(y=c->y)&&(z=c->z));
        }

};

vector <Cofanetto*> v;
vector <Cofanetto*> entra;
void printv();
int scorri(Cofanetto *t, int p, int ind);
void stampa_ins(Cofanetto *a, Cofanetto *b);
void solve(Cofanetto *c);


Cofanetto* cercamin()
{
    Cofanetto *temp=entra[0];
    int ind=-1;
    for(int i=0;i<entra.size();i++)
    {
        if(entra[i]->isLess(temp))
        {
            ind=i;
            temp=entra[i];
        }
    }
    return temp;
}
int indice=0;


int cercaindice(Cofanetto*c)
{
    for(int i=0;i<v.size();i++)
    {
        if(c->isEqual(v[i]))
            return i;
    }
    return -1;
}
int totale=1;
int main()
{
	ifstream infile("input.txt");
	ofstream outfile("output.txt");
	string l;
    int N,x,y,z;
    totale=1;
    int *tot=new int[100];
    int cont=0;
	while(getline(infile, l))
    {
        v.clear();
        entra.clear();
        totale=1;
        N=0;
		istringstream iss(l);
		iss >> N;
		cout<<"n: "<<N;
        for(int i=0;i<N;i++)
        {
            iss >> x >> y >> z;
            Cofanetto* temp=new Cofanetto(x,y,z);
            v.push_back(temp);
        }
        cout<<totale<<endl;
        for(int i=0;i<v.size();i++)
        {
            indice=i;
            solve(v[i]);
        }
        cout<<totale<<endl;
        outfile<<totale<<endl;
	}
	return 0;
}


void solve(Cofanetto *c)
{
    //printv();
    entra.clear();
    for(int i=0;i<v.size();i++)
    {
        if(c->isLess(v[i]))
        {
            entra.push_back(v[i]);
        }
    }
    if(entra.size()>0)
    {
        indice=cercaindice(c);
        totale=totale+1;
        if(entra.size()==1)
        {
            //stampa_ins(c, entra[0]);
            v.erase(v.begin() + indice);
            solve(entra[0]);
        }
        else
        {
            Cofanetto *t=cercamin();
            //stampa_ins(c, t);
            v.erase(v.begin() + indice);
            solve(t);
        }
    }
}

void stampa_ins(Cofanetto *a, Cofanetto *b)
{
    cout<<"metto ";
    a->print();
    cout<<" in ";
    b->print();
}

void printv()
{
    cout << "size: "<< v.size()<<endl;
        for(int i=0; i<v.size(); i++)
        {
            Cofanetto *t=v[i];
            t->print();
            //v[i]->print();
        }
}

