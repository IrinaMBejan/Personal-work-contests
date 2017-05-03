#include <cstdio>
#include <vector>
using namespace std;

FILE* fin = fopen("chei.in","r");
FILE* fout = fopen("chei.out","w");

const int NMAX = 100005;
vector<int> G[NMAX];
int viz[NMAX];
int chei[NMAX];
int pre[NMAX];

void Citire();
void DFS(int x);
bool verifCiclu(int x, int s);

int M,rez;

int main()
{

    Citire();
    int i;
    int nr = 0;
    for(i = 1; i <= M; i++)
        if(viz[i] == 0 )
        {
            rez = 0;

            int z = i;

            chei[z] = 1;
            while(chei[pre[z]] == 0)
            {
                chei[pre[z]] = 1;
                z = pre[z];
            }

            nr++;

          //  fprintf(fout,"\n%d\n%d ", nr,z);

            DFS(z);
        }
    fprintf(fout,"%d\n",nr);
    return 0;
}

void Citire()
{
    int i, x;
    fscanf(fin,"%d",&M);

    for(i = 1; i <= M ; i++)
    {
        fscanf(fin,"%d",&x);
        G[x].push_back(i);
        pre[i] = x;
    }
}

void DFS(int x)
{
    int i;

    viz[x] = 1;
    for( i = 0; i < G[x].size(); i++)
        if( viz[G[x][i]] == 0 )
        {
          //  fprintf(fout,"%d ", G[x][i]);
            DFS(G[x][i]);
        }
    return;
}

