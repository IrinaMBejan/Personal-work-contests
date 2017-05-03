#include <cstdio>

using namespace std;
FILE* fin=fopen("roata.in","r");
FILE* fout=fopen("roata.out","w");
int o[361],c[100001];
long long s;

int main()
{
    int n,p,i,k,pozmax,pozmin;
    fscanf(fin,"%d %d",&n,&p);
    for(i=1; i<=n; i++)
        o[i]=i;
    for(i=1; i<=p; i++)
    {
        fscanf(fin,"%d",&c[i]);
        s+=c[i];
    }
   fprintf(fout,"%lld\n",s);
    if (n<p)
        for(k=n+1; k<=p; k++)
        {
            pozmin=1;
            for(i=2; i<=n; i++)
                if (c[i]<c[pozmin]) pozmin=i;
            fprintf(fout,"%d ",o[pozmin]);
            if (c[pozmin]>10000000)
                for(i=1; i<=n; i++)
                    c[i]-=10000000;
            c[pozmin]+=c[k];
            o[pozmin]=k;
        }
    else
        n=p;
    pozmax=1;
    for(i=2; i<=n; i++)
        if (c[i]>=c[pozmax]) pozmax=i;

    for(k=1; k<=n; k++)
    {
        pozmin=1;
        for(i=2; i<=n; i++)
            if (c[i]<c[pozmin]) pozmin=i;
        fprintf(fout,"%d ",o[pozmin]);
        c[pozmin]+=100001;
    }
    fprintf(fout,"\n%d\n",pozmax);
    return 0;
}

