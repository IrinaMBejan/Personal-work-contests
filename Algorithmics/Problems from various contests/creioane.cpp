#include <cstdio>

using namespace std;
FILE* fin=fopen("creioane.in","r");
FILE* fout=fopen("creioane.out","w");

struct creion
{
    int a;
    int b;
}q[9001];
int h[9001];
int main()
{
    int n,i,k;
    fscanf(fin,"%d",&n);
    for(i=1;i<=n;i++)
        fscanf(fin,"%d %d",&q[i].a,&q[i].b);
    for(i=1;i<=n;i++)
    {
        h[i]=0;
        k=i;
        while(k!=0)
        {
            k=q[k].a;
            h[i]++;
        }
    }
    int max=0;
    for(i=1;i<=n;i++)
        if(h[i]>max) max=h[i];
    fprintf(fout,"%d",max);
    return 0;
}
