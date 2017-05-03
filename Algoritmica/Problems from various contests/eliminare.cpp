#include <cstdio>
#define NMAX 100001
using namespace std;

FILE* fin=fopen("eliminare.in","r");
FILE* fout=fopen("eliminare.out","w");

int a[NMAX],N;
int cautap(int x);
int main()
{
    int Q,i,poz,x;
    fscanf(fin,"%d %d",&N,&Q);
    for(i=1;i<=N;i++)
        fscanf(fin,"%d",&a[i]);
    for (i=1; i<=Q; i++)
   {
        fscanf(fin,"%d",&x);
      poz=cautap(x);
      if(x==a[poz]) fprintf(fout,"0\n");
      else fprintf(fout,"%d\n",x-poz+1);

   }
    return 0;
}

int cautap(int x)
{
    int hi =N+1, lo =0, mid;
    while (hi - lo > 1)
    {
      mid = (lo + hi) / 2;
       if (a[mid] < x)
        lo = mid;
       else
         hi = mid;
    }
    return hi;
}
