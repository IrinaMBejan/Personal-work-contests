#include <fstream>
#define Nmax 120
using namespace std;
ifstream fin("foto.in");
ofstream fout("foto.out");

int mat[Nmax][Nmax];
bool a[Nmax][Nmax];
int n;
void Lee();

struct pozitie
{
    int lin;
    int col;
}C[101*101],poz;

int dl[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};

int main()
{
    int i,j,m;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
                 fin>>a[i][j];


    for(i=0;i<=n+1;i++)
            a[i][0]=a[i][m+1]=1;


    for(i=0;i<=m+1;i++)
           a[0][i]=a[n+1][i]=1;

     int st, fi,k,nr,nrmax=-1;

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(!a[i][j]&&!mat[i][j])
            {
                nr=1;
                st=fi=1;
                C[1].lin=i;
                C[1].col=j;
                mat[i][j]=1;
                while(st<=fi)
                {
                        poz=C[st++];
                        for(k=0;k<4;k++)
                            if(!mat[poz.lin+dl[k]][poz.col+dc[k]]&&!a[poz.lin+dl[k]][poz.col+dc[k]])
                            {
                                nr++;
                                mat[poz.lin+dl[k]][poz.col+dc[k]]=1;
                                C[++fi].lin=poz.lin+dl[k];
                                C[fi].col=poz.col+dc[k];
                            }
                if(nr>nrmax) nrmax=nr;
                }
        }
        fout<<nrmax<<'\n';
    return 0;
}
