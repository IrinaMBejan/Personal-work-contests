#include <cstdio>
#define CMAX 210
FILE* fin=fopen("panglica.in","r");
FILE* fout=fopen("panglica.out","w");

int ci[CMAX];
int cf[CMAX];
int main()
{
    int n,c,i,x,maxi,poz;
    fscanf(fin,"%d %d",&n,&c);
    for(i=1;i<=n;i++)
    {
        fscanf(fin,"%d",&x);
        if(ci[x]==0)
            ci[x]=i;
        cf[x]=i;
    }
    maxi=cf[1]-ci[1]+1;
    poz=1;
    for(i=2;i<=c;i++)
        if(cf[i]-ci[i]+1>maxi)
        {
            maxi=cf[i]-ci[i]+1;
            poz=i;
        }
    fprintf(fout,"%d\n%d\n%d\n%d\n",maxi,poz,ci[poz]-1,n-cf[poz]);


    return 0;
}
