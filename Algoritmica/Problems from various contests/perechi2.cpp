#include <cstdio>
#define NMAX 1000001
using namespace std;

FILE* fin=fopen("perechi2.in","r");
FILE* fout=fopen("perechi2.out","w");

int s[NMAX];
int a[1001],b[1001],N,M;

int main()
{
    int i,j,nr=0;
    fscanf(fin,"%d %d",&N,&M);
    for(i=1;i<=N;i++)
        fscanf(fin,"%d",&a[i]);
    for(i=1;i<=M;i++)
        fscanf(fin,"%d",&b[i]);
    for(i=1;i<M;i++)
        for(j=i+1;j<=M;j++)
            s[b[i]+b[j]]++;
    for(i=1;i<N;i++)
        for(j=i+1;j<=N;j++)
           {nr+=s[a[i]+a[j]]; s[a[i]+a[j]]=0;}

    fprintf(fout,"%d\n",nr);
    return 0;
}
