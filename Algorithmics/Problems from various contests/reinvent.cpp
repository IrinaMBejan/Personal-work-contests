#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
FILE* fin = fopen("reinvent.in","r");
FILE* fout = fopen("reinvent.out","w");

const int NMAX = 100005;
const int INF = 0x3f3f3f3f;

vector<int> G[NMAX];
queue<int> cartier;
int dist[NMAX];
int src[NMAX];

void BFS();
void Citire();
int N,M,X;

int main()
{
    Citire();
    BFS();
    return 0;
}

void BFS()
{
    int i;
    int nod;
    while( !cartier.empty() )
    {
        nod = cartier.front();
        cartier.pop();

        for( i = 0; i < G[nod].size(); ++i)
        {
            if(src[G[nod][i]] == -1)
            {
                cartier.push(G[nod][i]);
                src[G[nod][i]] = src[nod];
                dist[G[nod][i]] = dist[nod]+1;
            }
            else if(src[G[nod][i]] != src[nod])
            {
                fprintf(fout,"%d\n", dist[G[nod][i]] + dist[nod] + 1);
                return;
            }
        }
    }
    return;
}


void Citire()
{
    fscanf(fin,"%d%d%d",&N,&M,&X);
    int x,y;
    for(;M; M--)
    {
        fscanf(fin,"%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }

    memset(src,-1,sizeof(src));
    for(;X; X--)
    {
        fscanf(fin,"%d", &x);
        cartier.push(x);
        src[x] = x;
    }
}
