#include <fstream>
#define Nmax 505
using namespace std;
ifstream fin("race.in");
ofstream fout("race.out");
typedef short int NRMARE[Nmax];

NRMARE S[2][Nmax];
int lgS[2][Nmax];
NRMARE P,Rez,Pr;
int lgP,lgRez,lgPr;
void suma(NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc);
void prodscal(NRMARE a, int na, int k);
void init1(NRMARE a, int &na);
void copie(NRMARE a, int na, NRMARE b, int &nb);
void afisare(NRMARE a, int na);

int main()
{
    int N,i,k;
    fin>>N;
    int lp=0,lc=1;
    init1(S[1][1],lgS[1][1]);
    for(i=2;i<=N;i++)
    {
        init1(S[lc][1],lgS[lc][1]);
        init1(S[lc][i],lgS[lc][i]);

        for(k=2;k<i;k++)
            {
                prodscal(S[lp][k],lgS[lp][k],k);
                suma(S[lp][k-1],lgS[lp][k-1],Pr,lgPr,S[lc][k],lgS[lc][k]);

            }

        lp=1-lp;
        lc=1-lc;
    }

    lgP=1;
    int j;
    for(k=1;k<=N;k++)
    {
        copie(S[lp][k],lgS[lp][k],Pr,lgPr);
        for(j=1;j<=k;j++)
            prodscal(Pr,lgPr,j);
        suma(P,lgP, Pr,lgPr, Rez,lgRez);
        copie(Rez,lgRez, P, lgP);
    }

    afisare(P,lgP);
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

void init1(NRMARE a, int &na)
{
    na=1;
    a[0]=1;
}

void prodscal(NRMARE a, int na, int k)
{
    int i, T=0;
    for(i=0;i<na;i++)
    {
        Pr[i]=a[i]*k+T;
        T=Pr[i]/10;
        Pr[i]%=10;
    }
    lgPr=i;
    while(T)
    {
        Pr[lgPr++]=T%10;
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
