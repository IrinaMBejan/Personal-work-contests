#include <cstdio>
using namespace std;
FILE* fin=fopen("pluricex.in","r");
FILE* fout=fopen("pluricex.out","w");

int a[25][20],res[10],ver[10];

int main()
{
    int n,d,m,nr,p,k,i,j;
    fscanf(fin,"%d %d %d", &n,&m,&d);
    for(i=1; i<=n; i++)
    {
        fscanf(fin,"%d",&nr);
        for(k=1; k<=nr; k++)
        {
            fscanf(fin,"%d",&p);
            a[i][p]=1;
        }
    }
    for(i=1; i<=m; i++)
        res[i]=i;
    int ok=0,ok2;
    while(!ok)
    {
        for(i=1;i<=d;i++)
            ver[i]=0;
        ok2=1;
        for(i=1; i<=m; i++)
            for(j=1;j<=d;j++)
                if(a[res[i]][j]==1) ver[j]=1;
        for(i=1;i<=d;i++)
            if(ver[i]==0) ok2=0;
        if(ok2==1)
            {
                for(i=1; i<=m; i++)
                    fprintf(fout,"%d ",res[i]);
                fprintf(fout,"\n");
            }
        i=m;
        while(res[i]==n-m+i&&i>=0)
            i--;
        if(i==0) ok=1;
        else
        {
            res[i]++;
            for(int k=i+1; k<=m; k++)
                res[k]=res[i]+k-i;
        }
    }
    return 0;
}
