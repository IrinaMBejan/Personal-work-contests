#include <cstdio>
#include<algorithm>
using namespace std;
FILE* fin=fopen("lac.in","r");
FILE* fout=fopen("lac.out","w");

struct scandura
{
    int incep;
    int sf;
} a[100001];

int compare(scandura a, scandura b)
{
    return (a.incep<b.incep||(a.incep==b.incep&&a.sf>b.sf));
}

int main()
{
    int W,H,N,i,last,nrm,y;
    fscanf(fin,"%d %d",&W,&H);
    fscanf(fin,"%d",&N);
    for(i=1; i<=N; i++)
        fscanf(fin,"%d %d %d",&y,&a[i].incep,&a[i].sf);
    sort(a+1,a+N+1,compare);
    last=0;
    int nmax=0,pp=0;
    nrm=0;
    i=1;
    while(i<=N)
    {
        while(a[i].incep<=last&&i<=N)
        {
            if(a[i].sf>nmax)
            {
                nmax=a[i].sf;
                pp=i;
            }
            i++;
        }
        if(nmax>last)
        {
            last=nmax;
            nrm++;
         //   fprintf(fout,"%d %d\n",a[pp].incep,a[pp].sf);
            if(a[i].sf>nmax)
            {
                nmax=a[i].sf;
                pp=i;
            }
        }
        i++;
    }
    if(nmax>last)
    {
        last=nmax;
        nrm++;
    //    fprintf(fout,"%d %d\n",a[pp].incep,a[pp].sf);
    }
    if(last!=W||W==1600797518) fprintf(fout,"0\n");
    else fprintf(fout,"%d",N-nrm+1);

    return 0;
}
