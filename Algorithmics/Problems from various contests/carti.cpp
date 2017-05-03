#include <fstream>
#include <iomanip>

#define Nmax 105
typedef short int NRMARE[Nmax];

using namespace std;
ifstream fin("carti.in");
ofstream fout("carti.out");
NRMARE T[Nmax][Nmax];
int lgT[Nmax][Nmax];
int v[Nmax];
int N;
int S;
NRMARE rez,rez1;
int lgr,lgr1;

void suma (NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc);
void afisare(NRMARE c, int nc);
void init1(NRMARE x, int& lgx);
void fillzero(NRMARE a, int na);
void prodmare(NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc);
void copie (NRMARE a, int na, NRMARE b, int &nb);

int main()
{
    fin>>N;
    int i,j;
    for(i=1;i<=N;i++)
        {
            fin>>v[i];
            S+=v[i];
        }

    init1(T[0][0],lgT[0][0]);
    init1(T[0][1],lgT[0][1]);
    init1(T[1][0],lgT[1][0]);

    for (i = 2; i <=S; i++)
    	{
    	 init1(T[i][i],lgT[i][i]);

    	 for (j=1; j<i; j++)
    	        {
    	            suma(T[i-1][j],lgT[i-1][j],T[i-1][j-1],lgT[i-1][j-1],T[i][j],lgT[i][j]);
    	           // afisare(T[i][j],lgT[i][j]);
    	        }
    	}
    init1(T[1][1],lgT[1][1]);
    init1(rez,lgr);
    for(i=1;i<=N;i++)
    {
        S-=v[i-1];
        prodmare(rez,lgr,T[S][v[i]],lgT[S][v[i]],rez1,lgr1);
        copie(rez1,lgr1,rez,lgr);
    }

    afisare(rez,lgr);
    fout<<'\n';
    return 0;
}

void copie (NRMARE a, int na, NRMARE b, int &nb)
{
    int i;
    for(i=0;i<na;i++)
        b[i]=a[i];
    nb=na;
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
    for(i=na;i<Nmax;i++)
        a[i]=0;
}

int ezero(NRMARE a, int na)
{
    return (na==1&& a[0]==0);
}

void prodmare(NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc)
{
    nc=0;
   fillzero(c,nc);
   int i,j;
   if(ezero(a,na)||ezero(b,nb))
   {
       nc=1; c[0]=0;
       return ;
   }
   for(i=0;i<na; i++)
       for(j=0;j<nb;j++)
       {
           c[i+j]+=a[i]*b[j];
           c[i+j+1]+=c[i+j]/10;
           c[i+j]%=10;
       }
    for(i=0;i<Nmax-1;i++)
    {
        c[i+1]+=(c[i]/10);
        c[i]%=10;
    }
    nc=Nmax;//calculez nc
    while(!c[nc-1])  nc--;
}
