#include <cstdio>

using namespace std;
FILE* fin=fopen("friends.in","r");
FILE* fout=fopen("friends.out","w");
int F,R;
int N;
int C,cmax=100000000,cs;
int mat[20][20], sol[20],uz[20];

void bkt(int k)
{
    if(k-1==N)
    {
        cs=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=N;j++)
                if(mat[i][j])
                {
                    if(sol[i]==j)
                        cs+=F*mat[i][j];
                    else
                        cs+=R*mat[i][j];
                }
        }
        if(cs<cmax) cmax=cs;
    }
    else
    {
        for(int i=1;i<=N;i++)
            if(uz[i]==0)
            {
                    sol[k]=i;
                    sol[i]=k;
                    uz[i]=1;
                    uz[k]=1;
                    int t=1;
                    while(uz[k+t]==1&&k+t<=N+1)
                        t++;
                    bkt(k+1);
                    uz[i]=0; uz[k]=0;
            }

        }
}

int main()
{
    int x,y,d;

    fscanf(fin,"%d %d",&F,&R);
    fscanf(fin,"%d",&N);
    fscanf(fin,"%d",&C);
    for(int i=1;i<=C;i++)
    {
        fscanf(fin,"%d %d %d\n",&x,&y,&d);
        mat[x][y]+=d;
    }
    bkt(1);
    fprintf(fout,"%d\n",cmax);
    return 0;
}
