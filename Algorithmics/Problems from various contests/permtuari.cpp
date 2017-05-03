#include <iostream>
#include<fstream>
#define Nmax 21
using namespace std;

bool uz[Nmax];
int vec[Nmax];
int n,m;
int z=0,nro;
ofstream fout("a.out");
void perm(int k, int m)
{
    if(k-1==m)
    {
        for(int i=1; i<=m; i++)
            fout<<vec[i]<<" ";
        fout<<'\n';
    }
    for(int i=1; i<=n; i++)
        if(uz[i]==0)
        {
            uz[i]=1;
            vec[k]=i;
            perm(k+1,m);
            uz[i]=0;
        }
}
int main()
{
    cin>>n>>m;
    perm(1,m);
    return 0;
}

