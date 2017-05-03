#include <cstdio>
#include <vector>
#define NMAX 100005
using namespace std;
FILE* fin=fopen("graf.in","r");
FILE* fout=fopen("graf.out","w");

vector< int > G[NMAX];
int N, M;
bool viz[NMAX];
int C[NMAX];
int nr;

void CitireListeAdiacenta();
void DFSRecListaAdiacenta(int x);
void BFSRecListaAdiacenta(int x);
void DFSCoadaListaAdiacenta(int x);

int main()
{

    CitireListeAdiacenta();

    int i;
    for(i=1; i<=N; i++)
        if( !viz[i] )
            {
                DFSCoadaListaAdiacenta(i);
                fprintf(fout,"\n");
                nr++;
            }

    fprintf(fout,"%d\n",nr);
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

void DFSRecListaAdiacenta(int x)
{
    int i;

    viz[x] = 1;
    fprintf(fout,"%d\n",x);
    for( i = 0; i < G[x].size(); i++)
         if( viz[G[x][i]] == 0 )
                DFSRecListaAdiacenta(G[x][i]);
}

void DFSCoadaListaAdiacenta(int x)
{
    int st=1, fi=1;
    int i;

    C[st] = x; viz[x] = 1;
    fprintf(fout,"%d ",x);


    while( fi-st >= 0 )
    {
        x = C[st++];

        for( i = 0; i < G[x].size(); i++)
            if( viz[G[x][i]] == 0 )
            {
                C[ ++fi ] = G[x][i];
                fprintf(fout,"%d ",G[x][i]);
                viz[G[x][i]] = 1;
            }
    }
}

