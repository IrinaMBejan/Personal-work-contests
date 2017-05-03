#include <cstdio>
#include<algorithm>
using namespace std;
FILE* fin=fopen("livada.in","r");
FILE* fout=fopen("livada.out","w");

long long int a[22501];
int main()
{
    long long int n,i,x,st=0,fi=0,m,me,t,q;
    fscanf(fin,"%lld %lld %lld",&n,&me,&x);
    q=n*me;
    for(i=1; i<=q; i++)
    {
        fscanf(fin,"%lld",&a[i]);
        if(a[i]>fi) fi=a[i];
    }
    if(x==1) fprintf(fout,"%lld\n",fi);
    else
    {
        fi++;
        while(fi-st>1)
        {
            m=(fi+st)/2;
            t=0;
            for (i=1; i<=q; i++)
                if (a[i]>m)
                    t=t+((a[i] - m + x - 2)/(x-1));
            if (t<=m)
                fi=m;
            else
                st=m;
        }
        if(t<=m) fprintf(fout,"%lld\n",m);
        else fprintf(fout,"%lld\n",fi);
    }
    return 0;
}
