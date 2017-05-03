#include <cstdio>
#include <algorithm>
#define TMAX 2881
FILE* fin=fopen("bac.in","r");
FILE* fout=fopen("bac.out","w");

using namespace std;

struct ore
{
    char mal;
    int t;
    int uz;
};

bool compare(ore a, ore b)
{
    return a.t<b.t;
}
int main()
{
    ore a[TMAX];
    int na, nb, i, j, h, m, k, l, x;
    fscanf(fin, "%d %d", &k,&l);
    fscanf(fin,"%d",&na);
    for(i=1;i<=na;i++)
    {
        fscanf(fin,"%d:%d", &h, &m);
        a[i].t=h*60+m;
        a[i].mal=65;
    }
    fscanf(fin,"%d",&nb);
    for(i=na+1;i<=nb+na;i++)
    {
        fscanf(fin,"%d:%d", &h, &m);
        a[i].t=h*60+m;
        a[i].mal=66;
    }
    sort(a+1,a+na+nb+1,compare);
    int nrplecari, nrbac,poz,last,p=na+nb;
    poz=1; nrplecari=0; nrbac=0;
    while (nrplecari<p)
    {
        nrbac++;
        while (a[poz].uz) poz++;
        a[poz].uz=1; nrplecari++;
        last=poz;
        for(i=1; i<=p; i++)
            if(a[i].uz==0&&a[i].t>=a[last].t+k+l&&a[i].mal!=a[last].mal)
                { a[i].uz=1; nrplecari++; last=i;}

    }
    fprintf(fout,"%d\n",nrbac);
    return 0;
}
