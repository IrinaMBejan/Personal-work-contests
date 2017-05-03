#include <cstdio>
#define NMAX 241
using namespace std;
FILE* fin=fopen("sotron.in","r");
FILE* fout=fopen("sotron.out","w");

int mat[NMAX][NMAX];
int main()
{
    int N,i,j,st,fi,poz;
    int sumMax=0;
    fscanf(fin,"%d",&N);
    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
                fscanf(fin,"%d",&mat[i][j]);
    int s,bestSum, mmin,x,y;
    for(i=1;i<=N;i+=2)
    {
         s=0; bestSum=-47900; mmin=0,st=0,fi=0,poz=0;
         x=i;
         y=1;
        while(x>=0&&y<=N)
        {
                s+=mat[x][y];
                if(s-mmin>bestSum)
                {
                    bestSum=s-mmin; st=poz+1; fi=i;
                }
                if(s<mmin)
                {
                    mmin=s; poz=i;
                }
                if(x%2==y%2) x--;
                else y++;
        }
        if(bestSum>sumMax) sumMax=bestSum;
    }
    for(i=2;i<=N;i+=2)
    {
         s=0; bestSum=-47900; mmin=0,st=0,fi=0,poz=0;
        x=N;
        y=i;
        while(x>=0&&y<=N)
        {
                s+=mat[x][y];
                if(s-mmin>bestSum)
                {
                    bestSum=s-mmin; st=poz+1; fi=i;
                }
                if(s<mmin)
                {
                    mmin=s; poz=i;
                }
                if(x%2==y%2) x--;
                else y++;
        }
        if(bestSum>sumMax) sumMax=bestSum;
    }
    fprintf(fout,"%d\n",sumMax);
    return 0;
}
