#include <fstream>
#include<cstring>
#define LGMAX 40

typedef short int NRMARE[LGMAX];
using namespace std;
ifstream fin("set.in");
ofstream fout("set.out");

NRMARE x,y;
int nx,ny;
void citire(NRMARE a, int& na);
void prodint (NRMARE a, int& na, int b);
void afisare(NRMARE c, int nc);
int n;

int main()
{
    citire(x,nx);
    prodint(x,nx,n-1);
    afisare(x,nx);
    prodint(x,nx,n+1);
    afisare(x,nx);
    return 0;
}


void citire(NRMARE a, int& na)
{
    int i;
    char s[LGMAX];
    fin>>s;
    na=strlen(s);
    for(i=na-1;i>=0;i--)
    {
        a[i]=s[na-i-1]-'0';
        n=(n*10)+s[na-i-1]-'0';
    }
}

void afisare(NRMARE c, int nc)
{
    int i;
    for(i=nc-1;i>=0;i--)
        fout<<c[i];
    fout<<'\n';
}

void prodint (NRMARE a, int& na, int b)
{
    if(!b)
    {
        na=1;
        a[0]=0;
        return ;
    }
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

