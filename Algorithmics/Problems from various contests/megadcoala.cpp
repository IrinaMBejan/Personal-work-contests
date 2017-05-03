#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;
const int NMAX = 105;
const int INF = 0x3f3f3f3f;

ifstream fin("megascoala.in");
ofstream fout("megascoala.out");

int drum[NMAX][NMAX];
vector<pair<int,int> > adj[NMAX];
queue<int> coada;
bitset<NMAX> inCoada;
int N;
int timpMinim = INF;

void Citire();
void BellmanFordComplet(int k);
void Rezolva();
void Afisare();

int main()
{
    Citire();
    int i,j;

    for(i=1 ; i<=N; i++)
    {
        for(j=1; j<=N; j++)
            drum[i][j] = INF;
    }

    for(i=1; i<= N; i++)
        BellmanFordComplet(i);
    Rezolva();
    Afisare();
    return 0;
}

void Citire()
{
    fin>>N;
    int i,j,x;
    for(i=1; i<=N; i++)
        for(j=1; j<=N; j++)
        {
            fin>>x;
            if(x != 0)
            {
                adj[i].push_back(make_pair(j,x));
                adj[j].push_back(make_pair(i,x));
            }
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

int scoala1, scoala2;
void Rezolva()
{
    int ti1, ti2, i, j;
    for(i=1; i<=N; i++)
        for(j=1; j<=N; j++)
            if(i!=j)
            {
                ti1 = 0;
                ti2 = 0;
                for(int k = 1; k<=N; k++)
                    if(k!= i && k!= j)
                    {
                        if(drum[i][k] <= drum[j][k])
                        {
                            if(ti1 < drum[i][k])
                            {
                                ti1 = drum[i][k];
                            }
                        }
                        else
                        {
                            if(ti2 < drum[j][k])
                            {
                                ti2 = drum[j][k];
                            }
                        }
                    }

                int timp = max(ti2,ti1);
                if(timp < timpMinim)
                {
                    timpMinim = timp;
                    scoala1 = i;
                    scoala2 = j;
                }

            }
}
void Afisare()
{
    fout<<scoala1<<" "<<scoala2<<" "<<timpMinim<<'\n';
}
