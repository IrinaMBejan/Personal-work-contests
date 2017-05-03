#include <fstream>

using namespace std;
ifstream fin("matriosca.in");
ofstream fout("matriosca.out");

struct matriosca
{
    int h;
    int nr;
    int w[1500];
} a[2502];

int main()
{
    int q,n,i,ok,p,j;
    p=0;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>q;
        ok=0;
        for(j=1; j<=p&&!ok; j++)
            if(q<a[j].h)
            {
                a[j].w[++a[j].nr]=i;
                a[j].h=q;
                ok=1;
            }
        if(ok==0)
        {
            a[++p].w[++a[j].nr]=i;
            a[j].h=q;
        }
    }
    fout<<p<<'\n';
    for(i=1; i<=p; i++)
    {
        fout<<a[i].nr<<" ";
        for(j=1; j<=a[i].nr; j++)
            fout<<a[i].w[j]<<" ";
        fout<<'\n';
    }
        return 0;
    }
