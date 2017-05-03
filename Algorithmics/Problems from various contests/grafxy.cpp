#include <cstdio>
#include <vector>
#include <cstring>
#define NMAX 100005

using namespace std;

FILE* fin=fopen("grafxy.in","r");
FILE* fout=fopen("grafxy.out","w");

void CitireListeAdiacenta();
void BFS();

int N, M, start;
vector <int> G[NMAX];
int viz[NMAX];
int C[NMAX];
int X[NMAX];
int Y[NMAX];
int nX, nY;

int main()
{
    int i;

    CitireListeAdiacenta();
    fscanf(fin,"%d",&nX);
    for( i=1; i<=nX; i++)
        fscanf(fin,"%d",&X[i]);

    fscanf(fin,"%d",&nY);
    for( i=1; i<=nY; i++)
        fscanf(fin,"%d",&Y[i]);

    memset(viz, -1, sizeof(viz));
    BFS();

    for( i=1; i<=nX;i++)
    {
        fprintf(fout,"%d\n",viz[X[i]]);
    }

    return 0;
}

void CitireListeAdiacenta()
{
    int i, x, y;
    fscanf(fin,"%d %d",&N,&M);

    for(i = 1; i <= M ; i++)
    {
        fscanf(fin,"%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
}

void BFS()
{
    int i, st, fi, nod;

    st = 0;  fi = 0;
    for( i=1; i<=nY; i++)
    {
        viz[Y[i]] = 0;
        C[fi++] = Y[i];
    }

    while( fi-st >= 0 )
    {
        nod = C[ st++ ];
        for( i = 0; i < G[nod].size(); i++)
            if( viz[ G[nod][i] ] == -1)
            {
                viz[G[nod][i]] = 1+viz[nod];
                C[ ++fi ] = G[nod][i];
            }
    }
}
