#include <fstream>
#include <iostream>

#define IN "praslea.in", "r"
#define OUT "praslea.out", "w"

using namespace std;

int m,n;
unsigned long v[500001], l, d, d1, x, y;
int main()
{
    freopen(IN, stdin);
    freopen(OUT, stdout);
    int i, Maxim, Maxim_1, t, r;
    scanf("%d%d%lld", &n, &m, &l);
    Maxim=0;
    for (i=1; i<=m; ++i)
    {
        scanf("%lld%lld", &x, &y);
        if(Maxim<x)
            Maxim=x;
        v[x]=y;
    }
    scanf("%lld", &d);
    t=0;
    Maxim_1=0;
    d1=0;
    r=0;
    for(i=1; i<=Maxim; ++i)
    {
        if(v[i]==0)
        {
            t++;
            v[i]=l;

        }
        else
        {
            if(Maxim_1<t)
                Maxim_1=t;
            t=0;
        }
        if(r==0)
        {
            if(d1+v[i]>=d)
                r=i;
            else d1=d1+v[i];
        }
    }
    if(n-Maxim>Maxim_1)
        Maxim_1=n-Maxim;
    printf("%d\n", Maxim_1);
    if(r==0)
    {
        r=Maxim+(d-d1)/l+1;
        if((d-d1)%l==0)
            r=r-1;
    }
    if(r==1&&d==0) r=2;
    printf("%d\n", r);
    return 0;
}

