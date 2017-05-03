#include <fstream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
const int nmax = 7501;
ifstream fin("graf.in");
ofstream fout("graf.out");



vector<int> G[nmax];
int dx[nmax],dy[nmax],num[nmax],vertex[nmax],poz[nmax];
queue<int> Q;
int n,m,x,y;

void bfs (int x, int d[nmax])
{
    int i,nod;
    Q.push(x);
    while(!Q.empty())
    {
        nod = Q.front();
        Q.pop();
        for(i=0; i<G[nod].size(); i++)
        {
            if(d[G[nod][i]] == 0)
            {
                Q.push(G[nod][i]);
                d[G[nod][i]] = d[nod]+1;
            }
        }
    }
}

int main()
{
    fin>>n>>m>>x>>y;

    int i,xx,yy;
    for (i=1; i<=m; i++)
    {
        fin>>xx>>yy;
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }
    dx[x] = 1;
    dy[y] = 1;
    bfs(x, dx);
    bfs(y, dy);

    for (i=1; i<=n; i++)
        if (dx[i] + dy[i] == dx[y] + 1)
        {
            num[dx[i]]++;
            vertex[dx[i]] = i;
        }

    int nr = 0;
    for (i=1; i<=n; i++)
        if (num[i]==1)
        {
            nr++;
            poz[vertex[i]]=1;
        }

    fout<<nr<<'\n';
    for (i=1; i<=n; i++)
        if (poz[i]==1)
            fout<<i<<' ';
}
