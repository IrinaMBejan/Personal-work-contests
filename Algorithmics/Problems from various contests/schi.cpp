#include <fstream>
#define DMAX 101

using namespace std;

ifstream fin("schi.in");
ofstream fout("schi.out");

float a[DMAX];
int pozm[DMAX];
bool ok[DMAX];

int main()
{
    int n, m, i, j, poz,c;
    float d, nmax,nmin,min;
    fin>>n>>m;
    fin>>a[1];
    min=a[1];
    for(i=2;i<=n;i++)
    {
        fin>>d;
        a[i]=min+d;
        if(a[i]<min) min=a[i];
    }
    for(i=1;i<=n;i++)
        pozm[i]=i;
    for(i=1; i<n;i++)
    {
        nmin=a[i];
        for(j=i;j<=n;j++)
        if(a[j]<nmin) {nmin=a[j]; poz=j;}
        if(a[i]!=nmin)
        {
            c=pozm[poz];
            pozm[poz]=pozm[i];
            pozm[i]=c;
            a[poz]=a[i];
            a[i]=nmin;
        }
    }

    for(i=1;i<=n;i++)
        ok[i]=false;
    for(i=1;i<=m;i++)
        ok[pozm[i]]=true;
    fin>>a[pozm[m]];
    min=a[pozm[m]];
    int x,k;
    k=pozm[m];
    while(m>0)
    {
        m--;
        fin>>a[pozm[m]];
        a[pozm[m]]+=min;
        if(a[pozm[m]]<min) min=a[pozm[m]];
    }
    for(j=1; j<=3; j++)
    {
        nmin=301;
        for(i=1; i<=n; i++)
            if(a[i]<nmin&&ok[i])
            {
                nmin=a[i];
                poz=i;

            }
        fout<<poz<<'\n';
        ok[poz]=false;
    }


    return 0;
}
