#include <fstream>
#include<cmath>
#include<algorithm>
using namespace std;
ifstream fin("seceta.in");
ofstream fout("seceta.out");

double d[15][15];
struct punct
{
    int x,y;
}g[15],f[15];

int perm[15];
int main()
{
    int n,i,j;
    fin>>n;
    for(i=1;i<=n;i++)
        fin>>g[i].x>>g[i].y;
    for(i=1;i<=n;i++)
        fin>>f[i].x>>f[i].y;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            d[i][j]=sqrt((double)(g[i].x-f[j].x)*(g[i].x-f[j].x)+(g[i].y-f[j].y)*(g[i].y-f[j].y));
    for(i=1;i<=n;i++)
        perm[i]=i;
    double Cost,Cmin=1000000;
    while(next_permutation(perm+1,perm+n+1))
    {
        Cost=0;
        for(i=1;i<=n;i++)
            Cost+=d[i][perm[i]];
        if(Cost<Cmin) Cmin=Cost;
    }

    fout<<(int)(Cmin*100)<<'\n';
    return 0;
}
