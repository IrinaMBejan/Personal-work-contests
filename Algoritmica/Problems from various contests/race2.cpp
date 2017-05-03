#include <fstream>
#define Nmax 305
using namespace std;
ifstream fin("race.in");
ofstream fout("race.out");
typedef short int NRMARE[Nmax];

NRMARE S[2][105];
int lgS[2][105];

NRMARE P, Pr, Rez;
int lgP, lgPr, lgRez;
int N;
void init1(NRMARE a, int &na);
void prodScalar(NRMARE a, int na, int k, NRMARE c, int &nc);
void suma(NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc);
void afisare(NRMARE a, int na);
void copie(NRMARE a, int na, NRMARE b, int &nb);
int main()
{
    fin>>N;
    int lp=0, lc=1;
    int i,k;
    init1(S[0][1],lgS[0][1]);
    for(i=2;i<=N;i++)
    {
        init1(S[lc][1],lgS[lc][1]);
        init1(S[lc][i], lgS[lc][i]);

        for(k=2;k<i;k++)
        {
            prodScalar(S[lp][k],lgS[lp][k], k, Pr, lgPr);
            suma(S[lp][k-1],lgS[lp][k-1],Pr,lgPr,S[lc][k],lgS[lc][k]);
        }
        lp=1-lp;
        lc=1-lc;
    }
    lgP=1;
    int j;
    for(k=1;k<=N;k++)
    {
        copie(S[lp][k],lgS[lp][k], Pr, lgPr);
        for(j=2;j<=k;j++)
        {
            prodScalar(Pr,lgPr, j, Rez, lgRez);
            copie(Rez,lgRez, Pr, lgPr);
        }

        suma(P,lgP, Pr, lgPr, Rez, lgRez);
        copie(Rez,lgRez, P, lgP);
    }

    afisare(P,lgP);
    return 0;
}

void copie(NRMARE a, int na, NRMARE b, int &nb)
{
    int i;
    for(i=0;i<na;i++)
        b[i]=a[i];
    nb=na;
}

void init1(NRMARE a, int &na)
{
    na=1;
    a[0]=1;
}

void prodScalar(NRMARE a, int na, int k, NRMARE c, int &nc)
{
    int i, T=0;
    for(i=0;i<na;i++)
    {
        c[i]= a[i]*k+T;
        T=c[i]/10;
        c[i]%=10;
    }
    nc=i;
    while(T)
    {
        c[nc++]=T%10; T/=10;
    }
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
    fillzero(c,nc);
    int i, T=0;
    for(i=0; i<na||i<nb||T;i++)
    {
        c[i] = a[i]+b[i]+T;
        T=c[i]/10;
        c[i]%=10;
    }
    nc=i;
}

void afisare(NRMARE a, int na)
{
    int i;
    for(i=na-1;i>=0;i--)
        fout<<a[i];
    fout<<'\n';
}
