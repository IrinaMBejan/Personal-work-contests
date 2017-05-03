#include <fstream>
#include<cstring>
#define LGMAX 201
using namespace std;

typedef short int NRMARE[LGMAX];
ifstream fin("nrmar.in");
ofstream fout("nrmar.out");
NRMARE x,y,z;
int nx,ny,nz;

//void fillzero(NRMARE a, int na);
//void diferenta (NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc);
//void suma (NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc);
//void citire(NRMARE a, int& na);
//void afisare(NRMARE c, int nc);
//void prodint (NRMARE a, int na, int b, NRMARE c, int &nc);
//int ezero(NRMARE a, int na);
void prodmare(NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc);
void impartint(NRMARE a, int na, int b, NRMARE c, int &nc, int&rest);



int main()
{
    int i,b,rest;
    citire(x,nx);
    fin>>b;
    afisare(x,nx);
    citire(y,ny);
    afisare(y,ny);
    impartint(x,nx,b,z,nz,rest);
    afisare(z,nz);
    fout<<'\n'<<rest;
    return 0;
}
void fillzero(NRMARE a, int na)
{
    int i;
    for(i=na;i<LGMAX;i++)
        a[i]=0;
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
    fout<<'\n';
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

int ezero(NRMARE a, int na)
{
    return (na==1&& a[0]==0);
}

void prodint (NRMARE a, int na, int b, NRMARE c, int &nc)
{
    if(ezero(a,na)||!b)
    {
        nc=1;
        c[0]=0;
        return ;
    }
    int i, T=0,prod;
    for(i=0;i<na;i++)
    {
        prod=a[i]*b+T;
        c[i]=prod%10;
        T=prod/10;
    }
    nc=na;
    while (T)
    {
        c[nc]=T%10;
        T/=10;
        nc++;
    }

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
    for(i=0;i<LGMAX-1;i++)
    {
        c[i+1]+=(c[i]/10);
        c[i]%=10;
    }
    nc=LGMAX;//calculez nc
    while(!c[nc-1])  nc--;
}

void impartint(NRMARE a, int na, int b, NRMARE c, int &nc, int&rest)
{
    if(!b) return ;
    int i,t=0;
    for(i=na-1;i>=0;i--)
    {
        t=t*10+a[i];
        c[i]=t/b;
        t=t%b;
    }
    for(nc=na;c[nc-1]==0&&nc>1;nc--);
    rest=t;
}

int comp(NRMARE a, int na, NRMARE b, int nb)//--
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
