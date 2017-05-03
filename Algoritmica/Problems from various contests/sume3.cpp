#include <cstdio>
#define Nmax 100001
#include<algorithm>
#include<cmath>
using namespace std;
FILE* fin=fopen("suma3.in","r");
FILE* fout=fopen("suma3.out","w");

int x;
struct suma
{
    long long int S;
    int q;
} z[Nmax];

int compare(suma a, suma b)
{
    return a.S<b.S;
}
int main()
{
    int n,i;
    long long int max,st,fi;
    fscanf(fin,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fin,"%lld",&x);
        z[i].S=z[i-1].S+x;
        z[i].q=i;
    }
    sort(z+0,z+n+1,compare);
    max=9999999999;
    for(i=1; i<n; i++)
        if(fabs((double)z[i].S-z[i-1].S)<max)
        {
            max=fabs((double)z[i].S-z[i-1].S);
            if(z[i-1].q<z[i].q)
            {
                st=z[i-1].q;
                fi=z[i].q;
            }
            else
            {
                st=z[i].q;
                fi=z[i-1].q;
            }
        }
    fprintf(fout,"%lld %lld %lld\n",max,st+1,fi);
    return 0;
}
