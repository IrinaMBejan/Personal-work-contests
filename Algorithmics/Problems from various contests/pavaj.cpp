#include <fstream>
#define LGMAX 301
using namespace std;

ifstream fin("pavaj.in");
ofstream fout("pavaj.out");

int d[251];
struct NRMARE
{
    int nr[LGMAX];
    int lung;
}x[701];
void suma (int a[LGMAX], int &na, int b[LGMAX], int nb);

int main()
{
    int n,L,i,k;
   fin>>L>>n;
   for(i=1;i<=n;i++)
        fin>>d[i];
    x[0].nr[0]=1;
    x[0].lung=1;
    for(k=1;k<=L;k++)
    {
        for(i=1;i<=n;i++)
            if(k-d[i]>=0)
            suma(x[k].nr,x[k].lung,x[k-d[i]].nr,x[k-d[i]].lung);
    }
    for(i=x[L].lung-1;i>=0;i--)
        fout<<x[L].nr[i];
    fout<<'\n';
    return 0;
}


void suma (int a[LGMAX], int &na, int b[LGMAX], int nb)
{
    int w,t=0,v;
    for(w=0;w<na||w<nb||t;w++)
    {
        v=a[w]+b[w]+t;
        a[w]=v%10;
        t=v/10;
    }
    na=w;
}


