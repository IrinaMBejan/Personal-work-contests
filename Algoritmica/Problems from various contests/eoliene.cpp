#include <cstdio>
#define NMAX 1001
using namespace std;

FILE* fin=fopen("eoliene.in","r");
FILE* fout=fopen("eoliene.out","w");

int d[NMAX],df[NMAX],max;
int main()
{
    int n,i,j,poz,dif,spal=0,x;
    fscanf(fin,"%d",&n);
    for(i=1;i<=n;i++)
        fscanf(fin,"%d",&d[i]);

    for(i=1;i<=n;i++)
    {
        fscanf(fin,"%d",&x);
        df[i]=d[i]+x;
        d[i]-=x;
    }
    for(j=n;j>1;j--)
    {
        max=df[1]; poz=1;
        for (i=2; i<=j; i++)
            if(df[i]>max) { max=df[i]; poz=i;}
        x=d[poz];
        d[poz]=d[j];
        df[poz]=df[j];
        d[j]=x;
        df[j]=max;
    }
    i=1;
    int nr=0;
    while(i<n)
    {
       while(d[i+1]<=df[j]&&i<n)
            { nr++; i++;}
       i++;
       j=i;
    }
    fprintf(fout,"%d\n",nr);
    return 0;
}
