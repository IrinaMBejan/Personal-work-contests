#include <cstdio>
using namespace std;
FILE* fin=fopen("premii1.in","r");
FILE* fout=fopen("premii1.out","w");



bool p[500002];
int a[501];

int main()
{
    int n,nr=0,x,i,j,smax=0;
    fscanf(fin,"%d",&n);
    for(int i=1; i<=n; i++)
    {
        fscanf(fin,"%d",&a[i]);
        smax+=a[i];
    }
    p[0]=1;
    for(i=1; i<=n; i++)
    {
        for(j=smax-1; j>=0; j--)
            if(p[j])
                p[j+a[i]]=1;
    }
    for(i=1; i<=smax; i++)
        if(p[i]) nr++;
    fprintf(fout,"%d",nr);
    return 0;
}
