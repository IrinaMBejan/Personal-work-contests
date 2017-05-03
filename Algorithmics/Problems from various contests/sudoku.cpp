#include <fstream>
#include <cmath>
#define Nmax 100

using namespace std;
ifstream fin("sudoku1.in");
ofstream fout("sudoku1.out");


unsigned a[Nmax][Nmax];
unsigned long long n,k,p,i,j;

int main()
{
    fin>>n>>k;
    p=1LL<<(2*n-2);
    fout<<p*3<<'\n';
    k--;

    if(k<p)
        a[1][1]=1;
    else if(k<2*p)
                a[1][1]=2,k-=p;
            else
                a[1][1]=3,k-=2*p;
    p/=2;
    for(i=2;i<=n;i++)
        {
            if(k<p)
                a[1][i]=(a[1][i-1]==1?2:1);
            else
              a[1][i]=(a[1][i-1]<3?3:2),k-=p;
            p/=2;
        }
    for(i=2;i<=n;i++)
        {
            if(k<p)
                a[i][1]=(a[i-1][1]==1?2:1);
            else
                a[i][1]=(a[i-1][1]<3?3:2),k-=p;
            p/=2;
        }
    for(i=2;i<=n;i++)
        for(j=2;j<=n;j++)
            if(a[i-1][j]!=a[i][j-1])
                    a[i][j]=a[i-1][j-1];
            else
                    a[i][j]=6-a[i-1][j-1]-a[i-1][j];
    for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                fout<<a[i][j]<<' ';
            fout<<'\n';
        }
    return 0;
}

