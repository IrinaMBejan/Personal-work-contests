#include <fstream>
#include<cstdio>
#define Nmax 1005
using namespace std;
FILE* fin=fopen("tsunami.in","r");
ofstream fout("tsunami.out");

int mat[Nmax][Nmax];
bool a[Nmax][Nmax];
struct pozitie
{
    int lin;
    int col;
} C[Nmax*Nmax],poz;

int dl[]= {-1,0,1,  0};
int dc[]= {0,1,0,-1,};
int n,m,h;
int main()
{
    int i,j,st=1,fi=1,nz=0;
    fscanf(fin,"%d %d %d",&n,&m,&h);
    for(i=0;i<=n+1;i++)
            a[i][0]=a[i][m+1]=1;


    for(i=0;i<=m+1;i++)
           a[0][i]=a[n+1][i]=1;

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            fscanf(fin,"%d",&mat[i][j]);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
                if(mat[i][j]==0)
                {
                    bool ok=0;
                    a[i][j]=1;
                    for(int q=0;q<4;q++)
                        if(mat[i+dl[q]][j+dc[q]]!=0)
                            ok=1;
                    if(ok)
                    {C[fi].lin=i;
                    C[fi++].col=j;}
                }

    nz=fi;
    int nr=0;
    if(st!=fi)
    while(st<=fi)
    {
        poz=C[st++];
        for(int k=0; k<4; k++)
            if(mat[poz.lin+dl[k]][poz.col+dc[k]]<h&&a[poz.lin+dl[k]][poz.col+dc[k]]==0)
            {
                nr++;
                a[poz.lin+dl[k]][poz.col+dc[k]]=1;
                C[fi].lin=poz.lin+dl[k];
                C[fi++].col=poz.col+dc[k];
            }
    }
    nr--;
    fout<<nr<<'\n';
    return 0;
}
