#include <cstdio>
#define INF 10005
using namespace std;
FILE* fin=fopen("secv.in","r");
FILE* fout=fopen("secv.out","w");

int A[30005],x,y;
int MAX=INF;
int main()
{
    int N,i;
    fscanf(fin,"%d",&N);
    int X=0,poz;
    for(i=1; i<=N; i++)
    {
        fscanf(fin,"%d",&A[i]);
        if(A[i]>X)
        {
            X=A[i];
            poz=i;
        }
    }

    //caz a)
    int max=0;
    for(i=N; i>poz+1; i--)
    {
        if(A[i]>max) max=A[i];
        if(max+A[i-1]+X<MAX)
        {
            MAX= max+A[i-1]+X;
            x=i-2;
            y=i-1;
        }
    }

    //caz b)
    if(poz!=1&&poz!=N)
    {
        if(A[1]+X+A[N]<MAX)
        {
            MAX=A[1]+X+A[N];
            x=1;
            y=N-1;
        }
    }
    //caz c)
    max=0;
    for(i=1; i<poz-1; i++)
    {
        if(A[i]>max) max=A[i];
        if(max+A[i+1]+X<MAX)
        {
            MAX=max+A[i+1]+X;
            x=i;
            y=i+1;
        }
    }

    fprintf(fout,"%d\n%d %d\n",MAX,x,y);
    return 0;
}
