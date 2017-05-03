#include <cstdio>
#define NRM 2000010
using namespace std;

FILE* fin=fopen("ozn1.in","r");
FILE* fout=fopen("ozn1.out","w");

int a[NRM];
int N,K;

int main()
{
    int x1,y1,x2,y2,nr,i;
    fscanf(fin,"%d %d",&N,&K);
    for (i=1; i <= N; ++i)
    {
        fscanf(fin,"%d %d %d %d %d",&x1,&y1,&x2,&y2,&nr);
        a[x1]+=nr;
        a[x2+1]-=nr;
    }
    for (i = 1; i < NRM; ++i)
        a[i] += a[i-1];
    for (i = 1; i <= K; ++i)
    {
        fscanf(fin,"%d",&x1);
        fprintf(fout,"%d\n",a[x1]);

    }
    return 0;
}
