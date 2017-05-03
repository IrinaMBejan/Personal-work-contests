#include <cstdio>
#define NMAX 20
using namespace std;

FILE* fin=fopen("combin.in","r");
FILE* fout=fopen("combin.out","w");

int e[NMAX],res[NMAX];
int main()
{
    int i,n,m,ok=0;
    fscanf(fin,"%d %d",&n,&m);
    for(i=1; i<=m; i++)
        res[i]=i;
    while(!ok)
    {
        for(i=1; i<=m; i++)
            fprintf(fout,"%d ",res[i]);
        fprintf(fout,"\n");
        i=m;
        while(res[i]==n-m+i&&i>=0)
            i--;
        if(i==0) ok=1;
        else
        {
            res[i]++;
            for(int k=i+1; k<=n; k++)
                res[k]=res[i]+k-i;
        }
    }
    return 0;
}
