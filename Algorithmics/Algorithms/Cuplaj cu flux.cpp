#include <cstdio>
#include <vector>
#include <cstring>
#define NMAX  10005
using namespace std;

FILE* fin = fopen("cuplaj.in","r");
FILE* fout = fopen("cuplaj.out","w");

vector <int> G[NMAX];
int u[NMAX], v[NMAX], viz[NMAX];
int N,M,E;
int cp;

int DFS(int n);
void Citire();
void CuplajHopcroftKarp();
void Afisare();

int main()
{
    Citire();
    CuplajHopcroftKarp();
    Afisare();
    return 0;
}

void CuplajHopcroftKarp()
{
    bool ok = 1;
    int i;
    while(ok)
    {
        ok = 0;
        memset(viz, 0, sizeof(viz));

        for(i=1;i<=N;i++)
            if (!u[i])
                ok |= DFS(i);
    }

    for(i=1;i<=N;i++)
        cp += (u[i] > 0);
}

void Afisare()
{
    fprintf(fout,"%d\n", cp);

    int i;
    for(i=1;i<=N;i++)
        if (u[i] > 0)
            fprintf(fout,"%d %d\n", i, u[i]);
}

void Citire()
{
    fscanf(fin,"%d %d %d", &N, &M, &E);

    int x, y;
    while(E--)
    {
        fscanf(fin,"%d %d", &x, &y);
        G[x].push_back(y);
    }
}


int DFS(int n)
{
    if (viz[n])  return 0;
    viz[n] = 1;
    for (int i = 0; i<G[n].size();i++)
        if (!v[G[n][i]])
        {
            u[n] = G[n][i];
            v[G[n][i]] = n;
            return 1;
        }

    for (int i = 0; i<G[n].size(); i++)
        if (DFS(v[G[n][i]]))
        {
            u[n] = G[n][i];
            v[G[n][i]] = n;
            return 1;
        }
    return 0;
}
