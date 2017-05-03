#include <cstdio>

using namespace std;
FILE* fin=fopen("secvente1.in","r");
FILE* fout=fopen("secvente1.out","w");

int a[15000],ciur[30001];
bool pprim(int x, int p);

int main()
{
    int D,j,i,x,n,p,k,m;
    fscanf(fin,"%d",&D);
    for (j=4; j<=30000; j+=2)
        ciur[j]=1;
    for (i=3; i<=173; i+=2)
    {
        if (ciur[i]==0)
            for (j=i*i; j<=30000; j+=i)
                ciur[j]=1;
    }
    for(int q=1; q<=D; q++)
    {
        fscanf(fin,"%d %d %d",&n,&p,&k);
        m=0;
        for(i=1; i<=n; i++)
        {
            fscanf(fin,"%d",&x);
            if(!pprim(x,p))
                a[m++]=i;
        }
        if(m-k+1<=0)  fprintf(fout,"0\n");
        else fprintf(fout,"%d\n",m-k+1);
        for(i=0; i<m-k+1;i++)
            fprintf(fout,"%d %d\n",a[i],a[i+k-1]);
    }
    return 0;
}


bool pprim(int x, int p)
{
    if(x==1) return 1;
    else
        while(x%p==0)
            x/=p;
    return ciur[x];
}
