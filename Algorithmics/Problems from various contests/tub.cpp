#include <fstream>
#define LGMAX 10101
using namespace std;
typedef short int NRMARE[LGMAX];

ifstream fin("tub.in");
ofstream fout("tub.out");

NRMARE x ;
int nx;
void prodint (NRMARE a, int &na, int b);
void afisare(NRMARE c, int nc);

int main()
{
    int n,i,T;
    nx=1;
    x[0]=1;
    fin>>n;
    for(i=1; i<=n-1; i++)
    {
        prodint(x,nx,2);
    }
    afisare(x,nx);
    return 0;
}


void prodint (NRMARE a, int& na, int b)
{
    int i, T=0, prod;
    for(i=0; i<na; i++)
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
    for(i=nc-1; i>=0; i--)
        fout<<c[i];
    fout<<'\n';
}
