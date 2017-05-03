#include <fstream>
#include<cstring>
#define LGMAX 201
using namespace std;

typedef short int NRMARE[LGMAX];
ifstream fin("descfib.in");
ofstream fout("descfib.out");

struct a
{
    NRMARE a;
    int na;
    bool ok;
} sir[501];

NRMARE N;
int nn;

void diferenta (NRMARE a, int &na, NRMARE b, int nb);
void suma (NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc);
void citire(NRMARE a, int& na);
int comp(NRMARE a, int na, NRMARE b, int nb);
void afisare(NRMARE c, int nc);
int main()
{
    int i;
    citire(N,nn);
    i=2;
    sir[0].a[0]=0;
    sir[0].na=1;
    sir[1].a[0]=1;
    sir[1].na=1;
    int nr=0;
    while(comp(N,nn,sir[i-1].a,sir[i-1].na)==1)
    {
        suma(sir[i-1].a,sir[i-1].na,sir[i-2].a,sir[i-2].na,sir[i].a,sir[i].na);
        i++;
    }
    int k;
    for(k=i-1;k>0;k--)
        if(comp(N,nn,sir[k].a,sir[k].na)==1||comp(N,nn,sir[k].a,sir[k].na)==0)
            {
                diferenta(N,nn,sir[k].a,sir[k].na);
                sir[k].ok=1;
                nr++;
            }
    fout<<nr<<'\n';
    for(k=1;k<=i;k++)
            if(sir[k].ok==1) afisare(sir[k].a,sir[k].na);

}



void suma (NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc)
{
    int i,t=0,v;
    for(i=0;i<na||i<nb||t;i++)
    {
        v=a[i]+b[i]+t;
        c[i]=v%10;
        t=v/10;
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
    fout<<'\n';
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



void diferenta (NRMARE a, int& na, NRMARE b, int nb)
{
        //a>=b;
        int T=0,i;
        for(i=0;i<na;i++)
        {
            a[i]=(a[i]-b[i]+T);
            if(a[i]<0) {a[i]+=10; T=-1;}
            else T=0;
        }
        while(a[na-1]==0&&na>1)
            na--;
}
