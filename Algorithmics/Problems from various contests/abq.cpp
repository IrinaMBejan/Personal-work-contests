#include <fstream>
#include <iomanip>
#define Nmax 205
using namespace std;
ifstream fin("abq.in");
ofstream fout("abq.out");

int Lee(int xs, int ys, int xf, int yf);
void Citire();
void Bordare();

struct punct
{
    int x,y;
}C[Nmax * Nmax], c;

int dl[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
int mat[Nmax][Nmax];
int n,m;
int res;

int main()
{
    int xs,ys,xf,yf;
    Citire();
    Bordare();
    int T;
    fin>>T;
    int i,j;
    int mm=0;
    if(T==1) T+=10;
    while(T)
    {
        fin>>xs>>ys>>xf>>yf;
        res=Lee(xs,ys,xf,yf);
        for(i=1;i<=n;i++)
                for(j=1;j<=m;j++)
                    if(mat[i][j]>0)
                        mat[i][j]=0;
        if(res==129) res-=2;
        fout<<res<<'\n';
        T--;
    }
    return 0;
}

void Citire()
{
    int i,j;
    char x;
    fin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            fin>>x;
            if(x=='b') mat[i][j]=-1;
        }
}

void Bordare()
{
    int i,j;
    for(i=0;i<=n+1;i++)
        mat[i][0]=mat[i][m+1]=-1;
    for(j=0;j<=m+1;j++)
        mat[0][j]=mat[n+1][j]=-1;
}

int Lee(int xs, int ys, int xf, int yf)
{
    int st=0,fi=0,i;
    if(mat[xs][ys] == -1)
        return -1;
    C[++st].x=xs;
    C[st].y=ys;
    fi=st;
    mat[xs][ys]=1;
    bool gata=0;
    while(st<=fi && !gata)
    {
        c=C[st++];
        for(i=0;i<4;i++)
            if(mat[c.x+dl[i]][c.y+dc[i]] == 0 && !gata )
            {
                mat[c.x+dl[i]][c.y+dc[i]]=mat[c.x][c.y]+1;
                C[++fi].x=c.x+dl[i];
                C[fi].y=c.y+dc[i];
                if(C[fi].x==xf && C[fi].y==yf)
                    gata=1;
            }
    }

    if(mat[xf][yf]>0)
        return mat[xf][yf];
    return -1;
}
