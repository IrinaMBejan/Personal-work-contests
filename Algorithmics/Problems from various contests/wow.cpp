#include <fstream>
#define NMAX 105
#define MMAX 505
using namespace std;
ifstream fin("wow.in");
ofstream fout("wow.out");

short int mat[NMAX][NMAX];
short int viz[NMAX][NMAX];
int Sum[NMAX][NMAX];
int valid[NMAX][NMAX];
struct pozitie
{
    short int lin;
    short int col;
} C[NMAX*NMAX],poz;


int dl[4]= {-1,0,1,0};
int dc[4]= {0,1,0,-1};

int N,p,M;
void Fill1(int lin, int col);

int main()
{
    int i,j;
    //citire
    fin>>N>>p>>M;
    for(i=1; i<=N; i++)
        for(j=1; j<=p; j++)
        {
            fin>>mat[i][j];
            if(mat[i][j]==1)
                mat[i][j]=-1;
        }

    //bordare
    for(i=0; i<=N+1; i++)
        mat[i][p+1]=mat[i][0]=-1;
    for(i=0; i<=p+1; i++)
        mat[N+1][i]=mat[0][i]=-1;

    //fill
    int x,y,i1;
    for(i=1; i<=M; i++)
    {
        fin>>x>>y;
        Fill1(x+1,y+1);


        for(i1=1;i1<=N;i1++)
            for(j=1;j<=p;j++)
            {
                Sum[i1][j]+=(viz[i1][j]-1);
                viz[i1][j]=0;
            }
    }

    int dmin=10000000, lmin=0, cmin=0,q,d;
    for(i=1; i<=N; i++)
        for(j=1; j<=p; j++)
            if(mat[i][j]!=-1 && valid[i][j]==M)
            {
                if(Sum[i][j]<dmin)
                {
                    dmin=Sum[i][j], lmin=i,cmin=j;
                }
            }

    fout<<dmin<<'\n'<<lmin-1<<" "<<cmin-1<<'\n';
    return 0;
}

void Fill1(int lin, int col)
{
    int st=1,fi=1;
    C[st].lin=lin;
    C[st].col=col;
    viz[C[st].lin][C[st].col]=1;
    valid[C[st].lin][C[st].col]++;
    while(st<=fi)
    {
        poz=C[st++];
        for(int k=0; k<4; k++)
            if(mat[poz.lin+dl[k]][poz.col+dc[k]]!=-1 && !viz[poz.lin+dl[k]][poz.col+dc[k]])
            {
                viz[poz.lin+dl[k]][poz.col+dc[k]]=viz[poz.lin][poz.col]+1;
                valid[poz.lin+dl[k]][poz.col+dc[k]]++;
                C[++fi].lin=poz.lin+dl[k];
                C[fi].col=poz.col+dc[k];
            }
    }
}
