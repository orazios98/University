#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>



using namespace std;
bool dx1(int x, int y);
bool dx2(int x, int y);
bool sx1(int x, int y);
bool sx2(int x, int y);
bool up1(int x, int y);
bool up2(int x, int y);
bool down1(int x, int y);
bool down2(int x, int y);
bool dupsx(int x, int y);
bool dupdx(int x, int y);


void print(int n, int m, char **v);
void print(int n, int m, bool **v);
bool solve(int x, int y);
char **griglia;
bool **passato;
int N,M;
int e_x, e_y,u_x,u_y,a_x,a_y;
const char Free = '_';
const char End = 'U';
const char io = '*';
int contatore;

int main()
{
    ifstream infile("inputb.txt");
    ofstream outfile("output.txt");
    string l;
    while(getline(infile, l))
    {
        istringstream iss(l);
        iss >> N;
        iss >> M;
        contatore=0;
        griglia = new char*[N];
        for(int i=0; i<N; i++)
            griglia[i] = new char[M];
        passato = new bool*[N];
        for(int i=0; i<N; i++)
            passato[i] = new bool[M];
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                passato[i][j]=true;

        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                iss>>griglia[i][j];

        for(int i=0; i<N; i++)
        {
            for(int j=0; j<M; j++)
            {
                if(griglia[i][j]=='E')
                {
                    e_x=j;
                    e_y=i;
                    griglia[i][j]=1
                }
                else if(griglia[i][j]=='U')
                {
                    u_x=j;
                    u_y=i;
                }
            }
        }



        //cout<<endl<<endl;
    }
    return 0;
}

void print(int n, int m, char **v)
{
    cout<<"---------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<"  |";
        cout<<endl;
    }
    cout<<"---------------------"<<endl;
    return;
}

void print(int n, int m, bool **v)
{
    cout<<"---------------------"<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<"  |";
        cout<<endl;
    }
    cout<<"---------------------"<<endl;
    return;
}

bool solve(int x, int y)
{
    passato[y][x]=false;
    if(x==u_x && y==u_y)
        return true;
    if (x>1 && griglia[y][x-2] == End && solve(x-2,y))
    {
        contatore++;
        return true;
    }
    if (x>0 && griglia[y][x-1] == End && solve(x-1,y))
    {
        contatore++;
        return true;
    }
    if (x<M-2 && griglia[y][x+2]==End && solve(x+2,y))
    {
        contatore++;
        return true;
    }
    if (x<M-1 && griglia[y][x+1]==End && solve(x+1,y))
    {
        contatore++;
        return true;
    }
    if (y>1 && griglia[y-2][x]==End && solve(x,y-2))
    {
        contatore++;
        return true;
    }
    if (y>0 && griglia[y-1][x]==End && solve(x,y-1))
    {
        contatore++;
        return true;
    }
    if (y<N-2 && griglia[y+2][x]==End && solve(x,y+2))
    {
        contatore++;
        return true;
    }
    if (y<N-1 && griglia[y+1][x]==End && solve(x,y+1))
    {
        contatore++;
        return true;
    }
    if(y>0 && x>0 && griglia[y-1][x-1]==End && solve(x-1,y-1))
    {
        contatore++;
        return true;
    }
    if(y<N-1 && x>0 && griglia[y+1][x-1]==End && solve(x-1,y+1))
    {
        contatore++;
        return true;
    }
    if(y<N-1 && x<M-1 && griglia[y+1][x+1]==End && solve(x+1,y+1))
    {
        contatore++;
        return true;
    }
    if(y>0 && x<M-1 && griglia[y-1][x+1]==End && solve(x+1,y-1))
    {
        contatore++;
        return true;
    }

    //caso 0
    if(x>=u_x && y>=u_y)
    {
        //dietro2
        if (x>1 && griglia[y][x-2]==Free && passato[y][x-2]==true && solve(x-2,y))
        {
            contatore++;
            //cout<<"tot: "<<contatore<<endl;
            return true;
        }

        //sopra2
        if (y>1 && griglia[y-2][x]==Free && passato[y-2][x]==true && solve(x,y-2))
        {
            contatore++;
            //cout<<"tot: "<<contatore<<endl;
            return true;
        }

        //diag sopra sx
        if(y>0 && x>0 && griglia[y-1][x-1]==Free && passato[y-1][x-1]==true && solve(x-1,y-1))
        {
            contatore++;
            //cout<<"tot: "<<contatore<<endl;
            return true;
        }

        //dietro1
        if (x>0 && griglia[y][x-1] == Free && passato[y][x-1] ==true && solve(x-1,y))
        {
            contatore++;
            //cout<<"tot: "<<contatore<<endl;
            return true;
        }

        //sopra1
        if (y>0 && griglia[y-1][x]==Free && passato[y-1][x]==true && solve(x,y-1))
        {
            contatore++;
            //cout<<"tot: "<<contatore<<endl;
            return true;
        }

        //diag sopra dx
        if(y>0 && x<M-1 && griglia[y-1][x+1]==Free && passato[y-1][x+1]==true && solve(x+1,y-1))
        {
            contatore++;
            //cout<<"tot: "<<contatore<<endl;
            return true;
        }

        //avanti1
        if (x<M-1 && griglia[y][x+1]==Free && passato[y][x+1]==true && solve(x+1,y))
        {
            contatore++;
            //cout<<"tot: "<<contatore<<endl;
            return true;
        }

        //avanti2
        if (x<M-2 && griglia[y][x+2]==Free && passato[y][x+2]==true && solve(x+2,y))
        {
            contatore++;
            //cout<<"tot: "<<contatore<<endl;
            return true;
        }

        //diag sotto sx
        if(y<N-1 && x>0 && griglia[y+1][x-1]==Free && passato[y+1][x-1]==true && solve(x-1,y+1))
        {
            contatore++;
            //cout<<"tot: "<<contatore<<endl;
            return true;
        }

        //sotto1
        if (y<N-1 && griglia[y+1][x]==Free && passato[y+1][x]==true && solve(x,y+1))
        {
            contatore++;
            //cout<<"tot: "<<contatore<<endl;
            return true;
        }

        //diag sotto dx
        if(y<N-1 && x<M-1 && griglia[y+1][x+1]==Free && passato[y+1][x+1]==true && solve(x+1,y+1))
        {
            contatore++;
            //cout<<"tot: "<<contatore<<endl;
            return true;
        }

        //sotto2
        if (y<N-2 && griglia[y+2][x]==Free && passato[y+2][x]==true && solve(x,y+2))
        {
            contatore++;
            //cout<<"tot: "<<contatore<<endl;
            return true;
        }
      
    }
    
    griglia[y][x]=Free;
    //print(N,M,griglia);
    return false;
}
