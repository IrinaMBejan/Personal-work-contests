#include <cstdio>

using namespace std;
FILE* fin=fopen("boltz.in","r");
FILE* fout=fopen("boltz.out","w");

bool a[350001];
int main()
{
    int N,M,i,tip,nr,j;
    fscanf(fin,"%d %d",&N,&M);
    for(i=1;i<=M;i++)
    {
        fscanf(fin,"%d %d",&tip,&nr);
        if(tip==1)
        {
            for(j=nr;j<=N;j+=nr)
                a[j]=1;
        }
        else if(tip==2)
        {
            if(a[nr]==1) fprintf(fout,"BOLTZ\n");
            else fprintf(fout,"%d\n",nr);
        }
    }
    return 0;
}
