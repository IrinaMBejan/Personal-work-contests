#include <fstream>
#include<cstring>
#define LGMAX 201
using namespace std;

typedef short int NRMARE[LGMAX];
ifstream fin("sumb.in");
ofstream fout("sumb.out");
NRMARE x,y,z,rez1;
int nx,ny,nz,nrez1;

void citire(NRMARE a, int& na);
void suma (NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc,int base);

int main()
{
    int ok;
   citire(x,nx);
   citire(y,ny);
   citire(z,nz);
   int j;
   for(int i=2;i<=256;i++)
   {
        suma(x,nx,y,ny,rez1,nrez1,i);
       ok=1;
       for(j=0;j<nz&&ok;j++)
            if(z[j]!=rez1[j]) ok=0;
        if(ok) {fout<<i<<'\n'; return 0;}
   }
   fout<<"0"<<'\n';
    return 0;
}

void suma (NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc, int base)
{
    int i,t=0,v;
    for(i=0;i<na||i<nb||t;i++)
    {
        v=a[i]+b[i]+t;
        c[i]=v%base;
        t=v/base;
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
