#include <fstream>
#define LGMAX 205

using namespace std;
typedef short int NRMARE[LGMAX];

ifstream fin("minm.in");
ofstream fout("minm.out");

int a[1001];

NRMARE rez,Rr;
int nrez,nRr;
void prodint (NRMARE a, int &na, int b);
void afisare(NRMARE c, int nc);
void suma (NRMARE a, int &na, NRMARE b, int nb);


int main()
{
    int k, n,R,x;
    int p,i,ok;
    fin>>R>>n;
    for(k=1; k<=n; k++)
    {

        fin>>x;
        p=0;
        ok=0;
        while (x%2==0)
        {
            x/=2;
            p++;
            ok++;
        }
        if(p>a[2]) a[2]=p;
        i=3;
        while (x>1)
        {
            if (i*i>x && !ok) break;
            p=0;
            while (x%i==0)
            {
                p++;
                ok++;
                x/=i;
            }

            if (p>a[i])
                a[i]=p;
            i+=2;
        }
        if(ok==0&&a[x]==0) a[x]=1;
    }
    nrez=1;
    rez[0]=1;
    for(i=2;i<=1000;i++)
        if(a[i])
            {
                for(k=1;k<=a[i];k++)
                    prodint(rez,nrez,i);
            }
    nRr=0;
    while(R>0)
    {
        Rr[nRr]=R%10;
        nRr++;
        R/=10;
    }
    suma(rez,nrez,Rr,nRr);
    afisare(rez,nrez);
        return 0;
    }

void prodint (NRMARE a, int &na, int b)
{
    int i, T=0,prod;
    for(i=0;i<na;i++)
    {
         prod=a[i]*b+T;
         a[i]=prod%10;
         T=prod/10;
    }
    while (T)
    {
        a[na]=T%10;
        T/=10;
        na++;
     }
}

void afisare(NRMARE c, int nc)
{
   int i;
   for(i=nc-1;i>=0;i--)
        fout<<c[i];
    fout<<'\n';
}

void suma (NRMARE a, int &na, NRMARE b, int nb)
{
    int i,t=0,v;
    for(i=0;i<na||i<nb||t;i++)
    {
        v=a[i]+b[i]+t;
        a[i]=v%10;
        t=v/10;
    }
    na=i;
}

