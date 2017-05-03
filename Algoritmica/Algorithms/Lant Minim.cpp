#include <cstdio>
#include <vector>
#define NMAX 100005

using namespace std;

FILE* fin=fopen("graf.in","r");
FILE* fout=fopen("graf.out","w");

void CitireListeAdiacenta();
void BFS(int nod);
void FaDrum(int nod);
void Afisare();

int N, M, start;
vector <int> G[NMAX];
int viz[NMAX];
int C[NMAX];
int drum[NMAX];
int lgdrum;

int main()
{
    CitireListeAdiacenta();
    fscanf(fin,"%d",&start);

    BFS(start);

    Afisare();

    return 0;
}

void Afisare()
{
    int i,j;
    for( i = 1; i <= N; i++)
        if( viz[i] == 0)
            fprintf( fout, "%d: Nu exista lant\n",i);
        else if(viz[i] != -1)
        {
            FaDrum(i);
            fprintf( fout,"%d: ",i);
            for( j = lgdrum; j >= 1 ; j--)
                fprintf (fout, "%d ", drum[j]);
            fprintf(fout,"\n");
        }
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

void BFS(int nod)
{
    int i, st, fi;

    viz[nod] = -1;
    st = fi = 1; C[st] = nod;

    while( fi-st >= 0 )
    {
        nod = C[ st++ ];
        for( i = 0; i < G[nod].size(); i++)
            if( !viz[ G[nod][i] ] )
            {
                viz[G[nod][i]] = nod;
                C[ ++fi ] = G[nod][i];
            }
    }
}

void FaDrum(int nod)
{
    lgdrum = 0;
    while(viz[nod] != -1)
    {
        drum[ ++lgdrum ] = viz[nod];
        nod = viz[nod];
    }
}
