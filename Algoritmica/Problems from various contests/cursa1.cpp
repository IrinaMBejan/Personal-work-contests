#include <fstream>
#define NMAX 501
using namespace std;

ifstream fin("cursa1.in");
ofstream fout("cursa1.out");


struct ll
{
    int c;
    int d;
    int nr;
};
ll l[NMAX];
int n, nrd, d[NMAX];

int caut(int i)
{
    int poz;
    for (poz=1; l[poz].nr!=i; poz++);
    return poz;
}



int main()
{
    int i;
    fin>>n;
    for (i=1; i<=n; i++)
    {
        fin>>l[i].c>>l[i].d;
        l[i].nr=i;
    }
    for (i=n; i>1; i--)
        l[i].d-=l[i-1].d;

    int poz, pozmin;
    ll aux;
    for (poz=n; poz>1; poz--)
    {
        pozmin=1;
        for (i=2; i<=poz; i++)
            if (l[pozmin].d>l[i].d || l[pozmin].d==l[i].d && l[pozmin].c<l[i].c)
                pozmin=i;

        aux=l[pozmin];
        l[pozmin]=l[poz];
        l[poz]=aux;
    }
    for (i=1; i<n; i++) fout<<l[i].c<<' ';
    fout<<l[n].c<<'\n';
    int j;
    for (i=2; i<=n; i++)
    {
        poz=caut(i);
        nrd=0;
        for (j=n; j>0; j--)
            if (i>l[j].nr && l[poz].d>l[j].d)
            {
                nrd++;
                d[nrd]=j;
            }
        if (nrd)
        {
            fout<<i<<' '<<l[poz].c<<' '<<nrd;
            for (j=1; j<=nrd; j++) fout<<' '<<l[d[j]].c;
            fout<<'\n';
        }
    }
    return 0;
}
