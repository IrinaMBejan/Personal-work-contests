#include <fstream>
#define Nmax 305
using namespace std;
ifstream fin("fillmat.in");
ofstream fout("fillmat.out");

char mat[Nmax][Nmax];
int a[Nmax][Nmax];
struct pozitie
{
    int lin;
    int col;
} C[Nmax*Nmax],poz;

int dl[]= {-1,-1,0,1,1,1,  0,-1};
int dc[]= {0,  1,1,1,0,-1,-1,-1};

int main()
{
    int n,i,j,st=1,fi=1,np=0;
    fin>>n;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            {
                fin>>mat[i][j];
                if(mat[i][j]=='1')
                {
                    C[fi].lin=i;
                    C[fi++].col=j;
                    a[i][j]=1;
                }
            }
    while(st<=fi)
    {
        poz=C[st++];
        for(int k=0; k<8; k++)
            if(mat[poz.lin+dl[k]][poz.col+dc[k]]=='0')
            {
                int nr=0;
                for(int q=0; q<8; q++)
                    if(mat[poz.lin+dl[k]+dl[q]][poz.col+dc[k]+dc[q]]=='1'&&a[poz.lin+dl[k]+dl[q]][poz.col+dc[k]+dc[q]]<=a[poz.lin][poz.col])
                        nr++;
                if(nr>=3)
                {
                    mat[poz.lin+dl[k]][poz.col+dc[k]]='1';
                    a[poz.lin+dl[k]][poz.col+dc[k]]=a[poz.lin][poz.col]+1;
                    if(a[poz.lin+dl[k]][poz.col+dc[k]]>np)
                            np=a[poz.lin+dl[k]][poz.col+dc[k]];
                    C[fi].lin=poz.lin+dl[k];
                    C[fi++].col=poz.col+dc[k];
                }
            }
    }
    fout<<np-1<<'\n';
    return 0;
}
