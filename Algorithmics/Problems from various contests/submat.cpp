#include <cstdio>
#include<algorithm>
#define NMAX 1001
using namespace std;
FILE* fin=fopen("submat.in","r");
FILE* fout=fopen("submat.out","w");

int lg[NMAX];
int main()
{
    int n,m,i,j,max=0,x;
    fscanf(fin,"%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            fscanf(fin,"%d",&x);
            if(x==0) lg[i]++;
        }
    }
   sort(lg+1,lg+n+1);
    for(i=n;i>=1;i--)
        if(lg[i]*(n-i+1)>max) max=lg[i]*(n-i+1);
    fprintf(fout,"%d\n",max);
    return 0;
}
