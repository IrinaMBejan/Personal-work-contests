#include <cstdio>
#define DMAX 1000005

using namespace std;
FILE* fin=fopen("secvente2.in","r");
FILE* fout=fopen("secvente2.out","w");

int pos[DMAX];

int main()
{
    int N,lgmax,st,fi,x,i;
    fscanf(fin,"%d",&N);
    lgmax=0;
    for(i=1; i<=N; i++)
    {
        fscanf(fin,"%d",&x);
        st=x;
        fi=x;
        if(pos[x-1]!=0) st=pos[x-1];
        if(pos[x+1]!=0) fi=pos[x+1];
        pos[st]=fi;
        pos[fi]=st;
        if(fi-st+1>lgmax) lgmax=fi-st+1;
        fprintf(fout,"%d\n",lgmax);
    }
    return 0;
}
