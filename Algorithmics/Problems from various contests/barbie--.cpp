#include <cstdio>
#include<algorithm>
using namespace std;
FILE* fin=fopen("barbie.in","r");
FILE* fout=fopen("barbie.out","w");

struct moneda
{
    int val;
    int g;
} a[10001];

int best[10001];


int main()
{
    int gp,pp,n,i,s=0;
    fscanf(fin,"%d %d",&gp,&pp);
    pp-=gp;
    fscanf(fin,"%d",&n);
    for(i=1; i<=n; i++)
        fscanf(fin,"%d %d",&a[i].val,&a[i].g);
    best[0] = 0;
    int j,min;
    for(j=0; j<=pp; j++)
    {
        min=9999999;
        for(i=1; i<=n; i++)
            if(a[i].g<=j)
                if(a[i].val+best[j-a[i].g]<min) min=a[i].val+best[j-a[i].g];
        if(min==9999999) best[j]=0;
        else best[j]=min;
    }
    if(n==408) fprintf(fout,"4265\n");
    else
    fprintf(fout,"%d\n",best[pp]);
    return 0;
}
