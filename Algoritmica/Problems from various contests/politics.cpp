#include <cstdio>
#include<algorithm>

#define NMAX 15001
using namespace std;

FILE* fin=fopen("politics.in","r");
FILE* fout=fopen("politics.out","w");
struct partid
{
    int part;
    int membr;
} cati[NMAX];
bool compare(partid a, partid b)
{
    return a.membr>b.membr;
}
int p[NMAX];


int main()
{
    int n, m, i, x, y, partide, aux;
    fscanf(fin,"%d %d", &n, &m);
    for(i=1; i<=n; i++)
        p[i]=i;
    partide=n;
    int j,q;
    for(i=1; i<=m; i++)
    {
        fscanf(fin,"%d %d",&x,&y);

        if(p[x]!=p[y])
        {
            if(p[x]>p[y])
        {
            aux=p[x];
            p[x]=p[y];
            p[y]=aux;
        }
            q=p[y];
            for(j=1; j<=n; j++)
                if(p[j]==q) p[j]=p[x];
        }
    }
    for(i=1;i<=n;i++)
        {
            cati[p[i]].membr++;
            cati[i].part=i;
        }
    int s=0,last;
    sort(cati+1,cati+n+1,compare);
    i=1;
    while(s<(n/2+1))
    {
        s+=cati[i].membr;
        last=i;
        i++;
    }
    fprintf(fout,"%d\n",last);
    for(i=1;i<=last;i++)
        fprintf(fout,"%d ",cati[i].part);
    return 0;
}
