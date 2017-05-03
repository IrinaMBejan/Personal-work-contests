#include <fstream>
#define NMAX 105
using namespace std;
ifstream fin("pereti.in");
ofstream fout("pereti.out");

int mat[NMAX][NMAX];
struct pozitie
{
    int lin;
    int col;
} C[NMAX*NMAX],poz;

int dl[4]= {-1,0,1,0};
int dc[4]= {0,1,0,-1};
int rest[4]={8,4,2,1};
int n,m;
void Lee();
int nrp=0;
char s[20][5]={"0000",
                        "0001",
                        "0010",
                        "0011",
                        "0100",
                        "0101",
                        "0110",
                        "0111",
                        "1000",
                        "1001",
                        "1010",
                        "1011",
                        "1100",
                        "1101",
                        "1110",
                        "1111",NULL};
int st, fi;
void afisare();

int main()
{
    int i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                fin>>mat[i+1][j+1];
    st=1; fi=1;
    for(i=0; i<=n+3; i++)
            mat[i][m+3]=mat[i][1]=mat[i][m+2]=mat[i][0]=20;
    for(i=0; i<=m+3; i++)
            mat[n+3][i]=mat[1][i]=mat[n+2][i]=mat[0][i]=20;
 //afisare();
    Lee();
    fout<<nrp;
    fout<<'\n';
    return 0;
}

void afisare()
{
    int i,j;
    for(i=0;i<=n+3;i++)
    {
        for(j=0;j<=m+3;j++)
            fout<<mat[i][j]<<" ";
        fout<<'\n';
    }
    fout<<'\n'<<'\n';
}

void Lee()
{
    C[st].lin=1; C[st].col=2;
    while(st<=fi)
    {
        poz=C[st++];
        for(int k=0; k<4; k++)
            if(mat[poz.lin+dl[k]][poz.col+dc[k]]==0)
            {
                    mat[poz.lin+dl[k]][poz.col+dc[k]]=20;
                    C[++fi].lin=poz.lin+dl[k];
                    C[fi].col=poz.col+dc[k];
            }
            else if(mat[poz.lin+dl[k]][poz.col+dc[k]]<=15)
                {
                    C[++fi].lin=poz.lin+dl[k];
                    C[fi].col=poz.col+dc[k];
                    mat[poz.lin+dl[k]][poz.col+dc[k]]-=rest[k]; nrp++;
                }
        }
        afisare();

}


