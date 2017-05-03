#include <fstream>
#define NMAX 105
#define INF 2000
using namespace std;

ifstream fin("royfloyd.in");
ofstream fout("royfloyd.out");

int N;
int mat[NMAX][NMAX];
int mato[NMAX][NMAX];

void Citire();
void RoyFloyd();
void Afisare();

int main()
{

    Citire();
    RoyFloyd();
    Afisare();
    return 0;
}

void Citire()
{
    int i,j,x,y,t,M;
    fin>>N>>M;
    for(i=1; i<=N; i++)
        for(j=1; j<=N; j++)
            {
                mat[i][j] = INF; mato[i][j] = INF;
            }
    for(i=1; i<=M; i++)
    {
        fin>>x>>y>>t;
        mat[x][y] = t;
        mat[y][x] = t;
        mato[x][y] = mat[x][y];
        mato[y][x] = mat[y][x];
    }
    for(i = 1; i <= N; i++)
        mato[i][i] = 0;
}

void RoyFloyd()
{
    int z, x, y;
    for(z = 1; z <= N; z++)
        for(x = 1; x <= N; x++)
            for(y = 1; y <= N; y++)
                if(mato[x][y] > mato[x][z] + mato[z][y])
                {
                    mato[x][y] = mato[x][z] + mato[z][y];
                }
}

void Afisare()
{
    int i,j;
    for(i=1; i<=N; i++)
    {
        for(j=1; j<=N; j++)
            if(mato[i][j] == INF)
                fout<<"0 ";
            else
                fout<<mato[i][j]<<" ";
        fout<<'\n';
    }
}
