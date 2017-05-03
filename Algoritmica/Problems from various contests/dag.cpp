#include <cstdio>
#include <list>
#include <vector>
#include<cstring>
using namespace std;
FILE* fin=fopen("dag.in","r");
FILE* fout=fopen("dag.out","w");

const int NMAX = 100005;
vector<int> G[NMAX];
int gr[NMAX];


int grMax;

list<int> niv[NMAX];
bool elim[NMAX];

int n,m;
void Citire();
void Solutie();
void Afisare();

int main()
{
    Citire();

    Solutie();
    Afisare();
    return 0;
}

void Citire()
{
    fscanf(fin,"%d%d",&n,&m);
    int i;
    int x,y;
    for(i=1; i<=m; i++)
    {
        fscanf(fin,"%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
        gr[x]++;
        gr[y]++;
    }

    for(i=1; i<=n; i++)
        niv[gr[i]].push_back(i);
}

void Solutie()
{
    int i,j,nod,ok;
    grMax = 0;
    for(i = 1; i <= n; ++i)
    {
        ok = 0;
        list<int>::iterator it;
        for(it = niv[i].begin(); it != niv[i].end(); ++it )
        {
            nod = *it;
            if(elim[nod] == 0)
            {
                grMax = max(grMax,gr[nod]);
                for(j = 0; j < G[nod].size(); ++j )
                {
                    niv[gr[G[nod][j]]].remove(G[nod][j]);
                    gr[G[nod][j]]--;
                    niv[gr[G[nod][j]]].push_back(G[nod][j]);
                }
                elim[nod] = 1;
                ok = 1;
            }
        }
        if(ok) i = 0;
    }
}
void Afisare()
{
    fprintf(fout,"%d\n",grMax);
}
