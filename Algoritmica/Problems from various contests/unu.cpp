#include <cstdio>
#define KMAX 200003
using namespace std;

FILE* fin=fopen("unu.in","r");
FILE* fout=fopen("unu.out","w");

int b[KMAX];
int main()
{
    int n,T=0,i;
    fscanf(fin,"%d",&n);
    for(i=1;i<=n;i++)
    {
        b[i]=i+T;
        T=b[i]/10;
        b[i]%=10;
    }
    for(i=n+1;i<=2*n-1;i++)
    {
        b[i]=2*n-i+T;
        T=b[i]/10;
        b[i]%=10;
    }
    for(i=2*n-1;i>=1;i--)
            fprintf(fout,"%d",b[i]);
    fprintf(fout,"\n");

    return 0;
}
