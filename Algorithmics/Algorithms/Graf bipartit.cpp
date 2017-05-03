#include <cstdio>
#include <vector>
#define NMAX 100005

using namespace std;

FILE* fin=fopen("graf.in","r");
FILE* fout=fopen("graf.out","w");

void CitireListeAdiacenta();
int BFS(int nod);

int N, M;
vector <int> G[NMAX];
int viz[NMAX];
int C[NMAX];

int main()
{
    CitireListeAdiacenta();

    bool rez = 0;
    int i;
    for( i = 1; i <= N; i++)
        if( viz[i] == 0)
            rez = rez || BFS(i);

    if( rez == true)
        fprintf(fout,"Graful nu este bipartit\n");
    else
        fprintf(fout,"Graful este bipartit\n");

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

int BFS(int nod)
{
    int i, st, fi;

    viz[nod] = 1;
    st = fi = 1; C[st] = nod;

    while( fi-st >= 0 )
    {
        nod = C[ st++ ];
        for( i = 0; i < G[nod].size(); i++)
            if( !viz[ G[nod][i] ] )
            {
                viz[G[nod][i]] = 3 - viz[nod];
                C[ ++fi ] = G[nod][i];
            }
            else
            {
                if( viz[G[nod][i]] == viz[nod] )
                    return 1;
            }
    }
    return 0;
}

