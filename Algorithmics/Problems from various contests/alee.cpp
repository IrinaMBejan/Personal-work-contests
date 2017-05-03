#include <fstream>
#define NMAX 180
using namespace std;
ifstream fin("alee.in");
ofstream fout("alee.out");

int mat[NMAX][NMAX];
struct pozitie
{
    int lin;
    int col;
} C[NMAX*NMAX],poz;

int dl[5]= {-1,0,1,0};
int dc[5]= {0,1,0,-1};
int main()
{
    int n,m,i,j,st,fi,x,y,x1,x2,y1,y2;
    //copac=-1, zona vizitata=1;
    fin>>n>>m;
    for(i=1; i<=m; i++)
    {
        fin>>x>>y;
        mat[x][y]=-1;
    }
    fin>>x1>>y1;
    fin>>x2>>y2;
    C[1].lin=x1;
    C[1].col=y1;
    mat[x1][y1]=1;
    st=1;
    fi=1;
    for(i=0; i<=n+1; i++)
        mat[i][n+1]=mat[i][0]=mat[0][i]=mat[n+1][i]=-1;
    while(st<=fi&&!mat[x2][y2])
    {
        poz=C[st++];
        for(int k=0; k<4; k++)
            if(mat[poz.lin+dl[k]][poz.col+dc[k]]==0)
            {
                mat[poz.lin+dl[k]][poz.col+dc[k]]=1+mat[poz.lin][poz.col];
                C[++fi].lin=poz.lin+dl[k];
                C[fi].col=poz.col+dc[k];
            }
    }
    fout<<mat[x2][y2]<<'\n';
    return 0;
}
