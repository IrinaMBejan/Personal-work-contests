#include <fstream>
#include <math.h>
#define NMAX 201
using namespace std;

ifstream fin("grupe2.in");
ofstream fout("grupe2.out");

int rmax[NMAX], x[NMAX];

int nrd(int x)
{
    int i,nr=2;
    for(i=2; i*i<x; i++)
        if (x%i==0) nr+=2;
    if (i*i==x) nr++;
    return nr;
}

int main()
{
    int nr,i,max1,max2,poz1,poz2,n,m;
    int a;
    fin>>n>>m;
    for(i=1; i<=n*m; i++)
    {
        fin>>a;
        nr=nrd(a);
        x[nr]++;
        if (a>rmax[nr]) rmax[nr]=a;
    }
    max1 = x[2];
    poz1 = 2;
    max2=0;
    for(i=3; i<=200; i++)
        if (x[i]>=max1)
        {
            max2 = max1;
            poz2 = poz1;
            max1 = x[i];
            poz1 = i;
        }
        else if (x[i]>=max2)
        {
            max2 = x[i];
            poz2 = i;
        }
    fout<<poz1<<" "<<x[poz1]<<" "<<rmax[poz1]<<'\n';
    if (max2==0)
        fout<<"0 0 0";
    else
        fout<<poz2<<" "<<x[poz2]<<" "<<rmax[poz2];

    return 0;
}
