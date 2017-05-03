#include <cstdio>
#define NMAX 105
using namespace std;
FILE* fin=fopen("rj.in","r");
FILE* fout=fopen("rj.out","w");

int dl[8]= {-1,-1,0,1,1,1,0,-1};
int dc[8]= {0,1,1,1,0,-1,-1,-1};

int mat1[NMAX][NMAX],mat2[NMAX][NMAX];

struct pozitie
{
    int lin;
    int col;
} C[NMAX*NMAX],poz;

void Lee(int x, int y, int mat[NMAX][NMAX]);
int N,M;

int main()
{
    int i,j,val,x,y,xr,yr,xj,yj;
    char c;
    fscanf(fin,"%d %d\n",&N,&M);
    for(i=1; i<=N; i++)
    {
        for(j=1; j<=M; j++)
        {
            c=getc(fin);
            if(c=='X')
            {
                mat1[i][j]=-1;
                mat2[i][j]=-1;
            }
            else if(c=='R')
            {
                xr=i;
                yr=j;
            }
            else if(c=='J')
            {
                xj=i;
                yj=j;
            }
        }
        c=getc(fin);
    }
    for(i=0; i<=N+1; i++)
        mat1[i][0]=mat1[i][M+1]=mat2[i][0]=mat2[i][M+1]=-1;
    for(i=0; i<=M+1; i++)
        mat1[0][i]=mat1[N+1][i]=mat2[0][i]=mat2[N+1][i]=-1;

    /* for(i=0;i<=N+1;i++)
         {
             for(j=0;j<=M+1;j++)
                 fprintf(fout,"%d ",mat1[i][j]);
             fprintf(fout,"\n");
         }
    */
    Lee(xr,yr,mat1);
    Lee(sxj,yj,mat2);
    val=1000000;
    for(i=1; i<=N; i++)
        for(j=1; j<=M; j++)
            if(mat1[i][j]==mat2[i][j]&&mat1[i][j]<val&&mat1[i][j]>0)
            {
                val=mat1[i][j];
                x=i;
                y=j;
            }
    fprintf(fout,"%d %d %d\n",val,x,y);
    return 0;
}


void Lee(int x, int y, int mat[NMAX][NMAX])
{
    int st=1,fi=1;
    C[1].lin=x;
    C[1].col=y;
    mat[x][y]=1;
    while(st<=fi)
    {
        poz=C[st++];
        for(int k=0; k<=7; k++)
            if(mat[poz.lin+dl[k]][poz.col+dc[k]]==0)
            {
                mat[poz.lin+dl[k]][poz.col+dc[k]]=1+mat[poz.lin][poz.col];
                C[++fi].lin=poz.lin+dl[k];
                C[fi].col=poz.col+dc[k];
            }
    }

}
