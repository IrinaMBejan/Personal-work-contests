#include <cstdio>
#include<cmath>
using namespace std;
FILE* fin=fopen("stalpi2.in","r");
FILE* fout=fopen("stalpi2.out","w");

struct elementeA
{
    int xa;
    int ia;
} A[10001];

struct elementeB
{
    int xb;
    int ib;
} B[10001];

struct culoare
{
    int x,y;
} cc[101];

int cA[30001],cB[30001];
double S;
struct elemente
{
    int x,y;
} vec[101];

int main()
{
    int n,d,i,val,cul,k=0,d1=0,d2=0;
    fscanf(fin,"%d %d",&n,&d);
    for(i=1; i<=n; i++)
    {
        fscanf(fin,"%d %d",&val,&cul);
        cA[val]=i*100+cul-1;
        if(cul>k) k=cul;
        if(val>d1) d1=val;
    }
    for(i=1; i<=n; i++)
    {
        fscanf(fin,"%d %d",&val,&cul);
        cB[val]=i*100+cul-1;
        if(val>d2) d2=val;
    }
    int n1,n2,j,a,b,dif,dift;
    for(i=1; i<=k; i++)
    {
        n1=n2=0;
        for(j=0; j<=d1; j++)
            if(cA[j]&&cA[j]%100+1==i)
            {
                n1++;
                A[n1].xa=j;
                A[n1].ia=cA[j]/100;

            }
        for(j=0; j<=d2; j++)
            if(cB[j]&&cB[j]%100+1==i)
            {
                n2++;
                B[n2].xb=j;
                B[n2].ib=cB[j]/100;
            }
        a=1; b=1; dift=30000;
        while (a<=n1 && b<=n2)
        {
            dif=A[a].xa-B[b].xb;
            if (dif<0)dif=-dif;
            if (dif<dift)
            {
                dift=dif;
                vec[i].x=A[a].ia;
                vec[i].y=B[b].ib;
            }
            if (A[a].xa<B[b].xb)a++;
            else b++;
        }
        S+=sqrt((double)d*d+dift*dift);
    }
    fprintf(fout,"%.3lf\n",S);
    for(i=1; i<=k; i++)
        fprintf(fout,"%d %d\n",vec[i].x,vec[i].y);
    return 0;
}
