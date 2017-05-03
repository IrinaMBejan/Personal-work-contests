#include <cstdio>
#include <vector>
#include <stack>
#include <utility>
using namespace std;
const int NMAX = 100005;
FILE* fin = fopen("biconex.in","r");
FILE* fout = fopen("biconex.out","w");

int low[NMAX],dfn[NMAX];
vector<int> G[NMAX];
vector<int> sol[NMAX];
stack<pair<int, int> > stiva;
int nro;
int N,M,q;

void DFS(int x, int tx);
void Citire();
void Afisare();

int main()
{
    Citire();
    int i;
    for(i=1; i<=N;i++)
        if(dfn[i] == -1)
            DFS(i,0);
    Afisare();
    return 0;
}

void Citire()
{
    fscanf(fin,"%d %d",&N,&M);
    int x,y;
    while(M--)
    {
        fscanf(fin,"%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    int i;
    for(i = 1; i<=N; i++)
        dfn[i] = -1;
}

void Afisare()
{
    int i,j;
    fprintf(fout,"%d\n", q);
    for(i = 1; i <= q; i++)
    {
        for(j = sol[i].size()-1; j>=0; j--)
            fprintf(fout,"%d ",sol[i][j]);
        fprintf(fout,"\n");
    }
}

void DFS(int x, int tx)
{
    int i;
    nro++;
    low[x] = dfn[x] = nro;
    bool pct = 0;
    for(i = 0; i<G[x].size(); i++)
        if(G[x][i] != tx)
        {
            if(dfn[G[x][i]]== -1)
            {
                stiva.push(make_pair(G[x][i],x));
                DFS(G[x][i], x);

                low[x] = min(low[x],low[G[x][i]]);

                if(low[G[x][i]] >= dfn[x])
                {
                    int cx, ctx;
                    q++;
                    do
                    {
                        ctx = stiva.top().second;
                        cx = stiva.top().first;
                        stiva.pop();
                        sol[q].push_back(cx);
                    }
                    while(ctx != x || cx!= G[x][i]);
                    sol[q].push_back(ctx);
                }
            }
            else
            {
                 low[x] = min(low[x], dfn[G[x][i]]);
            }
        }
}
