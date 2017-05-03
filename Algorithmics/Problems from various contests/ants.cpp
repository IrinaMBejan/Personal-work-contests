#include <cstdio>

using namespace std;
FILE* fin=fopen("ants.in","r");
FILE* fout=fopen("ants.out","w");

struct familie
{
    int poz;
    int bob;
} q[100001];

int n;
int verifica(int m);

int main()
{
    unsigned long long int s=0;
    int i,m,ok=0,fi,st;
    fscanf(fin,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fin,"%d %d",&q[i].poz,&q[i].bob);
        s+=q[i].bob;
    }
    fi=s/4+1;
    st=0;
    while(fi-st>1)
    {
        m=(fi+st)/2;
        ok=verifica(m);
        if(ok==1)
            st=m;
        else
            fi=m;
    }
    if(verifica(m)==1) fprintf(fout,"%d\n",m);
    else  fprintf(fout,"%d\n",st);
    return 0;
}

int verifica(int m)
{
    int i;
    long long int transport=0,x;
    for(i=1; i<n; i++)
    {
        x=q[i].bob+transport;
        if(x<m)
            transport=x-m-(q[i+1].poz-q[i].poz);
        else
        {
           transport = x-m-(q[i+1].poz-q[i].poz);
           if (transport<0) transport = 0;
        }
    }
    return (q[n].bob+transport>=m);
}
