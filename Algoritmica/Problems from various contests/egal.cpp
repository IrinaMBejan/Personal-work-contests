#include <cstdio>
#define NMAX 200001
using namespace std;
FILE* fin=fopen("egal.in","r");
FILE* fout=fopen("egal.out","w");

struct secvente
{
    int nr,val;
}secv[NMAX];

int a[NMAX];
int main()
{
    int k=1,N,x,i;
    fscanf(fin,"%d",&N);
    for(i=1;i<=N;i++)
        fscanf(fin,"%d",&a[i]);
    secv[k].val=a[1];
    secv[k].nr=1;
    for(i=2;i<=N;i++)
    {
        while(secv[k].val==a[i])
        {
            secv[k].nr++;
            i++;
        }
        k++;
        secv[k].val=a[i];
        secv[k].nr=1;
    }

    for(i=1;i<=k;i++)
        fprintf(fout,"%d %d\n",secv[i].val,secv[i].nr);
    return 0;
}
