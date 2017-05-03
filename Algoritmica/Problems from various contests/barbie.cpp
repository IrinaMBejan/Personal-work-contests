#include <cstdio>
#include<algorithm>
using namespace std;
FILE* fin=fopen("barbie.in","r");
FILE* fout=fopen("barbie.out","w");

struct moneda
{
    int val;
    int g;
    double k;
} a[10001];
int compare(moneda a, moneda b)
{
    return a.k< b.k;
}


int main()
{
    int gp,pp,n,i,s=0;
    fscanf(fin,"%d %d",&gp,&pp);
    pp-=gp;
    fscanf(fin,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fin,"%d %d",&a[i].val,&a[i].g);
        a[i].k=a[i].val/a[i].g;
    }
    sort(a+1,a+n+1,compare);
    i=1;
    while(pp>0&&a[i].g<=pp)
    {
        while(a[i].g<=pp)
        {
            pp-=a[i].g;
            s+=a[i].val;
        }
        i++;
    }
    fprintf(fout,"%d\n",s);
    return 0;
}
