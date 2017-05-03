#include<cstdio>
#include<algorithm>
#define NMAX 10003000
#define VALmax 1000
using namespace std;
FILE* fin=fopen("tabara.in","r");
FILE* fout=fopen("tabara.out","w");

int e[NMAX],N;
int cautabin();

int main()
{
    int i;
    fscanf(fin,"%lld",&N);
    for(i=1; i<=N; i++)
    {
        fscanf(fin,"%lld",&e[i]);
    }
    sort(e+1,e+N+1);
    fprintf(fout,"%d\n",cautabin());
    return 0;
}

int check(int M)
{
    long long int S = 0;
    for(i=1;i<=N && M*N>=S;i++)
        S+=e[i];
    return  S<
}

int cautabin()
{
    int st=0,fi=e[N]+1,M,i;
    while(fi-st>1)
    {
        M=st+(fi-st)/2;
        if(check(M))
            st=M;
        else
            fi=M;
    }
    return st;
}
