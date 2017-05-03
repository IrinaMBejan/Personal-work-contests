#include <iostream>
#include<cstring>
#define NMAX 105
using namespace std;

const int nsize = 40;
const int dsize = 21;
typedef short int NRMARE[NMAX];
NRMARE c,numbers[nsize][dsize], results[nsize][dsize];
int lgc,lg[nsize][dsize],lres[nsize][dsize];

void suma (NRMARE a, int& na, NRMARE b, int nb);
void prodmare(NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc);
void diferenta (NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc);
void afisare(NRMARE c, int nc);
void gen_numbers();

int main()
{

    int n,d;
    gen_numbers();
    while(cin>>n>>d)
    {
        afisare(results[n][d],lres[n][d]);
    }
    return 0;
}


void diferenta (NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc)
{
        //a>=b;
        int T=0,i;
        for(i=0;i<na;i++)
        {
            c[i]=a[i]-b[i]+T;
            if(c[i]<0) {c[i]+=10; T=-1;}
            else T=0;
        }
        nc=na;
        while(c[nc-1]==0&&nc>1)
            nc--;
}
void fillzero(NRMARE a, int na)
{
    int i;
    for(i=na;i<NMAX;i++)
        a[i]=0;
}

int ezero(NRMARE a, int na)
{
    return (na==1&& a[0]==0);
}
void prodmare(NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc)
{
   fillzero(c,nc);
   int i,j,p1,p2;
   long int T=0;
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
       }//normalizam
    for(i=0;i<NMAX-1;i++)
    {
        c[i+1]+=(c[i]/10);
        c[i]%=10;
    }
    nc=NMAX;//calculez nc
    while(!c[nc-1])  nc--;
}

void gen_numbers()
{
    for (int d = 0; d < dsize; ++d)
        {
            numbers[0][d][0] = 1;
            lg[0][d] = 1;
        }
    for (int n = 2; n < nsize; n += 2)
        for (int d = 1; d < dsize ; ++d)
            for (int i = 2; i <= n; i += 2)
                {
                    prodmare(numbers[i-2][d-1], lg[i-2][d-1], numbers[n-i][d], lg[n-i][d], c, lgc);
                    suma(numbers[n][d],lg[n][d],c,lgc);
                }
    for (int n = 1; n < nsize; ++n)
        for (int d = 1; d < dsize; ++d)
           diferenta(numbers[n][d],lg[n][d], numbers[n][d-1], lg[n][d-1], results[n][d],lres[n][d]);
}

void suma (NRMARE a, int& na, NRMARE b, int nb)
{
    int i,v, T = 0;
    for(i = 0; i < na || i < nb || T; i++)
    {
        v = a[i]+b[i]+T;
        T = v/10;
        a[i] = v % 10;
    }
    na = i;
}

void afisare(NRMARE c, int nc)
{
    int i;
    for(i=nc-1;i>=0;i--)
        cout<<c[i];
    cout<<'\n';
}
