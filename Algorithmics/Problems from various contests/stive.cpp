#include <cstdio>
#define  MAXN 30010

int n, nrm;
int a[MAXN], M[MAXN];

FILE *fin=fopen("stive.in","r");
FILE *fout=fopen("stive.out","w");

int solve(int n)
{
    int nr=0;
    while(n)
        n=n-(n+1)/2, nr++;
    return nr;
}

int main()
{
    int i, x, max, j, lg;
    fscanf(fin,"%d",&n);
    for (i=1; i<=n; i++)
        a[i]=i;
    nrm=solve(n);
    fprintf(fout,"%d\n",nrm);
    max=n;
    do
    {
        x=(max+1)/2;
        lg=0;
        for (i=1; i<=n; i++)
            if (a[i]>=x)
            {
                M[lg++]=i;
                a[i]-=x;
            }
        fprintf(fout,"%d",lg);
        for (j=0; j<lg; j++)
            fprintf(fout," %d",M[j]);
        fprintf(fout," %d\n",x);
        max=max-x;
    }
    while (max);

    fclose(fout);
    return 0;
}

