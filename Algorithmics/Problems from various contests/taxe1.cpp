#include <fstream>
#define NMAX 110
using namespace std;
ifstream fin("taxe1.in");
ofstream fout("taxe1.out");

int dl[4]= {-1,0,1,0};
int dc[4]= {0,1,0,-1};

struct pozitie
{
    int lin,col;
} C[NMAX*NMAX*7],poz;
int mat[NMAX][NMAX],parcurs[NMAX][NMAX],val[NMAX][NMAX];
int main()
{
    int S,N,i,j;
    fin>>S>>N;
    for(i=1; i<=N; i++)
        for(j=1; j<=N; j++)
        {
            fin>>mat[i][j];
            val[i][j]=mat[i][j];
        }

    for(i=0; i<=N+1; i++)
        parcurs[i][0]=parcurs[0][i]=parcurs[i][N+1]=parcurs[N+1][i]=-1;

    int st=1,fi=1;
    C[1].lin=1;
    C[1].col=1;
    mat[1][1]=S-val[1][1];
    parcurs[1][1]=1;
    while(st<=fi)
    {
        poz=C[st++];
        for(int k=0; k<4; k++)
        {
            if(parcurs[poz.lin+dl[k]][poz.col+dc[k]]==0||(parcurs[poz.lin+dl[k]][poz.col+dc[k]]>0&&mat[poz.lin][poz.col]-val[poz.lin+dl[k]][poz.col+dc[k]]>mat[poz.lin+dl[k]][poz.col+dc[k]]))
            {
                mat[poz.lin+dl[k]][poz.col+dc[k]]=mat[poz.lin][poz.col]-val[poz.lin+dl[k]][poz.col+dc[k]];
                C[++fi].lin=poz.lin+dl[k];
                C[fi].col=poz.col+dc[k];
                parcurs[poz.lin+dl[k]][poz.col+dc[k]]=1;
            }
        }
    }
    /*     for(i=1; i<=N; i++)
         {
             for(j=1; j<=N; j++)
                 fout<<mat[i][j]<<" ";
             fout<<'\n';
         }*/
    if(mat[N][N]>=0) fout<<mat[N][N];
    else fout<<"-1";
    fout<<'\n';

}
