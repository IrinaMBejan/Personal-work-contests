#include <cstdio>

using namespace std;
FILE* fin=fopen("predecesor.in","r");
FILE* fout=fopen("predecesor.out","w");

int stiva[500001];

int main()
{
    int N,k,nr,i,x;
    fscanf(fin,"%d",&N);
    fscanf(fin,"%d",&stiva[1]);
    k=1;
    nr=0;
    for(i=1;i<=N;i++)
    {
        fscanf(fin,"%d",&x);
        if(x<=stiva[k])
            stiva[++k]=x;
        else
        {
            stiva[k]=x;
            nr++;
        }
    }
    fprintf(fout,"%d\n",N-nr);
    return 0;
}
