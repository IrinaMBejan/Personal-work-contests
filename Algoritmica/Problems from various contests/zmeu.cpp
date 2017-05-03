#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;
const int NMAX = 1005;
const int INF = 0x3f3f3f3f;

FILE* fin=fopen("zmeu.in","r");
ofstream fout("zmeu.out");

vector<int> iesiri;
int ff;
int fete[10];
int drum[NMAX][NMAX];
vector<pair<int,int> > adj[NMAX];
queue<int> coada;
bitset<NMAX> inCoada;
int N,M,P;
int timpMinim = INF;

int perm[10];
int viz[10];

void Citire();
void BellmanFordComplet(int k);
void Generare(int k);
void Afisare();

int main()
{
    Citire();
    int i,j;

    for(i=1 ;i<=N;i++)
    {
        for(j=1;j<=N;j++)
            drum[i][j] = INF;

    }

    for(i=1; i<= 5; i++)
        BellmanFordComplet(fete[i]);

    BellmanFordComplet(ff);

    Generare(1);
    Afisare();
    return 0;
}

void Citire()
{
    fscanf(fin,"%d %d %d %d",&N,&M,&P,&ff);
    int i,x,y,ti;

    for( i = 1; i <= 5; i++)
        fscanf(fin,"%d",&fete[i]);

    for( i = 1; i <= M; i++)
    {
        fscanf(fin,"%d %d %d",&x,&y,&ti);
        adj[x].push_back(make_pair(y,ti));
        adj[y].push_back(make_pair(x,ti));
    }

    for( i = 1; i <= P; i++)
    {
        fscanf(fin,"%d",&x);
        iesiri.push_back(x);
    }
}

void BellmanFordComplet(int k)
{
    inCoada.reset();
    coada.empty();

    coada.push(k);
    inCoada[k].flip();
    drum[k][k] = 0;

    while(!coada.empty())
    {
        int x = coada.front();
        coada.pop();
        inCoada[x].flip();

        vector<pair<int,int> >::iterator it;
        for(it = adj[x].begin(); it != adj[x].end(); ++it)
            if( drum[k][x] + it->second < drum[k][it->first])
            {
                drum[k][it->first] = drum[k][x] + it->second;
                if( !inCoada[it->first])
                {
                    coada.push(it->first);
                    inCoada[it->first] = true;
                }
            }
    }
}

void Generare(int k)
{
    if(k == 6 )
    {
        int i;
        int timpNecesar = drum[ff][fete[perm[1]]];

        if(timpNecesar == 0 || timpNecesar == INF) return;

        for(i = 2; i <= 5; i++)
        {
            timpNecesar += drum[fete[perm[i-1]]][fete[perm[i]]];
            if(timpNecesar == 0 || timpNecesar == INF) return;
        }
     //    int pmin;

        int timpIesireMinim = INF;
        for(i = 0; i < iesiri.size(); i++)
            if(timpIesireMinim > drum[fete[perm[5]]][iesiri[i]] && drum[fete[perm[5]]][iesiri[i]] != INF)
            {
                timpIesireMinim = drum[fete[perm[5]]][iesiri[i]];
             //   pmin = iesiri[i];
            }
        if(timpIesireMinim == INF) return;

        if(timpNecesar + timpIesireMinim < timpMinim)
        {
            timpMinim = timpNecesar + timpIesireMinim;
            /*for(i=1;i<=5;i++)
               {
                   fout<<fete[perm[i]]<<" ";
               }
               fout<<pmin<<'\n';*/
        }
    }
    else
    {
        int i;
        for(i = 1; i <= 5; i++)
            if(!viz[i])
            {
                perm[k] = i;
                viz[i] = 1;
                Generare(k+1);
                viz[i] = 0;
            }
    }
}

void Afisare()
{
    fout<<timpMinim<<'\n';
}
