#include <fstream>
#include<algorithm>
using namespace std;
ifstream fin("triunghi6.in");
ofstream fout("triunghi6.out");
int ssig[50], nra,nr,a[50],n,k,i,j,b[50],aux,x,p;

int main()
{
    fin>>p>>n>>k;
    for (i=1; i<=n; i++)
        fin>>a[i];
    sort(a+1,a+n+1);
    if (p==1)
    {
        b[1]=b[2]=a[1];
        for (i=3; i<=k; i++)
            b[i]=b[i-1]+b[i-2];
        for (i=1; i<=k; ++i)
            fout<<b[i]<<' ';
        fout<<"\n";
    }
    else
    {
        if (a[1]==a[2])
        {
            b[1]=b[2]=a[1];
            ssig[1]=ssig[2]=1;
            nra=3;
        }
        else
        {
            b[1]=b[2]=1;
            if (a[1]==1)
            {
                ssig[1]=1;
                nra=2;
            }
            else
                nra=1;

        }
        nr=2;
        while (nra<n)
        {
            x=b[nr]+b[nr-1];

            if (b[nr]+x<=a[nra] && x<=a[nra+1]-a[nra])
                b[++nr]=x;
            else
            {
                b[++nr]=a[nra++];
                ssig[nr]=1;
            }
        }
        while (nra==n)
        {
            x=b[nr]+b[nr-1];
            if(b[nr]<=a[nra]-x)
                b[++nr]=x;
            else
            {
                b[++nr]=a[nra++];
                ssig[nr]=1;
            }
        }
        while (b[nr]<=2000000000-b[nr-1])
        {
            b[nr+1]=b[nr]+b[nr-1];
            nr++;
        }
        for (i=1; i<=nr; i++)
            if (ssig[i]) fout<<b[i]<<" ";
        x=k-n;
        for(i=1; x && i<=nr; i++)
            if (!ssig[i])
            {
                fout<<b[i]<<" ";
                --x;
            }
        fout<<"\n";
    }
    fin.close();
    fout.close();

    return 0;
}
