#include <fstream>
#include <queue>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;
ifstream fin("bellmanford.in");
ofstream fout("bellmanford.out");

const int NMAX = 50005;
const int INF = 0x3f3f3f3f;

bitset<NMAX> inCoada;
queue<int> coada;
vector<int> lis[NMAX];
vector<int> cmin(NMAX, INF), frecvInCoada(NMAX, 0);
vector< pair<int,int> > cost[NMAX];

bool cicluNegativ = false;
int N,M;


void Citire();
void BellmanFord();
void Afisare();


int main()
{
    Citire();
    BellmanFord();
    Afisare();

    return 0;
}

void Citire()
{
    fin>>N>>M;

    int x,y,cst,i;
    for(i = 1; i <= M; i++)
    {
        fin>>x>>y>>cst;
        cost[x].push_back(make_pair(y,cst));
        lis[x].push_back(y);
    }
    fin.close();
}

void BellmanFord()
{
    coada.push(1);
    inCoada[1].flip();
    cmin[1] = 0;

    while (!coada.empty() && !cicluNegativ)
    {
        int x = coada.front();
        coada.pop();
        inCoada[x] = false;

        vector < pair <int, int> >::iterator it;
        for( it = cost[x].begin(); it != cost[x].end(); ++it)
            if(cmin[x] < INF && cmin[x] + it->second < cmin[it->first])
            {
                cmin[it->first] = cmin[x] + it->second;
                if(!inCoada[it->first])
                    if(frecvInCoada[it->first] > N)
                        cicluNegativ = true;
                    else
                    {
                        coada.push(it->first);
                        inCoada[it->first] = true;
                        frecvInCoada[it->first] ++;
                    }
            }
    }
}

void Afisare()
{
    int i;
    if (!cicluNegativ)
    {
        for (i = 2; i <= N; ++i)
            fout << cmin[i] <<" ";
    }
    else
        fout << "Ciclu negativ!";

    fout<<'\n';

    fout.close();
}
