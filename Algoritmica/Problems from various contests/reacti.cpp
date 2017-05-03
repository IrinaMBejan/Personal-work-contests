#include <fstream>

using namespace std;
FILE* fin=fopen("reactii.in","r");
FILE* fout=fopen("reactii.out","w");

struct stiva
{
    int min;
    int max;

} q[15001];

int unifica(int poz);

int main()
{
    int j,N,M,i,k;
    fscanf(fin,"%d %d",&N,&M);
    for(j=1; j<=M; j++)
    {
        fscanf(fin,"%d",&q[1].min);
        q[1].max=q[1].min;
        k=1;
        for(i=2; i<=N; i++)
        {
            k++;
            fscanf(fin,"%d",&q[k].min);
            q[k].max=q[k].min;
            while(unifica(k)&&k>1)
                k--;
        }
        if(k==1&&q[1].min==1&&q[1].max==N)
                fprintf(fout,"1\n");
        else fprintf(fout,"0\n");

        q[0].min=q[0].max=0;
    }
    return 0;
}

int unifica(int poz)
{
    if(q[poz].max==q[poz-1].min-1)
        q[poz-1].min=q[poz].min;
    else if(q[poz].min==q[poz-1].max+1)
        q[poz-1].max=q[poz].max;
    else return 0;
    return 1;
}
