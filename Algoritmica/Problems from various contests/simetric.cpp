#include <fstream>

using namespace std;
ifstream fin("simetric.in");
ofstream fout("simetric.out");
int a[202];
int main()
{
    int n,i,k,nr,ok=0,mij;
    fin>>n;
    for(i=1;i<=n;i++)
        fin>>a[i];
    k=0;
    while(ok==0)
    {
        for(i=1;i<=k;i++)
            a[n+k-i+1]=a[i];
        ok=1;
        for(i=1;i<=n+k;i++)
            if(a[i]!=a[n+k-i+1]) ok=0;
        if(ok==0) k++;

    }
    fout<<k<<'\n';
    if(k)
    {
    for(i=1;i<=k;i++)
        fout<<a[n+i]<<" ";
    }
    fout<<'\n';
    return 0;
}
