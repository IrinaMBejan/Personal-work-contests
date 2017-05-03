#include <cstdio>
#define DMAX 5001
using namespace std;
FILE* fin=fopen("ratb.in","r");
FILE* fout=fopen("ratb.out","w");

int a[DMAX];
int main()
{
    int n, k, i, s,poz1=0,poz2=0;
    fscanf(fin,"%d %d",&n,&k);
    for(i=1; i<=n; i++)
        fscanf(fin,"%d",&a[i]);
    int p=-30000;
    while(k<=n)
    {
        s=0;
        for(i=1; i<=k; i++)
            s+=a[i];
        if(s>p)
        {
            p=s;
            poz1=1;
            poz2=k;
        }
        for(i=k+1; i<=n; i++)
        {
            s=s-a[i-k]+a[i];
            if(s>p)
            {
                p=s;
                poz1=i-k+1;
                poz2=i;
            }
        }
        k++;
    }
    fprintf(fout,"%d\n%d %d\n",p,poz1,poz2);
    return 0;
}
