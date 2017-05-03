#include <cstdio>
#include <vector>
#define NMAX 100005
#define log 20
using namespace std;
FILE* fin = fopen("spiridusi.in","r");
FILE* fout = fopen("spiridusi.out","w");

int binsearch();
void df(int nod);

int N,C;
int s[NMAX], p[NMAX];
vector<int> G[NMAX];
int sol;
int dp[log][NMAX];
int st[log][NMAX];
int vf, nodes[NMAX],costs[NMAX],profits[NMAX],t[NMAX];


int main()
{
    fscanf(fin,"%d %d",&N,&C);
    int i;
    for(i=1;i<=N;i++)
        fscanf(fin,"%d",&s[i]);

    for(i=1;i<=N;i++)
        fscanf(fin,"%d",&p[i]);

    int a,b;
    for(i=1;i<N;i++)
        {
            fscanf(fin,"%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
    df(1);
    fprintf(fout,"%d\n",sol);

    return 0;
}

int binsearch()
{
    int st = 0, fi = vf, sol = vf;
    int m;
    while(st<=fi)
    {
        m = (st+fi)/2;
        if(costs[vf]-costs[m] <= C)
        {
            sol = m;
            fi = m-1;
        }
        else
            st = m+1;
    }
    return sol;
}

void df(int nod)
{
    nodes[++vf] = nod;
    costs[vf] = s[nod] + costs[vf-1];
    profits[vf] = p[nod] + profits[vf-1];

    int pozMinA = binsearch();

    st[0][nod] = nodes[vf-1];
    dp[0][nod] = profits[vf-1];

    int i;
    for(i=1; st[i-1][st[i-1][nod]] !=0; i++)
    {
        st[i][nod] = st[i-1][st[i-1][nod]];
        dp[i][nod] = min(dp[i-1][nod], dp[i-1][st[i-1][nod]]);
    }

    if(pozMinA != vf)
    {
        int p2 = 0;
        while((1<<(p2+1))<= vf - pozMinA)
            p2++;

        sol = max(sol, profits[vf] - min(dp[p2][nod],dp[p2][nodes[pozMinA+(1<<p2)]]));
    }

    int fiu;
    for(i = 0; i<G[nod].size(); i++)
    {
        fiu = G[nod][i];
        if(fiu == t[nod])
            continue;
        t[fiu] = nod;
        df(fiu);
    }
    --vf;
}

