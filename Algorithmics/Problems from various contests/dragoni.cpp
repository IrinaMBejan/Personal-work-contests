#include <cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
#define Nmax 805
#define INF 0x3f3f3f3f
using namespace std;
FILE* fin = fopen("dragoni.in","r");
FILE* fout = fopen("dragoni.out","w");

int N,M,p;
int sol1, sol2;
bool viz[Nmax];
int dmax[Nmax];

vector< pair<int,int> > G[Nmax];
queue<pair<int,int> > Q;
bool q[Nmax][Nmax];
int dist[Nmax][Nmax]; //dist[i][j] = dist min obtinuta in insula i, ajungand cu dragonul j; dist[1][1] = 0 intial

void Citire();
void DFS(int nod);
void BellmanFord();

int main()
{
    Citire();

    if(p == 1)
        {
            sol1 = -1;
            DFS(1);
            fprintf(fout,"%d\n",sol1);
        }
    if(p == 2)
        {
            BellmanFord();
        }
    return 0;
}
void BellmanFord()
{
    int i,j;

    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
            dist[i][j] = INF;

    for(i=1;i<=N;i++)
        sort(G[i].begin(),G[i].end());
    Q.push(make_pair(1,1));
    q[1][1] = 1;
    dist[1][1] = 0;
    int sol = INF, insula, dragon, cost;
    while(!Q.empty())
    {
        insula = Q.front().first;
        dragon = Q.front().second;
        q[insula][dragon] = 0;
        cost = dist[insula][dragon];
        Q.pop();
        if(dmax[insula] > dmax[dragon])
            dragon = insula;
        for(i=0;i<G[insula].size() && dmax[dragon]>= G[insula][i].first; i++) //parcurg vecinii tangibili
        {
            //daca obtin o distanta mai proasta decat solutia
            //sau mai proasta decaat distanta pentru insula vecina cu dragonul curent
            //atunci renunt sa ma deplasez acolo
            if(cost + G[insula][i].first >= sol || cost + G[insula][i].first >= dist[G[insula][i].second][dragon])
                continue;
            //daca vecinul e destinatia updatez solutia
            if(G[insula][i].second == N)
            {
                sol = cost + G[insula][i].first;
                continue;
            }

            //altfel updatez distanta pentru vecin cu dragonul curent
            dist[G[insula][i].second][dragon] = cost + G[insula][i].first;

            //daca prerechea vecin,dragon nu e in coada o adaug
            if(!q[G[insula][i].second][dragon])
            {
                q[G[insula][i].second][dragon] = 1;
                Q.push(make_pair(G[insula][i].second,dragon));
            }
        }
    }
    fprintf(fout,"%d\n",sol);
}

void DFS(int nod)
{
    int i;
    viz[nod] = 1;
    if(sol1 < dmax[nod])
        sol1 = dmax[nod];
    for( i = 0; i < G[nod].size(); i++ )
        if(G[nod][i].first <= dmax[1] && viz[G[nod][i].second] == 0)
            DFS(G[nod][i].second);
}

void Citire()
{
    fscanf(fin,"%d",&p);
    fscanf(fin,"%d %d",&N,&M);
    int i;
    for(i=1;i<=N;i++)
        fscanf(fin,"%d",&dmax[i]);
    int a,b,c;
    for(i=1;i<=M;i++)
    {
        fscanf(fin,"%d %d %d",&a,&b,&c);
        G[a].push_back(make_pair(c,b));
        G[b].push_back(make_pair(c,a));
    }
}
