#include <fstream>
#include<cstring>
#define LGMAX 201
using namespace std;

typedef short int NRMARE[LGMAX];
ifstream fin("scor.in");
ofstream fout("scor.out");

NRMARE s,d,x,y;
int ns,nd,nx,ny;

int comp(NRMARE a, int na, NRMARE b, int nb);
void diferenta (NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc);
void suma (NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc);
void citire(NRMARE a, int& na);
void afisare(NRMARE c, int nc);
void impartint(NRMARE a, int& na, int b);
void fillzero(NRMARE a, int& na);
int main()
{
    int T,i;
    fin>>T;
    for(i=1;i<=T;i++)
    {
        fillzero(s,ns);
        fillzero(d,nd);
        fillzero(y,ny);
        fillzero(x,nx);
        citire(s,ns);
        citire(d,nd);
        diferenta(s,ns,d,nd,y,ny);
        suma(s,ns,d,nd,x,nx);
        if(comp(s,ns,d,nd)==-1||x[0]%2==1||y[0]%2==1) fout<<"impossible"<<'\n';
        else
        {
            impartint(y,ny,2);
            impartint(x,nx,2);
            afisare(x,nx);
            afisare(y,ny);
            fout<<'\n';
        }

    }return 0;
}


void fillzero(NRMARE a, int& na)
{
    int i;
    for(i=0;i<na;i++)
        a[i]=0;
    na=0;
}

int comp(NRMARE a, int na, NRMARE b, int nb)
{
    int i;
    if(na>nb) return 1;
    if(nb>na) return -1;
    i=na-1;
    while(a[i]==b[i]&&i>=0) i--;
    if (i==-1) return 0;
    if(a[i]>b[i]) return 1;
    return -1;
}

void impartint(NRMARE a, int &na, int b)
{
    int i,t;
    for(t=0,i=na-1;i>=0;i--)
    {
        t=t*10+a[i];
        a[i]=t/b;
        t=t%b;
    }
    while(a[na-1]==0&&na>1)na--;
}

void suma (NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc)
{
    int i,t=0,v;
    for(i=0;i<na||i<nb||t;i++)
    {
        v=a[i]+b[i]+t;
        c[i]=v%10;
        t=v/10;
        //util pentru punerea rezultatului in unul din vectorii a si b
    }
    nc=i;
}


void citire(NRMARE a, int& na)
{
    int i;
    char s[LGMAX];
    fin>>s;
    na=strlen(s);
    for(i=na-1;i>=0;i--)
        a[i]=s[na-i-1]-'0';
}

void afisare(NRMARE c, int nc)
{
    int i;
    for(i=nc-1;i>=0;i--)
        fout<<c[i];
    fout<<" ";
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
