#include <fstream>
#include<cstring>
#define LGMAX 1505
using namespace std;

typedef short int NRMARE[LGMAX];
ifstream fin("culori1.in");
ofstream fout("culori1.out");
NRMARE A[2],Al[2],R[2],V[2],G[2];
int a[2],al[2],r[2],v[2],g[2];
NRMARE sol;
int nrsol;
void suma (NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc);
void afisare(NRMARE c, int nc);
void egalitate(NRMARE a, int &na, NRMARE b, int nb);
int N;
void Citire();
void Dinamica();
void SumSol();
int prev,next;

int main()
{
    Citire();
    Dinamica();
    SumSol();
    afisare(sol,nrsol);
    return 0;
}

void Citire()
{
    fin>>N;
}

void Dinamica()
{
    A[0][0]=Al[0][0]=R[0][0]=V[0][0]=1;
    a[0]=al[0]=r[0]=v[0]=1;
    int i;
    prev=0;
    next=1;
    for(i=2; i<=N; i++)
    {
        egalitate(A[next],a[next],Al[prev],al[prev]);
        suma(A[prev],a[prev],R[prev], r[prev],Al[next],al[next]);
        next=1-next;
        prev=1-prev;
    }
}

void SumSol()
{
    int i,t=0,val;
    int lg=a[prev];
    if(lg<al[prev]) lg=al[prev];
    if(lg<r[prev]) lg=r[prev];
    if(lg<v[prev]) lg=v[prev];
    if(lg<g[prev]) lg=g[prev];

    for(i=0; i<lg||t; i++)
    {
        val=A[prev][i]+Al[prev][i]+Al[prev][i]+R[prev][i]+A[prev][i]+t;
        sol[i]=val%10;
        t=val/10;
    }
    nrsol=i;
}

void suma (NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc)
{
    int i,t=0,v;
    for(i=0; i<na||i<nb||t; i++)
    {
        v=a[i]+b[i]+t;
        c[i]=v%10;
        t=v/10;
    }
    nc=i;
}

void egalitate(NRMARE a, int &na, NRMARE b, int nb)
{
    int i;
    for(i=0; i<nb; i++)
        a[i]=b[i];
    na=nb;
}


void afisare(NRMARE c, int nc)
{
    int i;
    for(i=nc-1; i>=0; i--)
        fout<<c[i];
    fout<<'\n';
}
