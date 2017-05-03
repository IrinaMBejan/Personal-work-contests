#include <fstream>
#define NMAX 1005
using namespace std;
ifstream fin("spider.in");
ofstream fout("spider.out");


int dl[4]= {-1,0,1,0};
int dc[4]= {0,1,0,-1};

int cost[NMAX][NMAX], h[NMAX][NMAX];

int lgmax,xmax,ymax,n,m;

void go(int x, int y);
int verifica(int x,int y);
void afisare();

int main()
{
    int i,j;
    //citirea
    fin>>m>>n;
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            fin>>h[i][j];

    //bordarea
    for(i=0; i<=m+1; i++)
        h[i][0]=h[i][n+1]=1000000000;
    for(j=0; j<=n+1; j++)
        h[0][j]=h[m+1][j]=1000000000;

    //cerinta
    for(i=1; i<=m; i++)
        for(j=1; j<=n; j++)
            if(!cost[i][j])
                go(i,j);

    fout<<lgmax<<" "<<xmax<<" "<<ymax<<'\n';
    return 0;
}

int verifica(int x, int y)
{
    int dmin=1000000000;
    int ksol=-1;
    for(int k=0; k<4; k++)
        if(h[x][y]-h[x+dl[k]][y+dc[k]]<dmin&&h[x][y]-h[x+dl[k]][y+dc[k]]>=0)
        {
            dmin=h[x][y]-h[x+dl[k]][y+dc[k]];
            ksol=k;
        }
    return ksol;
}

void go(int x, int y)
{
    int nr=1,xinitial=x, yinitial=y,k;
    //parcurgere
    k=verifica(x,y);
    cost[x][y]=-1;
    while(k>=0&&cost[x+dl[k]][y+dc[k]]==0)
    {
        nr++;
        x=x+dl[k];
        y=y+dc[k];
        k=verifica(x,y);
        cost[x][y]=-1;
    }

    //in cazul intersectarii cu un drum deja parcurs;
    if(k>=0&&cost[x+dl[k]][y+dc[k]]>0)
        nr+=cost[x+dl[k]][y+dc[k]];

    //reparcurgerea si marcarea locurilor traversate cu distanta maxima
    x=xinitial;
    y=yinitial;
    int cc=nr,lastval;
    while(cost[x][y]==-1)
    {
        cost[x][y]=cc;
        lastval=cost[x][y];
        k=verifica(x,y);
        x=x+dl[k];
        y=y+dc[k];
        if(lastval>cost[x][y]) cc--;
    }

    //modificare maxim, daca e cazul
    if(nr>lgmax)
    {
        lgmax=nr;
        xmax=xinitial;
        ymax=yinitial;
    }
    //test
    afisare();
    fout<<'\n';
}

void afisare()
{
    int i,j;
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
            fout<<cost[i][j]<<" ";
        fout<<'\n';
    }
}
