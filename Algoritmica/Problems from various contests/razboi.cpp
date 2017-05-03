#include <cstdio>
#include <fstream>
#include <vector>
#include <bitset>
using namespace std;
FILE* fin = fopen("razboi.in","r");
ofstream fout("razboi.out");

const int NMAX = 505;
const int INF = 0x3f3f3f3f;


vector< pair<int,int> > adj[NMAX*NMAX];
vector<int> cmin(NMAX, INF);
vector<int> pre(NMAX, 0);
vector<int> best(NMAX,0);
bitset<NMAX> viz;
int N,M;
int orasTinta;

void Citire();
void InitializareDijkstra(int orasTinta);
void Dijkstra(int orasTinta);
void Afisare();

int main()
{
    Citire();
    int i,j;
    for( i = 1; i <= N; i++)
    {
        InitializareDijkstra(i);
        Dijkstra(i);


        for(j = 1; j <= N; j++)
            {
                fout<<cmin[j]<<" ";
                if(cmin[j] > best[j])
                best[j] = cmin[j];
            }
                fout<<'\n';

    }
    Afisare();
    return 0;
}

void Citire()
{
    fscanf(fin,"%d %d",&N,&M);
    int i;
    int x,y,timp;
    for( i=1; i <= M; i++)
    {
        fscanf(fin,"%d %d %d",&x,&y, &timp);
        adj[x].push_back(make_pair(y,timp));
    }
    fscanf(fin,"%d",&orasTinta);
    fclose(fin);
}


void InitializareDijkstra(int orasTinta)
{
    int i;
    for( i = 1; i <= N; ++i)
    {
        cmin[i] = INF;
        pre[i] = orasTinta;
    }
    viz.reset();
    cmin[orasTinta] = 0;
    pre[orasTinta] = 0;
    viz[orasTinta].flip();

    vector<pair<int,int> >::iterator it;
    for(it = adj[orasTinta].begin(); it != adj[orasTinta].end(); ++it)
    {
        pre[it->first] = orasTinta;
        cmin[it->first] = it->second;
    }


}


void Dijkstra(int orasTinta)
{
    int minim, i, vfMinim;
    int ok = true;

    while(ok)
    {
        minim = INF;

        for(i = 1; i <= N; i++)
            if(!viz[i] && cmin[i] < minim)
            {
                minim = cmin[i];
                vfMinim = i;
            }
        if(minim != INF)
        {
            viz[vfMinim] = true;

            vector<pair<int,int> >::iterator it;
            for(it = adj[vfMinim].begin(); it!= adj[vfMinim].end(); ++it)
                if( it->second + cmin[vfMinim] < cmin[it->first])
                {
                    cmin[it->first] = it->second + cmin[vfMinim];
                    pre[it->first] = vfMinim;
                }

        }
        else ok = false;
    }

}


void Afisare()
{
    if(best[orasTinta] != INF)
        fout<<best[orasTinta]<<'\n';
    else
        fout<<"0"<<'\n';

    int timpRet = INF, orasRet, i;

    for( i = 1; i <= N; i++)
        if(best[i] < timpRet)
    {
        timpRet = best[i];
        orasRet = i;
    }

    if(timpRet != INF)
        fout<<orasRet<<" "<<timpRet<<'\n';
    else
        fout<<"0"<<'\n';

    fout.close();
}
