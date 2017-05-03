#include <fstream>
#define NMAX 101
using namespace std;
ifstream fin("siruri1.in");
ofstream fout("siruri1.out");

int a[NMAX],ord[NMAX];
int main()
{
    int n,i,j,poz,nmax;
    fin>>n;
    for (i=1; i<=n; i++)
        fin>>a[i];
    for(i=n; i>=1; i--)
        {
            nmax=-1;
            for(j=1;j<=n;j++)
            if(a[j]>nmax) {nmax=a[j]; poz=j;}
            ord[poz]=i;
            a[poz]=-1;
        }

    for(i=1;i<=n;i++)
        fout<<ord[i]<<" ";
    return 0;
}
