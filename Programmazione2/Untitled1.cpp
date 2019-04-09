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

};

vector <Cofanetto*> v;
void printv();
int scorri(Cofanetto *t, int p, int ind);

int main()
{
	ifstream infile("input.txt");
	ofstream outfile("output.txt");
	string l;
    int N,x,y,z;
	while(getline(infile, l))
    {
		istringstream iss(l);
		iss >> N;
        for(int i=0;i<N;i++)
        {
            iss >> x >> y >> z;
            Cofanetto* temp=new Cofanetto(x,y,z);
//          v.push_back(temp);
            int t=0,cont=0;
            int ind=0;
//          cout<<"prima while cont: "<<cont<<" t: "<<t<<"size:"<<v.size()<<endl;
            while(t<v.size())
            {
//                temp->print();
//                v[t]->print();
//                cout<<"dopo temp cont: "<<cont<<" t: "<<t<<"size:"<<v.size()<<endl;
                if(temp->isMore(v[t]))
                {
                    ind=t;
                    break;
                }
                t++;
            }
//            cout<<"prim insert cont: "<<cont<<" t: "<<t<<"size:"<<v.size()<<endl;
            temp->print();
                v.insert(v.begin()+ind, temp);
        }
        printv();
        for(int i=0;i<v.size();i++)
        {
            //cout<<"Guardo il "<<i<<"° elemento"<<endl;
            //scorri(v[i],1, i);
        }

		//outfile;

	}
	return 0;
}

int scorri(Cofanetto *t, int p, int ind)
{
    int contatore=p;
    cout<<"massimo: "<<contatore<<endl;
    for(int i=ind-1;i<v.size();i++)
    {
        cout<<"massimo: "<<contatore<<endl;
        if(t->fit(v[i]))
        {
            contatore++;
            cout <<" metto ";
            t->print();
            cout<<" in ";
            v[i]->print();
            cout<<" __ ";
            cout<<"massimo: "<<contatore<<endl;
            scorri(v[i],contatore, ind);
        } else {
            cout<<"massimo: "<<contatore<<endl;
            p=0;
        }
    }
    cout<<"massimo: "<<contatore<<endl;
    return contatore;
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

