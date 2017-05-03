#include <fstream>
#define NMax 200001
using namespace std;
ifstream fin("maxp.in");
ofstream fout("maxp.out");

struct stivaa
{
    int val;
    int poz;
}stiva[NMax];

int a[NMax],st[NMax],dr[NMax];
int main()
{
    int n,i,j,q,x,y,put,putmax=0,nr;
    fin>>n;
    for(i=1;i<=n;i++)
        fin>>a[i];
    stiva[0].val=1000000;
    stiva[0].poz=0;
    int k=0;
    for(i=1;i<=n;i++)
    {
        if(a[i]<=stiva[k].val)
        {
            st[i]=i-stiva[k].poz-1;
            stiva[++k].val=a[i];
            stiva[k].poz=i;
        }
        else
        {
            while(a[i]>stiva[k].val)
                k--;
            st[i]=i-stiva[k].poz-1;
            stiva[++k].val=a[i];
            stiva[k].poz=i;
        }
    }
    k=0;
     stiva[0].poz=n+1;
    for(i=n;i>=1;i--)
    {
        if(a[i]<=stiva[k].val)
        {
            dr[i]=stiva[k].poz-i-1;
            stiva[++k].val=a[i];
            stiva[k].poz=i;
        }
        else
        {
            while(a[i]>stiva[k].val)
                k--;
            dr[i]=stiva[k].poz-i-1;
            stiva[++k].val=a[i];
            stiva[k].poz=i;
        }
    }
    for(i=1;i<=n;i++)
    {
        put=(st[i]+1)*(dr[i]+1);
        if(put>putmax) {putmax=put; nr=1;}
        else if(put==putmax) nr++;
    }

    fout<<putmax<<'\n'<<nr<<'\n';
    return 0;
}
