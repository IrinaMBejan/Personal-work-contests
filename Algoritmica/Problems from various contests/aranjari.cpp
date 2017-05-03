#include <fstream>
#define Nmax 305
using namespace std;
ifstream fin("aranjari.in");
ofstream fout("aranjari.out");
typedef short int NRMARE[Nmax];

NRMARE Nr[2][105];
int lgN[2][105];
int N,k;
NRMARE Rez1,Rez2,Sum;
int lgRez1, lgRez2,lgSum;
void suma(NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc);
void prodscal(NRMARE a, int na, int k, NRMARE c, int &nc);
void init1(NRMARE a, int &na, int val);
void copie(NRMARE a, int na, NRMARE b, int &nb);
void afisare(NRMARE a, int na);

int main()
{
    fin>>N>>k;
    int lp=0,lc=1;
    init1(Nr[0][1],lgN[0][1],1);
    int i,j;
    for(i=4;i<=N;i++)
    {
        for(j=1;j<=k;j++)
        {
            prodscal (Nr[lp][j], lgN[lp][j], 2*j, Rez1, lgRez1);
            prodscal (Nr[lp][j-1], lgN[lp][j-1], i+1-2*j, Rez2, lgRez2);
            suma(Rez1,lgRez1,Rez2,lgRez2,Nr[lc][j],lgN[lc][j]);
        }
        lp=1-lp;
        lc=1-lc;
    }
    init1(Sum,lgSum,0);
    for(i=1;i<=k;i++)
    {
        suma(Sum,lgSum,Nr[lp][i],lgN[lp][i], Rez1,lgRez1);
        copie(Rez1,lgRez1, Sum,lgSum);
    }
    afisare(Sum,lgSum);
    return 0;
}

void fillzero(NRMARE a, int na)
{
    int i;
    for(i=na;i<Nmax;i++)
        a[i]=0;
}
void suma(NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc)
{
    fillzero(a,na);
    fillzero(b,nb);
    int i,T=0;
    for(i=0;i<na||i<nb||T;i++)
    {
        c[i]=a[i]+b[i]+T;
        T=c[i]/10;
        c[i]%=10;
    }
    nc=i;
}

void init1(NRMARE a, int &na,int val)
{
    na=1;
    a[0]=val;
}

void prodscal(NRMARE a, int na, int k, NRMARE c, int &nc)
{
    int i, T=0;
    for(i=0;i<na;i++)
    {
        c[i]=a[i]*k+T;
        T=c[i]/10;
        c[i]%=10;
    }
    nc=i;
    while(T)
    {
        c[nc++]=T%10;
        T/=10;
    }

}

void copie(NRMARE a, int na, NRMARE b, int &nb)
{
    int i;
    for(i=0;i<na;i++)
        b[i]=a[i];
    nb=na;
}

void afisare(NRMARE a, int na)
{
    int i;
    for(i=na-1;i>=0;i--)
        fout<<a[i];
    fout<<'\n';
}

