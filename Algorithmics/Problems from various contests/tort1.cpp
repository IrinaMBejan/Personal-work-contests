#include <cstdio>

using namespace std;
FILE* fin=fopen("tort1.in","r");
FILE* fout=fopen("tort1.out","w");

int Sum[501][501];
int main()
{
    int m,n,k,i,j;
    fscanf(fin,"%d %d %d",&m,&n,&k);
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            fscanf(fin,"%d",&Sum[i][j]);
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            Sum[i][j]+=Sum[i-1][j]+Sum[i][j-1]-Sum[i-1][j-1];
    int k1,S,min=1000000, nrs=0;
    for(k1=0; k1<=k; k1++)
        for(i=m-k1; i<=m; i++)
            for(j=n-k+k1; j<=n; j++)
            {
                S=Sum[i][j]-Sum[i-m+k1][j]-Sum[i][j-n+k-k1]+Sum[i-m+k1][j-n+k-k1];
                if(S<min)
                {
                    min=S;
                    nrs=1;
                }
                else if(S==min) nrs++;
            }
    fprintf(fout,"%d\n%d\n",Sum[m][n]-min,nrs);
    return 0;
}
