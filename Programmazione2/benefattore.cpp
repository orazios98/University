#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void BubbleSort(float *array, int N)
 {
   int massimo;
   for (massimo = N - 1; massimo > 0; massimo-- )
     { 
         for (int i=0; i<massimo; i++)
         {
           if (array[i]>array[i+1])
           { 
             float temp = array[i]; 
             array[i] = array[i+1]; 
             array[i+1] = temp;
           } 
         }
     }
 }

int main()
{
	ifstream infile("input.txt");
	ofstream outfile("output.txt");
	string l;
	int N;
    float peso_max,temp,peso_att;
	while(getline(infile, l))
    {
		istringstream iss(l);
		iss >> peso_max >> N;
        float *pesi=new float[N];
        for(int i=0;i<N;i++)
        {
            iss >> temp;
            pesi[i]=temp;
        }
        BubbleSort(pesi,N);
        peso_att=0;
        int count=0;
        while(peso_att<peso_max)
        {
            float t=peso_att+pesi[count];
            if(t<peso_max)
            {
                peso_att+=pesi[count];
                count++;
            }
            else
                break;
        }
        cout<<"max: "<<peso_max<<" att:"<<peso_att<<endl;
		outfile <<count <<" "<<setprecision(3) << peso_att << "\n";
	}
	return 0;
}