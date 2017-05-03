#include <cstdio>
#define NMAX 200001
using namespace std;

FILE* fin=fopen("copaci2.in","r");
FILE* fout=fopen("copaci2.out","w");

struct copac
{
    int h;
    int poz;
} stiva[NMAX];

int st[NMAX],dr[NMAX],h[NMAX];
int main()
{
    int n,i,k,val;
    fscanf(fin,"%d",&n);
    for(i=1; i<=n; i++)
        fscanf(fin,"%d",&h[i]);
    //stinga
    k=1;
    stiva[k].poz=1;
    stiva[k].h=h[1];
    for(i=2; i<=n; i++)
    {
        while(h[i]>stiva[k].h&&k>0)
            k--;
        st[i]=stiva[k].poz;
        stiva[++k].h=h[i];
        stiva[k].poz=i;
    }
    //dreapta
    k=1;
    stiva[k].poz=n;
    stiva[k].h=h[n];
    dr[n]=n+1;
    for(i=n-1; i>=1; i--)
    {
        while(h[i]>stiva[k].h&&k>0)
            k--;
        dr[i]=stiva[k].poz;
        stiva[++k].h=h[i];
        stiva[k].poz=i;
    }
    //solutie
    int nr=0;
    for(i=2; i<=n-1; i++)
        if(st[i]>0&&dr[i]<=n&&h[st[i]]>h[i]&&h[i]<h[dr[i]]) nr++;
    fprintf(fout,"%d\n",nr);
    return 0;
}
