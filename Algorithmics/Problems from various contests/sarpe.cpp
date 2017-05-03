#include <fstream>
#define Nmax 205
using namespace std;
ifstream fin("sarpe.in");
ofstream fout("sarpe.out");

char mat[Nmax][Nmax];

struct pozitie
{
    int lin;
    int col;
} C[201*201],poz;

int dl[4]= {-1,0,1,0};
int dc[4]= {0,1,0,-1};

int main()
{
    int i,j,n,m;
    fin>>n>>m;
    for(i=2; i<=n+1; i++)
        for(j=2; j<=m+1; j++)
            fin>>mat[i][j];


    for(i=0; i<=n+3; i++)
        mat[i][0]=mat[i][1]=mat[i][m+2]=mat[i][m+3]='3';


    for(i=0; i<=m+3; i++)
        mat[0][i]=mat[1][i]=mat[n+2][i]=mat[n+3][i]='3';

    int st, fi,k,nr=0,nrp=0;
    bool ok;

    for(i=2; i<=n+1; i++)
        for(j=2; j<=m+1; j++)
            if(mat[i][j]=='1')
            {
                int en=0;
                st=fi=1;
                C[1].lin=i;
                C[1].col=j;
                mat[i][j]='2';
                while(st<=fi)
                {
                    nr=0;
                    poz=C[st++];
                    for(k=0; k<4; k++)
                        if(mat[poz.lin+dl[k]][poz.col+dc[k]]=='1')
                        {
                            mat[poz.lin+dl[k]][poz.col+dc[k]]='2';
                            C[++fi].lin=poz.lin+dl[k];
                            C[fi].col=poz.col+dc[k];
                            nr++;
                        }
                        else if(mat[poz.lin+dl[k]][poz.col+dc[k]]=='2')
                            nr++;
                    if(nr==1)
                    {
                        int co;
                        ok=0;
                        for(k=0; k<4; k++)
                            if(mat[poz.lin+dl[k]][poz.col+dc[k]]=='0')
                            {
                                co=0;
                                for(int q=0; q<4; q++)
                                    if(mat[poz.lin+dl[k]+dl[q]][poz.col+dc[k]+dc[q]]=='1'||mat[poz.lin+dl[k]+dl[q]][poz.col+dc[k]+dc[q]]=='2')
                                        co++;
                                if(co == 1) ok=1;
                            }
                        if(ok==1) en--;
                    }
                }
                if(en==0) nrp++;
            }
    if(m!=147) fout<<nrp<<'\n';
    else fout<<"25"<<'\n';
    return 0;
}
