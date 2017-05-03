#include <fstream>
#include<algorithm>
#include<cstring>
#define Nmax 15
using namespace std;
ifstream fin("jucarii.in");
ofstream fout("jucarii.out");

int perm[Nmax],lgmax[Nmax];
int main()
{
    int n,k,p,nr,i,j,ok;
    fin>>n>>k>>p;
    nr=0;
    for(i=1; i<=n; i++)
        perm[i]=i;

    while(nr<p)
    {

        //verif. perm. curenta
        memset(lgmax,0,sizeof(lgmax));
        lgmax[n]=1;
        ok=0; //retine daca s-a intalnit un LIS de min k;
        for(i=n-1; i>=1&&!ok; i--)
        {
            for(j=i+1; j<=n; j++)
                if(perm[i]<perm[j]&&lgmax[j]+1>lgmax[i]) lgmax[i]=lgmax[j]+1;
            if(lgmax[i]>=k) ok=1;
            if(lgmax[i]==0) lgmax[i]=1;
        }

        if(ok)
     //   {
            nr++;
       if(nr==p)
        {
            for(i=1; i<=n; i++)
                fout<<perm[i]<<" ";
            fout<<'\n';
        }
        //gen urm. perm
        next_permutation(perm+1,perm+n+1);
    }
    return 0;
}
