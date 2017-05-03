#include <fstream>
#define LGMAX 201
typedef short int NRMARE[LGMAX];

using namespace std;
ifstream fin("chimie1.in");
ofstream fout("chimie1.out");
NRMARE nr1[2],nr2[2];
int nnr1[2],nnr2[2];


void suma (NRMARE a, NRMARE b);
void afisare(NRMARE c);
void prodint (NRMARE a, int b);
void transcrie(NRMARE a, NRMARE  b);
int ezero(NRMARE a)
{
    return (a[0]==1&& a[1]==0);
}

int main()
{
    int n,p,i,succ=1,last=0;
    fin>>n>>p;
    nnr1[0]=nnr2[0]=1;
    nr1[last][0]=nr2[last][0]=1;
    nr1[last][1]=2;
    nr2[last][1]=n-2;
    for(i=1;i<p;i++)
        {
            transcrie(nr1[succ],nr1[last]);
            suma(nr1[succ],nr2[last]);
            suma(nr1[succ],nr2[last]);

     //       nr1=lastnr1+2*lastnr2;
            prodint(nr1[last],n-2);
            prodint(nr2[last],n-2);
            transcrie(nr2[succ],nr1[last]);
            suma(nr2[succ],nr2[last]);
       //     nr2=(n-2)*lastnr1+(n-2)*lastnr2;
            succ=!succ;
            last=!last;
        }
    //fout<<nr1+nr2<<'\n';
    suma(nr1[last],nr2[last]);
    afisare(nr1[last]);
    return 0;
}


void suma (NRMARE a, NRMARE b)
{
    int i,t=0,v;
    for(i=1;i<=a[0]||i<=b[0]||t;i++)
    {
        v=a[i]+b[i]+t;
        a[i]=v%10;
        t=v/10;
        //util pentru punerea rezultatului in unul din vectorii a si b
    }
    a[0]=i-1;
}

void afisare(NRMARE c)
{
    int i;
    for(i=c[0];i>=1;i--)
        fout<<c[i];
    fout<<'\n';
}

void transcrie(NRMARE a, NRMARE b)
{
    int i;
    for(i=1;i<=b[0];i++)
        a[i]=b[i];
    a[0]=b[0];
}

void prodint (NRMARE a, int b)
{
    if(ezero(a)||!b)
    {
        a[0]=1;
        a[1]=0;
        return ;
    }
    int i, T=0,prod;
    for(i=1;i<=a[0];i++)
    {
        prod=a[i]*b+T;
        a[i]=prod%10;
        T=prod/10;
    }
    while (T)
    {
        a[++a[0]]=T%10;
        T/=10;
    }
}
// nr1[i] = numarul de moduri in care pot fi umplute corect eprubetele 1,2,..,i (i<p) cu substante chimice astfel incat eprubeta i sa fie umpluta cu substanta x sau cu substanta y
//nr2[i] = numarul de moduri in care pot fi umplute corect eprubetele 1,2,..,i (i<p) cu substante chimice astfel incat eprubeta i sa fie umpluta cu orice substanta din cele n disponibile in afara de substanta x si de substanta y
