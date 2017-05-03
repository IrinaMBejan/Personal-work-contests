#include <fstream>
#define LGMAX 105
using namespace std;
ifstream fin("red.in");
ofstream fout("red.out");

typedef short int NRMARE[LGMAX];
NRMARE ic;
int nc;

void combo(int, int);
void afisare(NRMARE c, int nc);
void prodint (NRMARE a, int &na, int b);
void impartint(NRMARE a, int &na, int b);
void afisare(NRMARE c, int nc);

int main()
{
    int n,m;
    fin>>n>>m;
    combo(n-m, m);
    prodint(ic,nc,n);
    impartint(ic,nc,n-m);
    afisare(ic,nc);
    return 0;
}

void combo(int in, int ir)
{
    if (ir < 0 || ir > in)
     return;
    int i;
    for(i=0;i<nc;i++)
        ic[i]=0;
    ic[0]=1;
    nc=1;
    i = 0; int con;
    while (i < ir)
    {
        i++;
        con=in-i+1;
        prodint(ic,nc,con);
        impartint(ic,nc,i);
    }
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

void afisare(NRMARE c, int nc)
{
    int i;
    for(i=nc-1;i>=0;i--)
        fout<<c[i];
    fout<<'\n';
}


