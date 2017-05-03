#include <fstream>
#define Nmax 108
using namespace std;
ifstream fin("zona.in");
ofstream fout("zona.out");

int a[Nmax][Nmax], b[Nmax][Nmax],x,y,n;
bool uz[Nmax][Nmax];
int dl[5]= {0, -1, 0, 1, 0};
int dc[5]= {0, 0, 1, 0,-1};

struct pozitie
{
    int lin,col;
} C[Nmax*Nmax],poz;

int cerinta1();
void marcheaza(int x, int y, int dir);
int fill(int i, int j);

int main()
{
    fout<<cerinta1()<<'\n';
    for(int i=0; i<=n+1; i++)
    {
        a[0][i]+=2;
        a[i][0]+=16;
        a[n+1][i]+=8;
        a[i][n+1]+=4;
    }

    fout<<(n+2)*(n+2)-fill(0,0)<<'\n';
    return 0;
}

int cerinta1()
{
    int i, j,L,pas,dir,sola=0;
    fin>>x>>y>>n>>L;
    int x1=x, y1=y;
    b[x][y]=1;
    pas=1;
    for(i=1; i<=L; i++)
    {
        fin>>dir;
        marcheaza(x1,y1,dir);
        x1+=dl[dir];
        y1+=dc[dir];
        if(!b[x1][y1])
            b[x1][y1]=++pas;
        else
        {
            sola=pas-b[x1][y1]+1;
            return sola;
        }
    }
    return -1;
}

void marcheaza(int x, int y, int dir)
{
    switch(dir)
    {
    case 1:
    {
        a[x][y]+=4;
        a[x][y+1]+=16;
        break;
    }
    case 2:
    {
        a[x][y+1]+=8;
        a[x+1][y+1]+=2;
        break;
    }
    case 3:
    {
        a[x+1][y]+=4;
        a[x+1][y+1]+=16;
        break;
    }
    case 4:
    {
        a[x][y]+=8;
        a[x+1][y]+=2;
        break;
    }
    }
}

int fill(int i, int j)
{
    int st=1, fi=1,solb=1;
    C[st].lin=i;
    C[st].col=j;
    uz[i][j]=1;
    while(st<=fi)
    {
        poz=C[st++];
        for(i=1; i<=4; i++)
            if(!(a[poz.lin][poz.col]&(1<<i))&&uz[poz.lin+dl[i]][poz.col+dc[i]]==0)
            {
                uz[poz.lin+dl[i]][poz.col+dc[i]]=1;
                C[++fi].lin=poz.lin+dl[i];
                C[fi].col=poz.col+dc[i];
                solb++;
            }
    }
    return solb;
}
