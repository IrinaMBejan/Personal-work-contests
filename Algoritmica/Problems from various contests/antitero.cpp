#include <fstream>
#define Nmax 40
using namespace std;
ifstream fin("antitero.in");
ofstream fout("antitero.out");

void Citire();
void Depl(int k, int x, int y, int niv);
int sol;
struct Tero
{
    int x,y,g;
} r[260];
bool ajuns=0;
int m, n, h, K, T;
bool p[Nmax][Nmax][Nmax]; //pentru vizitare
int cam[Nmax][Nmax][Nmax]; //pentru valori camere

int dl[9]= {0,-1,-1,0,1,1,1,0,-1};
int dc[9]= {0,0,1,1,1,0,-1,-1,-1};

int main()
{
    Citire();
    int i,a,b,c;
    for(a=0; a<=h+1; a++)
        for(b=0; b<=m+1; b++)
            for(c=0; c<=n+1; c++)
                p[a][b][c]=1; //bordare
    for(i=1; i<=K; i++)
    {
        for(a=1; a<=h; a++)
            for(b=1; b<=m; b++)
                for(c=1; c<=n; c++)
                    p[a][b][c]=0; //initializare zone vizitate
        p[1][r[i].x][r[i].y]=1;
        ajuns=0;
        Depl(i, r[i].x, r[i].y, 1);
    }
    fout<<sol<<'\n';
    return 0;
}

void Citire()
{
    fin>>m>>n>>h>>K>>T;
    int i,j,q;
    for(i=1; i<=h; i++)
        for(j=1; j<=m; j++)
            for(q=1; q<=n; q++)
                fin>>cam[i][j][q];
    for(i=1; i<=K; i++)
    {
        fin>>r[i].g>>r[i].x>>r[i].y;
    }
}

void Depl(int k, int x, int y, int niv)
{
    if(!ajuns)
    {
        if(niv == h)
        {
            ajuns=1;
            sol++;
        }
        else
        {
            int i,xx,yy;
            for(i=0; i<9; i++)
            {
                xx=dl[i]+x;
                yy=dc[i]+y; //toate posbilitatile la nivelul niv
                if(!p[niv+1][xx][yy]) //nu  am trecut pe acolo
                    if((r[k].g&cam[niv][xx][yy]) == r[k].g)
                    {
                        p[niv+1][xx][yy]=1;
                        Depl(k,xx,yy,niv+1);
                    }
            }
        }
    }
}
