#include <cstdio>
#define NMAX 80
using namespace std;
FILE* fin=fopen("inginer.in","r");
FILE* fout=fopen("inginer.out","w");

int dl[4]= {-1,0,1,0};
int dc[4]= {0,1,0,-1};

int matsablon[NMAX][NMAX],mat2[NMAX][NMAX];

struct pozitie
{
    int lin;
    int col;
} C[NMAX*NMAX],poz;

int Lee(int x, int y, int xt,int yt);
int N,M;

int main()
{
    int i,j;
    char c;
    fscanf(fin,"%d %d\n",&N,&M);
    for(i=2; i<=N+1; i++)
    {
        for(j=2; j<=M+1; j++)
        {
            c=getc(fin);
            if(c=='X')
                matsablon[i][j]=-1;
        }
        c=getc(fin);
    }
    for(i=0; i<=N+3; i++)
        matsablon[i][0]=matsablon[i][M+3]=mat2[i][0]=mat2[i][M+3]=-1;
    for(i=0; i<=M+3; i++)
        matsablon[0][i]=matsablon[N+3][i]=mat2[0][i]=mat2[N+3][i]=-1;
    int x1,y1,x2,y2;
    fscanf(fin,"%d %d %d %d",&x1,&y1,&x2,&y2);
    while(x1&&x2&&y1&&y2)
    {
        for(i=1; i<=N+2; i++)
            for(j=1; j<=M+2; j++)
                mat2[i][j]=matsablon[i][j];
        fprintf(fout,"%d\n",Lee(++x1,++y1,++x2,++y2));

        fscanf(fin,"%d %d %d %d",&x1,&y1,&x2,&y2);
    }
    return 0;
}


int Lee(int x, int y, int xt,int yt)
{
    int st=1,fi=1;
    C[1].lin=x;
    C[1].col=y;
    mat2[x][y]=1;
    mat2[xt][yt]=0;
    while(st<=fi&&!mat2[xt][yt])
    {
        poz=C[st++];
        for(int k=0; k<4; k++)
            if(mat2[poz.lin+dl[k]][poz.col+dc[k]]==0)
            {
                mat2[poz.lin+dl[k]][poz.col+dc[k]]=1+mat2[poz.lin][poz.col];
                C[++fi].lin=poz.lin+dl[k];
                C[fi].col=poz.col+dc[k];
            }
    }


    if(st>fi) return 0;
    return mat2[xt][yt]-1;

}
