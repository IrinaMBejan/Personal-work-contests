#include <cstdio>
#define Nmax 50000
#define INF  2000000000
using namespace std;

FILE* fin=fopen("stiva1.in","r");
FILE* fout=fopen("stiva1.out","w");
int lg,v[Nmax+5],st[Nmax+5],b[Nmax+5];
int k,p,maxst,maxdr,start;

int main()
{
    int i;
    bool ok1;
    fscanf(fin,"%d",&lg);
    int T=5;
    int minu,maxu;
    while(T)
    {
        for (i=1;i<=Nmax;i++)
            b[i]=0;

        minu=INF;
        maxu=0;
        for(i=1;i<=lg;i++)
            {
                fscanf(fin,"%d",&v[i]);
                if(v[i]<minu) minu=v[i];
                if(v[i]>maxu) maxu=v[i];
            }
        maxst=0;
        maxdr=0;
        ok1=0;
        for (i=1;i<=lg;i++)
        {
            v[i]-=(minu-1);
            b[v[i]]=1;
            if (v[i]==1)
                ok1=1;
            if (!ok1)
                if (v[i]>maxst)
                    maxst=v[i];
        }
        maxu-=(minu-1);
        start=1;
        for (i=maxst;i>1;i--)
            if (b[i]==0)
            {
                start=(start+Nmax-1)%Nmax;
                v[start]=i;
            }

        p=lg;
        for (i=maxu;i>=maxst;i--)
            if (b[i]==0)
                v[++p]=i;
        k=0;p=start;
        for(i=1;i<=maxu;i++)
        {
            st[++k]=i;
            while(k>0 and st[k]==v[p])
            {
                p=(p+1)%Nmax;
                --k;
            }
        }
        if (k==0) fprintf(fout,"1\n");
        else fprintf(fout,"0\n");
        T--;
    }
    return 0;
}

