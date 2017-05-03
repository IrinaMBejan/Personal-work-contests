#include <fstream>
#include<iomanip>
#define NMAX 102
using namespace std;
ifstream fin("insula.in");
ofstream fout("insula.out");

int mat[NMAX][NMAX];
struct pozitie
{
    int lin;
    int col;
} C[NMAX*NMAX],poz;

int dl[4]= {-1,0,1,0};
int dc[4]= {0,1,0,-1};
int n,m;
int verif(int x, int y, int c);
void fill1(int lin,int col,int val);

int nr[4];
int main()
{
    char c;
    int i,j;
    //citire
    fin>>n>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            fin>>c;
            mat[i][j]=c-'0';
        }
    //bordare
    for(i=0; i<=n+1; i++)
        mat[i][m+1]=mat[i][0]=7;
    for(i=0; i<=m+1; i++)
        mat[n+1][i]=mat[0][i]=7;

    //cerinta 1
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(mat[i][j]<4&&mat[i][j]!=0)
                fill1(i,j,mat[i][j]);
    for(i=1;i<=3;i++)
        fout<<nr[i]<<" ";


     //cerinta 2
    int st=1, fi=0;
     for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                if(!mat[i][j]&&verif(i,j,4))
                  {
                      C[++fi].lin=i,C[fi].col=j;
                      mat[i][j]=8;
                  }
    bool gasit=0;
    while(st<=fi)
    {
        poz=C[st++];
        for(int k=0; k<4; k++)
            if(mat[poz.lin+dl[k]][poz.col+dc[k]]==0)
            {
                mat[poz.lin+dl[k]][poz.col+dc[k]]=1+mat[poz.lin][poz.col];
                if(verif(poz.lin+dl[k],poz.col+dc[k],5)) {fout<<1+mat[poz.lin][poz.col]-7<<'\n'; return 0;}
                C[++fi].lin=poz.lin+dl[k];
                C[fi].col=poz.col+dc[k];
            }
    }
    return 0;
}

void fill1(int lin,int col,int val)
{
    int st=1,fi=1;
    nr[val]++;
    C[st].lin=lin;
    C[st].col=col;
    mat[C[st].lin][C[st].col]=val+3;
    while(st<=fi)
    {
        poz=C[st++];
        for(int k=0; k<4; k++)
            if(mat[poz.lin+dl[k]][poz.col+dc[k]]==val)
            {
                mat[poz.lin+dl[k]][poz.col+dc[k]]=val+3;
                C[++fi].lin=poz.lin+dl[k];
                C[fi].col=poz.col+dc[k];
            }
    }
}


int verif(int x, int y, int c)
{
    for(int k=0;k<4;k++)
        if(mat[x+dl[k]][y+dc[k]]==c)
            return 1;
    return 0;
}
