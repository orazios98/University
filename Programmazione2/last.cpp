#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
bool **visited;
int **mat;
int N,M;
const char Free = '_';
const char End = 'U';
const char Start = 'E';


struct Point
{
	int x;
	int y;
};

Point source = {0, 0};
Point dest = {0, 0};


struct Nodo
{
	Point pt;
	int dist;
};


bool isValid(int row, int col)
{

	return (row >= 0) && (row < N) && (col >= 0) && (col < M);
}

int rowNum[] = {-1, 0, 0, 1, 1, 1, -1, -1, -2, 0, 2, 0};
int colNum[] = {0, -1, 1, 0, 1, -1, -1, 1, 0, 2, 0, -2};


int find(int **mat, Point src, Point dest)
{

	visited=new bool*[N];
    for(int i=0;i<N;i++)
        visited[i]=new bool[M];
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            visited[i][j]=false;

	visited[src.x][src.y] = true;
	queue<Nodo> q;

	Nodo s = {src, 0};
	q.push(s);

	while (!q.empty())
	{
		Nodo curr = q.front();
		Point pt = curr.pt;
		if (pt.x == dest.x && pt.y == dest.y)
			return curr.dist;
		q.pop();

		for (int i = 0; i < 12; i++)
		{
			int row = pt.x + rowNum[i];
			int col = pt.y + colNum[i];

			if (isValid(row, col) && mat[row][col] && !visited[row][col])
			{
				visited[row][col] = true;
				Nodo vicino = { {row, col}, curr.dist + 1 };
				q.push(vicino);
			}
		}
	}
	return -1;
}

int main()
{

    ifstream infile("t.txt");
    ofstream outfile("sarout.txt");
    string l;
    while(getline(infile, l))
    {
        istringstream iss(l);
        iss>>N>>M;
        mat=new int*[N];
        for(int i=0;i<N;i++)
            mat[i]=new int[M];
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                char t;
                iss>>t;
                if(t==Free || t==End || t==Start)
                {
                    mat[i][j]=1;
                    if(t==End)
                    {
                        dest.y=j;
                        dest.x=i;
                    }
                    if(t==Start)
                    {
                        source.y=j;
                        source.x=i;
                    }
                }
                else
                    mat[i][j]=0;
            }
        }

        //cout<<"start: "<<source.x<<" , "<<source.y<<endl;
        //cout<<"end: "<<dest.x<<" , "<<dest.y<<endl;

        int dist = find(mat, source, dest);

        if (dist>0)
        {
            //cout << "Dist" << dist <<endl;
            outfile<<dist<<endl;
        }
    }
	return 0;
}
