#include <cstdio>
#include <vector>
#include <cstring>
#include<queue>
#define NMAX 100005
using namespace std;
FILE* fin = fopen("arborexyz.in","r");
FILE* fout = fopen("arborexyz.out","w");

struct muchie
{
    int st,dr;
} sol1,sol2;
int N,T;
vector<int> G[NMAX];
int lg[NMAX];
bool viz[NMAX],inC[NMAX];
int c[4];
queue<int> Q;
int nod1, nod2, max1 = -1,max2 = -1;

void DFS1(int x);
void DFS2(int x);
void BFS(int x, int val, muchie &sol);
void solveTest();

int main()
{
    fscanf(fin,"%d",&T);
    int a,b;
    while(T--)
    {
        fscanf(fin,"%d %d %d %d",&N,&c[1],&c[2],&c[3]);
        int i;
        for(i=1; i<N; i++)
        {
            fscanf(fin,"%d %d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        lg[1] = 1;
        DFS1(1);
        memset(lg,0,sizeof(lg));
        lg[nod1] = 1;
        DFS2(nod1);

        solveTest();

        for(i=1;i<=N;i++)
            G[i].clear();
        memset(lg,0,sizeof(lg));
    }
    return 0;
}

void solveTest()
{
    int i,j;
    for(i=1; i<=3; i++)
        for(j=1; j<=3; j++)
        {
            memset(viz,0,sizeof(viz));
            memset(inC,0,sizeof(inC));
            BFS(nod1, c[i], sol1);
            memset(inC,0,sizeof(inC));
            BFS(nod2, c[j], sol2);
            int rest = N - c[i] - c[j];
            for(int k =1; k<=N; k++)
                if(viz[k] == 0)
                    rest--;
            if(rest == 0)
            {
             //   fprintf(fout,"%d %d    %d %d\n",sol1.st, sol1.dr, sol2.st, sol2.dr);
                fprintf(fout,"1\n");
                return;
            }
        }
    fprintf(fout,"0\n");
    return;
}
void DFS1(int x)
{
    int i;

    for(i=0; i<G[x].size(); i++)
        if(!lg[G[x][i]])
        {
            lg[G[x][i]] = lg[x] + 1;
            if(lg[G[x][i]] > max1)
            {
                max1 = lg[G[x][i]];
                nod1 = G[x][i];
            }
            DFS1(G[x][i]);
        }
}

void DFS2(int x)
{
    int i;

    for(i=0; i<G[x].size(); i++)
        if(!lg[G[x][i]])
        {
            lg[G[x][i]] = lg[x] + 1;
            if(lg[G[x][i]] > max2)
            {
                max2 = lg[G[x][i]];
                nod2 = G[x][i];
            }
            DFS2(G[x][i]);
        }
}

void BFS(int x,int val, muchie& sol)
{
    Q.push(x);
    int contor = 1;
    int nod,i;
    bool ok = false;
    while(!Q.empty())
    {
        nod = Q.front();
        Q.pop();
        viz[nod] = 1;


        for(i=0; i<G[nod].size(); i++)
            if(!viz[i] && !inC[G[nod][i]])
            {
                if(!ok && contor<val)
                {
                    inC[G[nod][i]] = 1;
                    Q.push(G[nod][i]);
                    contor++;
                    if(contor == val)
                    {
                        ok = 1;
                        sol.st = nod;
                    }
                }
                else
                {
                    sol.dr = G[nod][i];
                    return;
                }
            }
    }

}
