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
bool DFSCiclu(int x, int s);

int main()
{

    CitireListeAdiacenta();

    bool aciclic = true;

    int i;
    for(i=1; i<=N; i++)
        if( !viz[i] )
                if(DFSCiclu(i,0)) aciclic = false;


    if(aciclic)
        fprintf(fout,"Este acilic\n");
    else
        fprintf(fout,"Nu este aciclic\n");


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

bool DFSCiclu(int x, int s)
{
    int i;
    viz[x] = 1;
    for( i = 0; i < G[x].size(); i++)
         if( viz[G[x][i]] == 0 )
            rez = rez || DFSCiclu(G[x][i],x);
         else
         {
             if( s != G[x][i] )
                rez = 1;
         }
    return rez;
}


