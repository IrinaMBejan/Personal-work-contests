#include <cstdio>
#include <vector>
#include<cstring>
#define NMAX 305
using namespace std;
FILE* fin=fopen("bile1.in","r");
FILE* fout=fopen("bile1.out","w");

vector< int > G[NMAX];
int N, M;
int gr[NMAX];
int grt[NMAX];
bool viz[NMAX];
int current;

void CitireListeAdiacenta();
void DFS(int x);

int main()
{

    CitireListeAdiacenta();

    int i, nr = 0;
    for( i = 1; i <= N; i++)
        {
            current = i;
            memset(viz,0, sizeof(viz));
            DFS(i);
        }
    for( i = 1; i <= N; i++)
        if(gr[i] >= (N+1)/2 || grt[i] >= (N+1)/2)
                nr++;

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
    }
}

void DFS(int x)
{
    int i;


    viz[x] = 1;

    for( i = 0; i < G[x].size(); i++)
         if( viz[G[x][i]] == 0 )
                {
                    gr[current]++;
                    grt[G[x][i]]++;
                    DFS(G[x][i]);
                }
}

