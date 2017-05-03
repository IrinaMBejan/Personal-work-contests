#include <fstream>
#define NMAX 1005
using namespace std;
ifstream fin("robotzi.in");
ofstream fout("robotzi.out");

char mat[NMAX][NMAX];
bool viz[NMAX][NMAX], le[NMAX][NMAX];
struct pozitie
{
    int lin;
    int col;
} C[NMAX*NMAX],poz;


int dl[4]= {1,0,-1,0};
int dc[4]= {0,1,0,1};

int N,p;
void Fill1();
void Fill2();
int nr=0;
int main()
{
    int i,j;
    //citire
    fin>>N>>p;
    for(i=1; i<=N; i++)
        for(j=1; j<=N; j++)
            fin>>mat[i][j];

    //bordare
    for(i=0; i<=N+1; i++)
        mat[i][N+1]=mat[i][0]=mat[N+1][i]=mat[0][i]='x';

    //fill
    Fill1();
    Fill2();
    //pt fiecare aur la care am ajuns si ne putem intoarce in 1,n
    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
            if(mat[i][j]=='$' && le[i][j] && viz[i][j])
                    nr++;

    fout<<nr<<'\n';
    return 0;
}
void Fill1()
{
    int st=1,fi=1;
    C[st].lin=1;
    C[st].col=1;
    viz[C[st].lin][C[st].col]=1;
    while(st<=fi)
    {
        poz=C[st++];
        if(poz.col<=p)
        {
            for(int k=0; k<2; k++)
            if(mat[poz.lin+dl[k]][poz.col+dc[k]]!='x' && !viz[poz.lin+dl[k]][poz.col+dc[k]])
            {
                viz[poz.lin+dl[k]][poz.col+dc[k]]=1;
                C[++fi].lin=poz.lin+dl[k];
                C[fi].col=poz.col+dc[k];
            }
        }
        else
        {
            for(int k=2; k<4; k++)
            if(mat[poz.lin+dl[k]][poz.col+dc[k]]!='x' && !viz[poz.lin+dl[k]][poz.col+dc[k]])
            {
                viz[poz.lin+dl[k]][poz.col+dc[k]]=1;
                C[++fi].lin=poz.lin+dl[k];
                C[fi].col=poz.col+dc[k];
            }
        }
    }
}
void Fill2()
{
    int st=1,fi=1;
    C[st].lin=1;
    C[st].col=N;
    le[C[st].lin][C[st].col]=1;
    while(st<=fi)
    {
        poz=C[st++];
        if(poz.col<=p)
        {
            for(int k=0; k<2; k++)
            if(mat[poz.lin-dl[k]][poz.col-dc[k]]!='x' && !le[poz.lin-dl[k]][poz.col-dc[k]])
            {
                le[poz.lin-dl[k]][poz.col-dc[k]]=1;
                C[++fi].lin=poz.lin-dl[k];
                C[fi].col=poz.col-dc[k];
            }
        }
        else
        {
            for(int k=2; k<4; k++)
            if(mat[poz.lin-dl[k]][poz.col-dc[k]]!='x' && !le[poz.lin-dl[k]][poz.col-dc[k]])
            {
                le[poz.lin-dl[k]][poz.col-dc[k]]=1;
                C[++fi].lin=poz.lin-dl[k];
                C[fi].col=poz.col-dc[k];
            }
        }
    }
}
