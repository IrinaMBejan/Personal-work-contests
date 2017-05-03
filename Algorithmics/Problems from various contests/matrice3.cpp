#include <fstream>
#include <iomanip>
#include<cstring>
#define LGMAX 150
#define NMAX 501
using namespace std;

typedef short int NRMARE[LGMAX];
ifstream fin("matrice3.in");
ofstream fout("matrice3.out");
NRMARE T[2][NMAX];
int lgT[2][NMAX];
void suma (NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc);
void afisare(NRMARE c, int nc);
void init1(NRMARE x, int& lgx);
void fillzero(NRMARE a, int na);
int main()
{
    int i,j,n, lc, lp,w,m;
    fin>>w>>i>>j;
    if(j>i)
    {
        n=j;
        m=i;
    }
    else
    {
        n=i;
        m=j;

    }
    n--;
    init1(T[0][0],lgT[0][0]);
    init1(T[0][1],lgT[0][1]);
    init1(T[1][0],lgT[1][0]);
    lp=0; lc=1;
    for (i = 2; i <=n; i++)
    	{

    	 init1(T[lc][i],lgT[lc][i]);
    	 for (j=1; j<i; j++)
    	     suma(T[lp][j],lgT[lp][j],T[lp][j-1],lgT[lp][j-1],T[lc][j],lgT[lc][j]);
         lp=1-lp; lc=1-lc;
    	}
    afisare(T[lp][m-1], lgT[lp][m-1]);
	fout<<'\n';

    return 0;
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

void afisare(NRMARE c, int nc)
{
    int i;
    for(i=nc-1;i>=0;i--)
        fout<<c[i];
    fout<<' ';
}

void init1(NRMARE x, int& lgx)
{
lgx=1; x[0]=1;
}

void fillzero(NRMARE a, int na)
{
    int i;
    for(i=na;i<LGMAX;i++)
        a[i]=0;
}
