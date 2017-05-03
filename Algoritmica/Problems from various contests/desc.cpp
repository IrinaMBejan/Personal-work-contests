#include <cstdio>
#define nrprim 10007
using namespace std;

FILE* fin = fopen("desc.in","r");
FILE* fout = fopen("desc.out","w");


long long int s[10005][10005];

int main()
{
    int n,m,k,x,i,j;
    fscanf(fin, "%ld%ld%ld", &n, &k, &x);
    s[1][1]=1;
    for(i=2; i <= n - x*k*(k-1)/2; i++)
        for(j = 1; j<= i; j++)
         s[i][j] = (s[i-1][j-1]+ s[i-1][j]*j) %10007;

    fprintf(fout,"%ld\n",s[n - x*k*(k-1)/2][k]);
    return 0;
}
