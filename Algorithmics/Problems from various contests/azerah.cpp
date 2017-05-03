#include <cstdio>
#define Nmax 1000005
#define MOD 1000000007
using namespace std;
FILE* fin=fopen("azerah.in","r");
FILE* fout=fopen("azerah.out","w");
int T,N;
long long int p[Nmax], im[Nmax];
int main()
{
    fscanf(fin,"%d",&T);
    int i;
    long long int x;
    while(T)
    {
        fscanf(fin,"%d",&N);
        fscanf(fin,"%lld",&x);
        p[1]=im[1]=0;
        if(x%2==0) p[1]=1;
        else im[1]=1;
        for(i=2;i<=N;++i)
        {
            fscanf(fin,"%lld",&x);
            if(x%2==0)
            {
                p[i]=(2*p[i-1]+1)%MOD;
                im[i]=(2*im[i-1])%MOD;
            }
            else
            {
                p[i]=(im[i-1]+p[i-1])%MOD;
                im[i]=(p[i-1]+im[i-1]+1)%MOD;
            }
        }
        fprintf(fout,"%lld\n",p[N]);
        --T;
    }
        return 0;
}
