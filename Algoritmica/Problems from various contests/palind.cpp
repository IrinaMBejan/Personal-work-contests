#include <cstdio>
#include<algorithm>
#define Nmax 10005
using namespace std;
FILE* fin=fopen("palind.in","r");
FILE* fout=fopen("palind.out","w");

int A[Nmax];
int main()
{
    int teste, N,k;
    fscanf(fin,"%d",&teste);
    while(teste--)
    {
        nrmin=0;
        fscanf(fin,"%d",%N);
        for(i=1;i<=N;i++)
            fin>>A[i];
        sort(A+1,A+N+1);
        for(i=1;i<=N;i++)
            nrmin+=(A[N/2+1]-A[i]);
        fout<<nrmin<<" ";
        fout<<'\n';
    }
    return 0;
}
