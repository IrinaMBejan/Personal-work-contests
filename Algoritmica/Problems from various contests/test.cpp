#include <fstream>
#define LGMAX 401
using namespace std;
typedef short int NRMARE[LGMAX];
ifstream fin("test.in");
ofstream fout("test.out");
NRMARE x;
int nx;

void prodint (NRMARE a, int& na, int b);

void afisare(NRMARE c, int nc);
int main()
{
    int n,m,i;
    nx=1;
    x[0]=1;
    fin>>m>>n;
    for(i=1;i<=m;i++)
        prodint(x,nx,n);
    afisare(x,nx);
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
