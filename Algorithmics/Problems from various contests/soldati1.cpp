#include <fstream>
#include<cstring>
#define LGMAX 205
#define Nmax 105
using namespace std;
ifstream fin("soldati1.in");
ofstream fout("soldati1.out");


typedef short int NRMARE[LGMAX];
NRMARE C[Nmax],P[Nmax];
int lgc[Nmax],lgp[Nmax];
int N,K;
NRMARE x, y;
int lgx,lgy;

void fillzero(NRMARE a, int na);
void suma (NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc);
void afisare(NRMARE c, int nc);
void prodint (NRMARE a, int na, int b, NRMARE c, int &nc);
int ezero(NRMARE a, int na);
void atrib(NRMARE a, int &na, NRMARE b, int nb);

int main()
{
    fin>>N>>K;
    lgp[0]=lgp[1]=lgc[1]=1;
    P[0][0]=P[1][0]=C[1][0]=1;
    int i,j;
    for(i=1;i<=N;i++)
    {
        for(j=2;j<=K;j++)
        {
            prodint(P[j],lgp[j],j,x,lgx);
            if(i-j+1<=0) continue;
            prodint(P[j-1],lgp[j-1],(i-j+1),y,lgy);
            suma(x,lgx,y,lgy,C[j],lgc[j]);
        }
        for(j=2;j<=K;j++)
            atrib(P[j], lgp[j], C[j], lgc[j]);
    }
    afisare(P[K], lgp[K]);
    return 0;
}
void atrib(NRMARE a, int &na, NRMARE b, int nb)
{
    int i;
    for(i=0;i<nb;i++)
        a[i]=b[i];
    a[i]=0;
    na=nb;
}

void afisare(NRMARE c, int nc)
{
    int i;
    for(i=nc-1;i>=0;i--)
        fout<<c[i];
    fout<<'\n';
}

void suma (NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc)
{
    fillzero(a,na);
    fillzero(b,nb);
    fillzero(c,0);
    int i,t=0,v;
    for(i=0;i<na||i<nb||t;i++)
    {
        v=a[i]+b[i]+t;
        c[i]=v%10;
        t=v/10;
    }
    nc=i;
}

void fillzero(NRMARE a, int na)
{
    int i;
    for(i=na;i<LGMAX;i++)
        a[i]=0;
}

void prodint (NRMARE a, int na, int b, NRMARE c, int &nc)
{
    if(ezero(a,na)||!b)
    {
        nc=1;
        c[0]=0;
        return ;
    }
    int i, T=0,prod;
    for(i=0;i<na;i++)
    {
        prod=a[i]*b+T;
        c[i]=prod%10;
        T=prod/10;
    }
    nc=na;
    while (T)
    {
        c[nc]=T%10;
        T/=10;
        nc++;
    }
}

int ezero(NRMARE a, int na)
{
    return (na==1&& a[0]==0);
}
