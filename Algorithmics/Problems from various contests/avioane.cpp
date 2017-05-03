#include <cstdio>
#include <vector>
#include <map>
#include <bitset>
#include <queue>
#include <utility>
#include <algorithm>
#define NMAX 30005
#define MMAX 90005
using namespace std;
FILE* fin =fopen("avioane.in","r");
FILE* fout = fopen("avioane.out","w");


const int INF = 0x3f3f3f3f;

bitset<NMAX> inCoada;
queue<int> coada;
vector<int> lis[NMAX];
vector<int> cmin(NMAX, INF), frecvInCoada(NMAX, 0);

int sol[NMAX];
vector< pair<int, int> > G[2*MMAX];
struct nod
{
    int timp;
    int ar;
    int cost;
};
map<nod, int> W;
map<int, nod> Wp;
vector<int> R[NMAX];


int N,M,K;
void BellmanFord();
int main()
{
    fscanf(fin,"%d %d %d",&N,&M,&K);
    int i,nrn;
    nod plecare, aterizare;
    plecare.timp = 0;
    plecare.ar = 1;
    Wp.insert(pair<int,nod>(1,plecare));
   //W[plecare] = 1;
    R[1].push_back(1);

    return 0;
}



void BellmanFord()
{
    coada.push(1);
    inCoada[1].flip();
    cmin[1] = 0;

    while (!coada.empty())
    {
        int x = coada.front();
        coada.pop();
        inCoada[x] = false;

        vector < pair <int, int> >::iterator it;
        for( it = G[x].begin(); it != G[x].end(); ++it)
            if(cmin[x] < INF && cmin[x] + it->second < cmin[it->first])
            {
                cmin[it->first] = cmin[x] + it->second;
                if(!inCoada[it->first])
                {
                     coada.push(it->first);
                     inCoada[it->first] = true;
                     frecvInCoada[it->first]++;
                }
            }
    }
}
