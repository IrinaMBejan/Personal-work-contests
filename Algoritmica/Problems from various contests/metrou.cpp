#include <cstdio>
#include <vector>
#include <utility>
#define Nmax 201000
using namespace std;
FILE* fin = fopen("metrou.in","r");
FILE* fout = fopen("metrou.out","w");

int n,m, nsp;
int sp[Nmax],who[Nmax],f[Nmax];
vector<int> G[Nmax],Gn[Nmax];
int g[Nmax], g2[Nmax], p[Nmax],lant[Nmax];

int dp[Nmax][2];
int nl;
struct lant
{
    int d[2][2];
    int c1, c2;
} l[Nmax];

int conflict[31][31];

void newChain(int i);
int solve();
int solveCiclu();
int solveLant();
pair< pair<int,int> , pair<int, int> > getChainResult(int a[]);



int main()
{
    fscanf(fin,"%d %d",&n,&m);
    int i;
    for(i=1;i<=n;i++)
        fscanf(fin,"%d",&p[i]);
    int a,b;
    for(i=1;i<=m;i++)
    {
        fscanf(fin,"%d %d",&a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
        ++g[a];
        ++g[b];
    }

    fprintf(fout,"%d",solve());
    return 0;
}

int solve()
{
    int ok1 = 0, ok3 = 0;

    int i;
    for(i=1;i<=n;i++)
    {
        if(g[i]>2)
        {
            ok3 = 1;
            sp[nsp++] = i;
            who[i] = nsp;
        }
        if(g[i]<2)
            ok1 = 1;
    }

    if(ok1 == 0 && ok3 == 0)
        return solveCiclu();
    if(ok3 == 0)
        return solveLant();

    for(i=1;i<=n;i++)
    {
        if(g[i]>2)
            continue;
        for(int j = 0; j<G[i].size();j++)
            if(g[G[i][j]]<=2)
        {
            Gn[i].push_back(G[i][j]);
            ++g2[i];

        }
    }

    for(i=1;i<=n;i++)
    {
        if(g[i]>2 || f[i] == 1 || g2[i] >1)
            continue;
        newChain(i);
    }

    for(int i=0; i<nsp; ++i)
    {
        int nod=sp[i];
        for(int j=0; j<G[nod].size(); ++j)
            conflict[i+1][who[G[nod][j]]]=1;
    }

    int sol=0;

    for(int i=0; i<(1<<nsp); ++i)
    {
        int ok=1;
        for(int j=0; j<nsp; ++j)
            for(int k=0; k<nsp; ++k)
                if(conflict[j+1][k+1] && ((i>>j)&1)==1 && ((i>>k)&1)==1)
                    ok=0;

        if(!ok)
            continue;

        int rez=0;

        for(int j=0; j<nsp; ++j)
            if((i>>j)&1)
                rez+=p[sp[j]];

        for(int j=1; j<=nl; ++j)
        {
            int c1=l[j].c1-1;
            int c2=l[j].c2-1;
            rez+=l[j].d[(i>>c1)&1][(i>>c2)&1];
        }

        if(rez>sol)
            sol=rez;

    }

    return sol;
}

void newChain(int i)
{
    ++nl;
    if(g2[i] == 0)
    {
        l[nl].c1 = who[G[i][0]];

        if(g[i]>1)
            l[nl].c2 = who[G[i][0]];
        else
            l[nl].c2 = nsp+1;

        l[nl].d[0][0] = p[i];
        return;
    }

    l[nl].c1 = nsp+1;
    int j;
    for(j= 0; j<G[i].size(); ++j)
        if(g[G[i][j]]>2)
            l[nl].c1 = who[G[i][j]];

    lant[0] = 0;
    lant[++lant[0]] = i;
    int x = Gn[i][0];
    lant[++lant[0]] = x;
    f[i] = f[x] = 1;

    while(g2[x] == 2)
    {
        if(f[Gn[x][0]] == 1)
            x = Gn[x][1];
        else
            x = Gn[x][0];
        f[x] = 1;
        lant[++lant[0]] = x;
    }

    l[nl].c2 = nsp+1;
    for(j = 0; j<G[x].size(); j++)
        if(g[G[x][j]]>2)
            l[nl].c2 = who[G[x][j]];

    pair<pair<int, int> , pair<int, int> > rez = getChainResult(lant);

    l[nl].d[0][0] = rez.first.first;
    l[nl].d[0][1]=rez.first.second;
    l[nl].d[1][0]=rez.second.first;
    l[nl].d[1][1]=rez.second.second;

}
pair< pair<int,int> , pair<int, int> > getChainResult(int a[])
{
    dp[0][0] = dp[0][1] = 0;
    dp[1][0] = p[a[1]];
    dp[1][1] = 0;

    int lg = a[0];

    int i,j;
    for(i=2;i<lg;i++)
    {
        for(j = 0;j<2;j++)
            dp[i][j] = max(dp[i-2][j] + p[a[i]], dp[i-1][j]);
    }

    return make_pair(make_pair(dp[lg][0], dp[lg-1][0]),make_pair(dp[lg][1], dp[lg-1][1]));
}

int solveCiclu()
{
    int x = 1;

    while(f[x] == 0)
    {
        f[x] = 1;
        lant[++lant[0]] = x;
        if(f[G[x][0]] == 1)
            x = G[x][1];
        else
            x = G[x][0];
    }

    pair< pair<int,int>, pair<int, int> > rez = getChainResult(lant);
    return max(rez.first.second,max(rez.second.second,rez.second.first));
}

int solveLant()
{
    int x = 1;
    int i;
    for(i=1;i<=n;i++)
        if(g[i] == 1)
            x = i;

    while(f[x] == 0)
    {
        f[x] = 1;
        lant[++lant[0]] = x;

        for(i=0;i<G[x].size();i++)
            if(f[G[x][i]]==0)
            {
                x = G[x][i];
                break;
            }
    }

    pair< pair<int,int> , pair<int, int> > rez = getChainResult(lant);
    return max(max(rez.first.first,rez.first.second),max(rez.second.first,rez.second.second));
}
