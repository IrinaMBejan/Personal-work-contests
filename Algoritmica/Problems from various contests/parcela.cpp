#include <fstream>
#define Nmax 255
#define Smax 40005
using namespace std;
ifstream fin("parcela.in");
ofstream fout("parcela.out");

int mat[Nmax][Nmax];
int nr[Nmax*Nmax];
bool Sum[Smax];
int N,M,S;
int Lee(int i,int j);

struct pozitie
{
    int lin;
    int col;
} C[Nmax*Nmax],poz;

int dl[8]= {-1,-1,0,1,1,1,0,-1};
int dc[8]= {0,1,1,1,0,-1,-1,-1};

int main()
{
    int i,j, q=0;
    fin>>N>>M>>S;
    for(i=1; i<=N; i++)
        for(j=1; j<=M; j++)
        {
            fin>>mat[i][j];
            if(mat[i][j]==1) mat[i][j]=-1;
        }

    for(i=1; i<=N; i++)
        for(j=1; j<=M; j++)
            if(mat[i][j]==-1)
                    nr[++q]=Lee(i,j);
    Sum[0]=1;
    for(i=1; i<=q; i++)
    {
        for(j=S; j>=0; j--)
            if(Sum[j] && j+nr[i]<=S)
                Sum[j+nr[i]]=1;
    }
    for(j=S; !Sum[j]; j--);
    fout<<j<<'\n';
    return 0;
}

int Lee(int i, int j)
{
    int st=1, fi=1,k, marime=1;
    C[1].lin=i;
    C[1].col=j;
    mat[i][j]=1;
    while(st<=fi)
    {
        poz=C[st++];
        for(k=0; k<8; k++)
            if(mat[poz.lin+dl[k]][poz.col+dc[k]]==-1)
            {
                mat[poz.lin+dl[k]][poz.col+dc[k]]=mat[poz.lin][poz.col]+1;
                marime++;
                C[++fi].lin=poz.lin+dl[k];
                C[fi].col=poz.col+dc[k];
            }
    }
    return marime;
}
