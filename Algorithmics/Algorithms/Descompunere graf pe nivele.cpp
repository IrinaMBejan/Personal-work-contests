#include <fstream>
#include <vector>
#include<cstring>
using namespace std;
ifstream fin("desc.in");
ofstream fout("desc.out");

const int NMAX = 1005;
vector<int> G[NMAX];
int N,M;
int gr[NMAX];
int niv[NMAX];
bool lastc[NMAX];

void Citire();
void Descomp();

int main()
{
    Citire();
    Descomp();
    int i;
    for(i=1 ;i <=N; i++)
        fout<<i<<" cu gradul "<<niv[i]<<'\n';
    return 0;
}

void Citire()
{
    fin>>N>>M;
    int i;
    int x,y;
    for(i=1 ; i<=M; i++)
    {
        fin>>x>>y;
        G[x].push_back(y);
        gr[y]++;
    }
}

void Descomp()
{
    int i,j;
    bool ok = true;
    int nv = 0;
    while(ok)
    {
        ok = false;
        nv++;
        memset(lastc,0,sizeof(lastc));

        for(i = 1; i <= N; i++)
            if(gr[i] == 0 && lastc[i] == 0)
            {
                niv[i] = nv;
                for(j = 0; j < G[i].size(); j++)
                        {
                            gr[G[i][j]]--;
                            lastc[G[i][j]]= 1;
                        }

                gr[i] = -1;
                ok = true;
            }
    }
}
