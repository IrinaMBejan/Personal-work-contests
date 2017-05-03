#include <fstream>
#include<algorithm>
#include<cmath>
#define NMAX 501
using namespace std;
ifstream fin("paralel.in");
ofstream fout("paralel.out");

int p[NMAX];
struct mijloace
{
    float x;
    float y;
} mij[NMAX*NMAX/2];


int compar(mijloace a, mijloace b)
{
    return (a.x<b.x||(a.x==b.x&&a.y<b.y));
}
int main()
{
    int n,i,j,x,y,k,mx,my,nr,nrf,nrt=0;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>x>>y;
        p[i]=x*1000+y;
    }
    k=0;
    for(i=1; i<n; i++)
        for(j=i+1; j<=n; j++)
        {
            mij[++k].x=((float)(p[i]/1000+p[j]/1000)/2);
            mij[k].y=((float)(p[i]%1000+p[j]%1000)/2);
        }
    sort(mij+1,mij+k+1,compar);
    for(i=1; i<=k; i++)
    {
        nr=0,nrf=0;
        while(mij[i].x==mij[i+1].x&&mij[i].y==mij[i+1].y)
            nr++,i++;
        if(nr)
            nrt+=((nr+1)*nr/2);
    }
    fout<<nrt<<'\n';
    return 0;
}
