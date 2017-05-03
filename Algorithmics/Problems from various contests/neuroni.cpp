#include <cstdio>
using namespace std;
FILE* fin=fopen("neuroni.in","r");
FILE* fout=fopen("neuroni.out","w");

int n,m;
int v[5051],w[5051];

int main()
{
    int k=0,i,j,nc;
    fscanf(fin,"%d %d",&n,&m);
    for(i=1; i<n; i++)
        for(j=1; j<=i; j++)
        {
            v[++k]=i%2;
            w[k]=i;
        }
    int q=n*(n-1)/2;
    for(i=1; i<=m; i++)
    {
        nc=1;
        while (nc<=q)
            if (v[nc]==0)
            {
                v[nc]=1;
                nc=nc+w[nc];
            }
            else
            {
                v[nc]=0;
                nc=nc+w[nc]+1;
            }
        v[nc]++;
    }
    int z=n*(n+1)/2;
    for(i=q+1; i<=z; i++)
        fprintf(fout,"%d ",v[i]);
    fprintf(fout,"\n");
    return 0;
}
