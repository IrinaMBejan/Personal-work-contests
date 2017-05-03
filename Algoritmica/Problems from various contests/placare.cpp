#include <cstdio>

using namespace std;
FILE* fin=fopen("placare.in","r");
FILE* fout=fopen("placare.out","w");

int a[301],ma[2][301];
int main()
{
    int n,m,i,j,k,x;
    fscanf(fin,"%d %d",&n,&m);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(ma[1][j]>0)
            {
                fprintf(fout,"%d ",ma[0][j]);
                ma[1][j]--;
            }
            else
            {
                fscanf(fin,"%d",&x);
                if(x>=0)
                {
                    for(k=1; k<=x; k++)
                    {
                        fprintf(fout,"%d ",x);
                        j++;
                    }
                    j--;
                }
                else
                {
                    x*=(-1);
                    ma[0][j]=x;
                    ma[1][j]=x-1;
                    fprintf(fout,"%d ",x);
                }
            }
        }
        fprintf(fout,"\n");
    }
    return 0;
}
