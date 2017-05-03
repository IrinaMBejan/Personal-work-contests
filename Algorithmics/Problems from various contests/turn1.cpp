#include <cstdio>
#include <vector>
#define NMAX 100005
using namespace std;
FILE* fin=fopen("turn1.in","r");
FILE* fout=fopen("turn1.out","w");

vector< int > G[NMAX];
int N, M;
bool viz[NMAX];
int C[NMAX];
int nr[NMAX];

void CitireListeAdiacenta();
void DFS(int x);

int max1, i1max, i2max, max2;
int current;
int main()
{

    CitireListeAdiacenta();

    int i;
    for(i=1; i<=N; i++)
        if( !viz[i] )
          {
              current = i;
              nr[i] = 1;
              DFS(i);
              if(nr[i]>max1) max1 = nr[i], i1max = i;
          }
    nr[i1max] = 0;
    for(i=1;i<=N;i++)
        if(nr[i]>max2 ) max2 = nr[i], i2max =i;

    if(i2max)
    fprintf(fout,"%d %d\n", i1max, i2max);
    else
    fprintf(fout,"%d %d\n", i1max, i1max);


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

void DFS(int x)
{
    int i;
    viz[x] = 1;
    for( i = 0; i < G[x].size(); i++)
         if( viz[G[x][i]] == 0 )
            {
                nr[current]++;
                DFS(G[x][i]);

            }
}

