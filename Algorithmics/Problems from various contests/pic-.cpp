#include <fstream>
#define LGMAX 31
using namespace std;
typedef  int NRMARE[LGMAX];

void diferenta (NRMARE a, NRMARE b);
void fillzero(NRMARE a);
void suma(NRMARE a, NRMARE b);
int comp(NRMARE a, NRMARE b);

ifstream fin("pic.in");
ofstream fout("pic.out");

NRMARE but[41],s,vase,maxi;

int main()
{
    int n,m,p,i,j,nr=0,k,c,poz;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fillzero(vase);
        fin>>nr;
        vase[0]=nr;
        for(j=1; j<=nr; j++)
            fin>>vase[nr-j+1];
        suma(s,vase);
    }
    fin>>m;
    for(i=1; i<=m; i++)
    {
        fin>>nr;
        but[i][0]=nr;
        for(j=1; j<=nr; j++)
            fin>>but[i][nr-j+1];
    }
    for(j=m; j>1; j--)
    {
        fillzero(maxi);
        for(i=0; i<=but[1][0]; i++)
            maxi[i]=but[1][i];
        poz=1;
        for (i=2; i<=j; i++)
            if(comp(but[i],maxi)>0)
            {
                fillzero(maxi);
                for(k=0; k<=but[i][0]; k++)
                    maxi[k]=but[i][k];
                poz=i;
            }
        fillzero(but[poz]);
        for(i=0; i<=but[j][0]; i++)
                but[poz][i]=but[j][i];
        fillzero(but[j]);
        for(i=0; i<=but[j][0]; i++)
            but[j][i]=maxi[i];
    }
    nr=0;
    for(i=1;i<=m&&comp(but[i],s)==-1;i++)
    {
        nr++;
        diferenta(s,but[i]);
    }
    fout<<nr<<'\n';
    return 0;

}

int comp(NRMARE a, NRMARE b)
{
    int i;
    if(a[0]>b[0]) return 1;
    if(b[0]>a[0]) return -1;
    i=a[0];
    while(a[i]==b[i]&&i>=1) i--;
    if (i==0) return 0;
    if(a[i]>b[i]) return 1;
    return -1;
}

void fillzero(NRMARE a)
{
    int i;
    for(i=1; i<=a[0]; i++)
        a[i]=0;
}

void suma (NRMARE a, NRMARE b)
{
    int i,t=0,v;
    for(i=1; i<=a[0]||i<=b[0]||t; i++)
    {
        v=a[i]+b[i]+t;
        a[i]=v%10;
        t=v/10;
    }
    a[0]=i-1;
}

void diferenta (NRMARE a,NRMARE b)
{
    int T=0,i;
    for(i=1; i<=a[0]; i++)
    {
        a[i]=a[i]-b[i]+T;
        if(a[i]<0)
        {
            a[i]+=10;
            T=-1;
        }
        else T=0;
    }
    while(a[a[0]]==0&&a[0]>1)
        a[0]--;
}

