#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;


class Cofanetto
{
    private:
        int x,y,z;
    public:
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

};

int main()
{
	ifstream infile("input.txt");
	ofstream outfile("output.txt");
	string l;
    int N,x,y,z;
	while(getline(infile, l))
    {
        int cont=0;
		istringstream iss(l);
		iss >> N;
        Cofanetto **vett;
        vett = new Cofanetto *[N];
        vector <Cofanetto> v(N);
        for(int i=0;i<N;i++)
        {
            iss >> x >> y >> z;
            Cofanetto* temp=new Cofanetto(x,y,z);
            v.push_back(temp);
            int t=0;
            while(t<)
            //     if(temp->maggiore(vett[t]))
            //         t++;
            vett[t]=temp;
            cont++;
        }
        for(int i=0; i<N; i++)
        {
            vett[i]->print();
        }
		//outfile;
        v.clear;
	}
	return 0;
}