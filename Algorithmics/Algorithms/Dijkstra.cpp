#include <fstream>
#define NMAX 1001
#define INF 99999999
using namespace std;

ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

int N,M;
int cmin[NMAX];
int pre[NMAX];
bool viz[NMAX];
int startVarf;
int mat[NMAX][NMAX];

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
    fin>>N>>M;

    for(i = 1; i <= M ; i++)
    {
        fin>>x>>y>>cost;
        mat[x][y] = cost;
    }
    fin>>startVarf;
}

void InitializareDijkstra()
{
    int i;
    for(i = 1; i <= N; i++)
    {
        cmin[i] = INF;
        pre[i] = startVarf;
    }

    cmin[startVarf] = 0;
    pre[startVarf] = 0;
    viz[startVarf] = 1;

    for( i = 1; i <= N; i++)
        if(mat[startVarf][i])
           {
               cmin[i] = mat[startVarf][i];
               pre[i] = startVarf;
           }
}

void Dijkstra()
{
    int minim, i, vfMinim;
    bool ok = 1;
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
            for( i = 1; i <= N; i++)
                if( mat[vfMinim][i] && mat[vfMinim][i] + cmin[vfMinim] < cmin[i])
                {
                    cmin[i] = mat[vfMinim][i] + cmin[vfMinim];
                    pre[i] = vfMinim;
                }
        }
        else ok = 0;
    }
}

void Afisare()
{
    int i;
    for(i = 1; i <= N; i++)
        if(i != startVarf)
        {
            if(cmin[i] < INF)
               {
                 fout<<"Cel mai scurt drum de la varful de start la "<<i<<" are costul:"<<cmin[i]<<'\n';
                 int varfCurent = i;
                 while(pre[varfCurent] != 0)
                 {
                     fout<<varfCurent<<" ";
                     varfCurent = pre[varfCurent];
                 }
                 fout<<'\n';
               }
            else
                fout<<"Nu exista drum"<<'\n';
        }
}
