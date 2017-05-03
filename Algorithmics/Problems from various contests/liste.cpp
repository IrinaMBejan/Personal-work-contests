#include <cstdio>

using namespace std;
FILE* fin=fopen("liste.in","r");
FILE* fout=fopen("liste.out","w");

bool stiva[100002][124];
int main()
{
    int N,i,j,k=1,nr=0,x,ok,q;
    fscanf(fin,"%d",&N);
    fscanf(fin,"%d",&x);
    for(j=1;j<=x;j++)
    {
        fscanf(fin,"%d",&q);
        stiva[k][q]=1;
    }
    for(i=2;i<=N;i++)
    {
        fscanf(fin,"%d",&x);
        k++;
        ok=0;
        for(j=1;j<=x;j++)
        {
            fscanf(fin,"%d",&q);
            stiva[k][q]=1;
            if(stiva[k-1][q]==1) ok=1;
        }
        while(ok==1)
        {
            ok=0;
            for(j=0;j<=120;j++)
            {
                nr++;
                if(stiva[k][j]==1)
                {
                    stiva[k-1][j]=1;
                    if(stiva[k-2][j]==1)
                        ok=1;
                    stiva[k][j]=0;
                }
            }
            k--;
        }
    }
    fprintf(fout,"%d\n",nr);
    return 0;
}
