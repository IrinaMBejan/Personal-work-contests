#include <cstdio>
#define NMAX 100001

using namespace std;
FILE* fin=fopen("schi1.in","r");
FILE *fout=fopen("schi1.out","w");

struct concurent
{
    int poz;
    long long int val;
} stiva[NMAX];
int cautabin(int x);
int k;
int main()
{
    long long int x;
    int i,n;
    fscanf(fin,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fin,"%lld",&x);
        if(stiva[k].val<x)
        {
            stiva[++k].val=x;
            stiva[k].poz=i;
        }
    }
    stiva[++k].val=100000000;
    stiva[k].poz=n+1;
    for(i=1; i<k; i++)
        stiva[i].poz=stiva[i+1].poz-stiva[i].poz;
    /*    for(i=1;i<k;i++)
            fprintf(fout,"%d ",stiva[i].poz);*/
    int m,p;
    fscanf(fin,"%d",&m);
    for(i=1; i<=m; i++)
    {
        fscanf(fin,"%d",&x);
        p=cautabin(x);
        fprintf(fout,"%d ",stiva[p].poz);
    }
    fprintf(fout,"\n");
    return 0;
}

int cautabin(int x)
{
    int lo=0,hi=k,mid;
    while(hi-lo>1)
    {
        mid=lo+(hi-lo)/2;
        if(stiva[mid].val<x)
            lo=mid;
        else hi=mid;
    }
    if(hi==k||stiva[hi].val!=x)
        return 0;
    return hi;
}
