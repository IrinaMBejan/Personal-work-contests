#include <fstream>
#include<cstring>
#define LGMAX 2100

using namespace std;
typedef short int NRMARE[LGMAX];
ifstream fin("fib.in");
ofstream fout("fib.out");

NRMARE x,y,z;
int nx,ny,nz;
void suma (NRMARE a, int &na, NRMARE b, int &nb, NRMARE c, int &nc);
void trans(NRMARE a, int na, NRMARE b, int nb, NRMARE c, int nc);


void afisare(NRMARE c, int nc);

int main()
{
    int q,q2,i;
    fin>>q;
    if(q==1||q==2) fout<<"1";
    else
    {
        nx=1;
        x[0]=1;
        q2=1;
        while(q2+ny<q)
        {

            q2+=ny;
            suma(x,nx,y,ny,z,nz);
        }
        int lim=q-q2;
        fout<<y[ny-lim]<<'\n';
    }
    return 0;
}


void trans(NRMARE a, int na, NRMARE c, int &nc)
{
    int i;
    nc=na;
    for(i=0; i<nc; i++)
        c[i]=a[i];
}


void suma (NRMARE a, int &na, NRMARE b, int &nb, NRMARE c, int &nc)
{
    int i,t=0,v;
    trans(b,nb,c,nc);
    for(i=0; i<na||i<nb||t; i++)
    {
        v=a[i]+b[i]+t;
        b[i]=v%10;
        t=v/10;
    }
    nb=i;
    trans(c,nc,a,na);
}

void afisare(NRMARE c, int nc)
{
    int i;
    for(i=nc-1; i>=0; i--)
        fout<<c[i];
}
