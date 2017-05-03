#include <cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
#define NMAX 105

using namespace std;

FILE* fin = fopen("pm.in","r");
FILE* fout = fopen("pm.out","w");

vector<int> G[NMAX],Gt[NMAX];
queue<int> Q;
bool inC[NMAX];
int gi[NMAX], ge[NMAX];
int earliest[NMAX], latest[NMAX];
int t[NMAX];
int niv[NMAX];
int N;

int comp1(int a, int b)
{
    return niv[a] <= niv[b];
}

int comp2(int a, int b)
{
    return niv[a] >= niv[b];
}
void BFS1(int nod)
{
    int i;
    Q.push(nod);
    while(!Q.empty())
    {
        nod = Q.front();
        Q.pop();
        for(i=0;i<G[nod].size();i++)
        {
            if(inC[G[nod][i]])
            {
                earliest[G[nod][i]] = max(earliest[G[nod][i]],t[nod]+earliest[nod]);
            }
            else
            {
                Q.push(G[nod][i]);
                earliest[G[nod][i]] = t[nod]+earliest[nod];
                inC[G[nod][i]] = 1;
                fprintf(fout,"%d ",G[nod][i]);
            }
        }
        fprintf(fout,"\n");
    }
}


void BFS2(int nod)
{
    int i;
    Q.push(nod);
    while(!Q.empty())
    {
        nod = Q.front();
        Q.pop();
        for(i=0;i<Gt[nod].size();i++)
        {
            if(inC[Gt[nod][i]])
            {
                latest[Gt[nod][i]] = min(latest[Gt[nod][i]],latest[nod] - t[Gt[nod][i]]);
            }
            else
            {
                Q.push(Gt[nod][i]);
                latest[Gt[nod][i]] = latest[nod] - t[Gt[nod][i]];
                inC[Gt[nod][i]] = 1;
            }
        }
    }
}

int main()
{
    fscanf(fin,"%d",&N);
    int i,q,j,m;
    for(i=1;i<=N;i++)
        fscanf(fin,"%d",&t[i]);
    for(i=1;i<=N;i++)
    {
        fscanf(fin,"%d",&m);
        for(j=1;j<=m;j++)
        {
            fscanf(fin,"%d",&q);
            G[q].push_back(i);
            gi[i]++; ge[q]++;
            Gt[i].push_back(q);
        }
    }

    t[0] = 0; t[N+1] = 0;
    for(i=1; i<=N;i++)
    {
        if(gi[i] == 0)
        {
            G[0].push_back(i);
            Gt[i].push_back(0);
        }
        if(ge[i] == 0)
        {
            G[i].push_back(N+1);
            Gt[N+1].push_back(i);

        }
    }

    bool ok = 1;
    int ni = 1;
    if(N!=0)
    while(ok)
    {
        ok = 0;
        for(i=1;i<=N && !ok;i++)
            if(gi[i] == 0 && niv[i] == 0)
            {
                for(j = 0; j<G[i].size(); j++)
                    gi[G[i][j]]--;
                niv[i] = ni;
                ok = 1;
            }
        ni++;
    }


    for(i=1;i<=N;i++)
    {
        sort(G[i].begin(), G[i].end(), comp1);
        sort(Gt[i].begin(), Gt[i].end(), comp2);
    }

    BFS1(0);
    latest[N+1] = earliest[N+1];
    memset(inC, 0, sizeof(inC));
    BFS2(N+1);

    fprintf(fout,"%d\n",earliest[N+1]);
    for(i=1;i<=N;i++)
        fprintf(fout,"%d %d\n",earliest[i],latest[i]);

    return 0;
}
