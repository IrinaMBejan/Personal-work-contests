#include <cstdio>
#include <vector>

using namespace std;

#define maxn 1000010

int n, m, st0;
int d[maxn], fSon[maxn], sSon[maxn], val[maxn], lvl[maxn];
int a[maxn], b[maxn], sol[maxn], st[maxn], mp[maxn];
vector<int> v[maxn], q[maxn];

void df(int nod)
{
    ++lvl[nod];

    int fiu, b1=0, b2=0;

    d[nod]=val[nod];

    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];
        lvl[fiu]=lvl[nod];

        df(fiu);

        d[nod]=max(d[nod], d[fiu]);

        if(d[b1]<=d[fiu])
        {
            b2=b1;
            b1=fiu;
        }
        else
        if(d[b2]<=d[fiu])
            b2=fiu;
    }

    fSon[nod]=b1;
    sSon[nod]=b2;
}

void df2(int nod)
{
    int fiu, l, nq;

    ++st0;
    mp[st0]=max(mp[st0-1], val[nod]);

    for(int i=0; i<q[nod].size(); ++i)
    {
        nq=q[nod][i];
        l=lvl[a[nq]];

        sol[nq]=max(mp[l-1], max(st[st0-1], d[fSon[nod]]));
    }

    for(int i=0; i<v[nod].size(); ++i)
    {
        fiu=v[nod][i];

        if(fiu==fSon[nod])
            st[st0]=max(st[st0-1], d[sSon[nod]]);
        else
            st[st0]=max(st[st0-1], d[fSon[nod]]);

        df2(fiu);
    }

    --st0;
}

int main()
{
    freopen("arbvalmax.in", "r", stdin);
    freopen("arbvalmax.out", "w", stdout);

    scanf("%d%d", &n, &m);

    for(int i=2; i<=n; ++i)
    {
        int x;
        scanf("%d", &x);
        v[x].push_back(i);
    }

    for(int i=1; i<=n; ++i)
        scanf("%d", &val[i]);

    for(int i=1; i<=m; ++i)
    {
        scanf("%d%d", &a[i], &b[i]);
        q[b[i]].push_back(i);
    }

    df(1);
    df2(1);

    for(int i=1; i<=m; ++i)
        printf("%d\n", sol[i]);

    return 0;
}
