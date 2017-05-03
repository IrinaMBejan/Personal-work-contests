#include<cstdio>
#include<algorithm>
using namespace std;
FILE* fin=fopen("tabara.in","r");
FILE* fout=fopen("tabara.out","w");

long long int e[50001],N,profi;
int cautabin();
int main()
{
    int i;
    fscanf(fin,"%lld %lld",&N,&profi);
    for(i=1; i<=N; i++)
        fscanf(fin,"%lld",&e[i]);
    sort(e+1,e+N+1);
    fprintf(fout,"%d\n",cautabin());
    return 0;
}

int check(int M)
{
    long long int S=0;
    int i;
    for(i=1; i<=N; i++)
            if (e[i] < M)
                S+=M-e[i];
     return (S<=M&&S<=profi);
}
int cautabin()
{
    int st=0,fi=e[N]+profi+1,M,i;
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
