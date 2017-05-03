#include <iostream>
#include<cstring>
#define LGMAX 105
using namespace std;

const int NMAX = 405;
typedef short int NRMARE[NMAX];
NRMARE res,x,y;
int nres,nx,ny;

void suma (NRMARE a, int& na, NRMARE b, int nb);
void copie(NRMARE a, int& na, NRMARE b, int nb);
void afisare(NRMARE c, int nc);
void prodint (NRMARE a, int& na, signed long long int b);
void impartint(NRMARE a, int& na, int b);

int main()
{
    int s,i;
    signed long long int n;

    cin>>s;

    for(i=1; i<=s;i++)
    {
        cin>>n;
        memset(res,0,sizeof(res));
        memset(y,0,sizeof(y));
        memset(x,0,sizeof(x));
        res[0] = x[0] = y[0]=1;
        nres = nx = ny = 1;

        prodint(y,ny,n);
        prodint(y,ny,(n-1));
        impartint(y,ny,2);

        copie(x,nx,y,ny);
        prodint(x,nx,(n-2));
        prodint(x,nx,(n-3));
        impartint(x,nx,12);

        suma(res,nres,x,nx);
        suma(res,nres,y,ny);

        afisare(res,nres);
    }
    return 0;
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


void impartint(NRMARE a, int& na, int b)
{
    int i,t=0;
    for(i=na-1;i>=0;i--)
    {
        t=t*10+a[i];
        a[i]=t/b;
        t=t%b;
    }
    for(;a[na-1]==0 && na>1; na--);

}

void afisare(NRMARE c, int nc)
{
    int i;
    for(i=nc-1;i>=0;i--)
        cout<<c[i];
    cout<<'\n';
}


void prodint (NRMARE a, int& na, signed long long int b)
{
    signed long long int i,v, T = 0;
    for(i = 0; i < na; i++)
    {
        v = a[i]*b+T;
        T = v/10;
        a[i] = v % 10;
    }

    while (T)
    {
        a[na]=T%10;
        T/=10;
        na++;
    }
}

void copie(NRMARE a, int& na, NRMARE b, int nb)
{
    int i; na = nb;
    for(i = 0; i<=nb;i++)
        a[i] = b[i];
}
