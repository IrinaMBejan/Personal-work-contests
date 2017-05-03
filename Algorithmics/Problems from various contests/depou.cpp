#include <fstream>
#define Nmax 505
using namespace std;
ifstream fin("depou.in");
ofstream fout("depou.out");

typedef short int NRMARE[Nmax];
NRMARE T[2][305];
int lgT[2][305];
void init1(NRMARE a, int &na);
void afisare(NRMARE a, int na);
void suma(NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc);
void diferenta(NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc);
NRMARE Cata;
int lgcat;
int N;

int main()
{
    fin>>N;
    int i,j;
    init1(T[0][0],lgT[0][0]);
    init1(T[0][1],lgT[0][1]);
    init1(T[1][0],lgT[1][0]);

    int lc=1, lp=0;

    for(i=2;i<=2*N;i++)
    {
        init1(T[lc][i],lgT[lc][i]);
        for(j=1;j<i;j++)
                suma(T[lp][j], lgT[lp][j], T[lp][j-1],lgT[lp][j-1], T[lc][j], lgT[lc][j]);

        lp = 1-lp;
        lc = 1-lc;
    }

    diferenta(T[lp][N], lgT[lp][N], T[lp][N-1], lgT[lp][N-1], Cata, lgcat);
    afisare(Cata,lgcat);
    return 0;
}

void init1(NRMARE a, int &na)
{
    na=1;
    a[0]=1;
}

void afisare(NRMARE a, int na)
{
    int i;
    for(i=na-1;i>=0;i--)
        fout<<a[i];
    fout<<'\n';
}

void suma(NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc)
{

    int i, T=0;
    for(i=0; i<na || i<nb || T;i++)
    {
        c[i] = a[i]+b[i]+T;
        T=c[i]/10;
        c[i]%=10;
    }
    nc=i;
}

void diferenta(NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc)
{
    int i,T=0;
    for(i=0;i<na;i++)
    {
        c[i] = a[i]-b[i]+T;
        if(c[i]<0) { c[i]+=10; T=-1;}
        else T=0;
    }
    nc=na;
    while(c[nc-1] == 0 && nc>1)
         nc--;
}


