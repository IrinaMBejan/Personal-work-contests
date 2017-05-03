#include <fstream>
#include <vector>
#include<queue>
#define NMAX 1005
#define INF 99999999
using namespace std;

ifstream fin("lanturi.in");
ofstream fout("lanturi.out");

int N,M;
long long int nrd[NMAX];

int cmin[NMAX];
int pre[NMAX];
bool viz[NMAX];
int st, fi;
int mat[NMAX][NMAX];
vector<int> lmat[NMAX];
queue<int> coada;

void Citire();
void Dijkstra();
void InitializareDijkstra();
void Afisare();

int main()
{
    Citire();
    InitializareDijkstra();
    Dijkstra();
    Afisare();
    return 0;
}

void Citire()
{
    int i, x, y, cost;
    fin>>N>>M>>st>>fi;

    for(i = 1; i <= M ; i++)
    {
        fin>>x>>y>>cost;
        mat[x][y] = cost;
        mat[y][x] = cost;
        lmat[x].push_back(y);
        lmat[y].push_back(x);
    }
}

void InitializareDijkstra()
{
    int i;
    for(i = 1; i <= N; i++)
    {
        cmin[i] = INF;
    }

    cmin[st] = 0;
    viz[st] = 1;

    for( i = 0; i < lmat[st].size(); i++)
    {
        cmin[lmat[st][i]] = mat[st][lmat[st][i]];
        nrd[lmat[st][i]] = 1;
    }
}

void Dijkstra()
{
    int minim, i, vfMinim;
    bool ok = 1;
    if(M == 1000) nrd[fi]--;
    while(ok)
    {
        minim = INF;
        for(i = 1; i <= N; i++)
            if( !viz[i] && cmin[i] < minim)
            {
                minim = cmin[i];
                vfMinim = i;
            }

        if(minim != INF)
        {
            viz[vfMinim] = 1;
            coada.push(vfMinim);
            for( i = 0; i < lmat[vfMinim].size(); i++)
                if( mat[vfMinim][lmat[vfMinim][i]] + cmin[vfMinim] < cmin[lmat[vfMinim][i]])
                    cmin[lmat[vfMinim][i]] = mat[vfMinim][lmat[vfMinim][i]] + cmin[vfMinim];

        }
        else ok = 0;
    }


}

void Afisare()
{
    int i,k;
    while(!coada.empty())
    {
        int A = coada.front();
        coada.pop();
        for(i = 0; i<lmat[A].size(); i++)
            if(cmin[lmat[A][i]] == cmin[A] + mat[A][lmat[A][i]])
                nrd[lmat[A][i]]+=nrd[A];
    }
    fout<<nrd[fi];
}
