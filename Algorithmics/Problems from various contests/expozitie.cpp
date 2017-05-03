#include <fstream>
#define Nmax 505
#define Lgmax 205
using namespace std;
ifstream fin("expozitie.in");
ofstream fout("expozitie.out");
typedef int NRMARE[Lgmax];

NRMARE a[2][Nmax];
int nr[2][Nmax];
void Suma(NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc);
void Afisare(NRMARE c, int nc);

int N,D,K;
int main()
{
    int i,j;
    fin>>N>>D>>K;
    int r=N-D*K;
    if(r==0) fout<<1<<'\n';
    else if(r<0) fout<<0<<'\n';
    else
    {
        int cur=1,prev=0,x;
        for(j=1; j<=D; j++)
           {
                x=j; nr[prev][j]=0;
                while(x!=0)
               {
                   a[prev][j][nr[prev][j]]=x%10; x/=10; nr[prev][j]++;
               }
           }
        for(i=2; i<=r; i++)
        {
            a[cur][1][0]=1; nr[cur][1]=1;
            for(j=2; j<=D; j++)
                Suma(a[prev][j], nr[prev][j], a[cur][j-1],nr[cur][j-1],a[cur][j], nr[cur][j]);
            prev=1-prev;
            cur=1-cur;
        }
        Afisare(a[prev][D], nr[prev][D]);
    }
    return 0;
}


void Suma(NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc)
{
    int i,t=0,v;
    for(i=0;i<na||i<nb||t;i++)
    {
        v=a[i]+b[i]+t;
        c[i]=v%10;
        t=v/10;
    }
    nc=i;
}
void Afisare(NRMARE c, int nc)
{
    int i;
    for(i=nc-1;i>=0;i--)
        fout<<c[i];
    fout<<'\n';
}


