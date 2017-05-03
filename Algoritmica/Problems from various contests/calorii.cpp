#include <cstdio>
#include<math.h>
#define NMAX 10001
using namespace std;

struct prod
{
    int cal;
    int pret;
    double rap;
} a[10001], nmax;

FILE* fin=fopen("calorii.in","r");
FILE* fout=fopen("calorii.out","w");

int main()
{
    long long int s, cal=0;
    int n, i, j, poz;
    double prec;
    fscanf (fin,"%d",&n);
    for (i=1; i<=n; i++)
        {
            fscanf (fin, "%d %d", &a[i].cal, &a[i].pret);
            a[i].rap= (double) a[i].cal/a[i].pret;
        }
    fscanf (fin, "%lld", &s);
    for (j=n; j>1; j--)
    {
        nmax=a[1]; poz=1;
        for (i=2; i<=j; i++)
            if (a[i].rap<nmax.rap)
                {
                    nmax=a[i];
                    poz=i;
                }
        a[poz]=a[j];
        a[j]=nmax;
    }
    i=1;
    bool ok=1;
    while (s&&i<=n&&ok)
    {
        if (a[i].pret<=s)
            {
                s-=a[i].pret;
                cal+=a[i].cal;
                poz=i;
            }
        else ok=0;
        i++;
    }
    poz++;
    prec=(float) s/a[poz].pret;
    prec*=a[poz].cal;
    fprintf(fout,"%.4f",cal+prec);
    return 0;
}
