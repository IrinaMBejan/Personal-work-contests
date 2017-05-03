#include <fstream>
#include <queue>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;
ifstream fin("trmv.in");
ofstream fout("trmv.out");

const int NMAX = 1000005;
const int INF = 0x3f3f3f3f;

bitset<NMAX> inCoada;
queue<int> coada;
vector<int> cmin(NMAX, INF);
vector< pair<int,int> > cost[NMAX];
vector<int> tinte;

int N,T,S,P;


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
    fin>>N>>T>>S>>P;

    int x,y,cst,k,j,i;
    for(i = 1; i <= T; i++)
    {
        fin>>k;
        fin>>x;
        for(j = 1; j < k ; j++)
        {
            fin>>cst>>y;
            cost[x].push_back(make_pair(y,cst));
            cost[y].push_back(make_pair(x,cst));
            x = y;
        }
    }
    for(i = 1; i <= P; i++)
    {
        fin>>x;
        tinte.push_back(x);
    }
    fin.close();
}

void BellmanFord()
{
    coada.push(S);
    inCoada[S].flip();
    cmin[S] = 0;

    while (!coada.empty())
    {
        int x = coada.front();
        coada.pop();
        inCoada[x] = false;

        vector < pair <int, int> >::iterator it;
        for( it = cost[x].begin(); it != cost[x].end(); ++it)
            if(cmin[x] + it->second < cmin[it->first])
            {
                cmin[it->first] = cmin[x] + it->second;
                if(!inCoada[it->first])
                    {
                        coada.push(it->first);
                        inCoada[it->first] = true;
                    }
            }
    }
}

void Afisare()
{
    int i;

    for(i = 0; i < tinte.size(); i++)
        if(cmin[tinte[i]] != INF)
            fout<<cmin[tinte[i]]<<" ";
        else fout<<"-1 ";
    fout<<'\n';

    fout.close();
}
