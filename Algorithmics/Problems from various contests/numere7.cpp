#include <cstdio>
#define NMAX 64001
using namespace std;
FILE* fin=fopen("numere7.in","r");
FILE* fout=fopen("numere7.out","w");

bool a[NMAX];
int main()
{
    int n,i,x,j,p,min,max;
    fscanf(fin,"%d",&n);
    if(n>252)
        p=64000;
    else p=n*n;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            fscanf(fin,"%d",&x);
            if(x<NMAX)
                a[x]=1;
        }
    i=1;
    while(a[i]==1&&i<=p)
        i++;
    min=i;
    while(a[i]==0&&i<=p)
        i++;
    max=i-1;
    fprintf(fout,"%d %d",min,max);
    return 0;
}
