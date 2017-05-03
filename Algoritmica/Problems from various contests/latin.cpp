#include <cstdio>
#include<algorithm>
using namespace std;
FILE* fin=fopen("latin.in","r");
FILE* fout=fopen("latin.out","w");

struct subpatratlatin
{
    int x,y,ord;

} latin[5050];

int a[505][505];
int compare(subpatratlatin a, subpatratlatin b)
{
    return((a.x<b.x)||(a.x==b.x&&a.ord<b.ord));
}
int main()
{
    int N,i,j,k,cmin,cmax,x,q=0;
    fscanf(fin,"%d",&N);
    for(i=1; i<=N; i++)
        for(j=1; j<=N; j++)
        {
            fscanf(fin,"%d",&x);
            a[i][x]=j;
        }
    int ok,v;
    for(i=1; i<=N; i++)
    {
        k=1;
        ok=1;
        cmin=cmax=a[i][1];
        do
        {
            if(ok)
            {
                k*=2;
                if(k>=N) break;
                for(v=1; v<=k; v++)
                {
                    if(i+k-1>N) break;
                    for(j=i; j<=i+k-1; j++)
                    {
                        if(a[j][v]<cmin) cmin=a[j][v];
                        if(a[j][v]>cmax) cmax=a[j][v];
                    }
                }
            }
            else
            {
                k++;
                if (k>= N)
                    break;
                for (v = k; v<=k; v++)
                {
                    for(j=i; j<=i+k-1; j++)
                    {
                        if(a[j][v]<cmin) cmin=a[j][v];
                        if(a[j][v]>cmax) cmax=a[j][v];
                    }
                }
            }
            if(cmax-cmin+1==k&&k!=N)
            {
                latin[++q].x=i;
                latin[q].y=cmin;
                latin[q].ord=k;
                ok=1;
            }
            else ok=0;
        }
        while (i + k- 1 <= N);
    }
    sort(latin+1,latin+q+1,compare);
    fprintf(fout,"%d\n",q);
    for(i=1; i<=q; i++)
        fprintf(fout,"%d %d %d\n",latin[i].x,latin[i].y,latin[i].ord);
    return 0;
}
