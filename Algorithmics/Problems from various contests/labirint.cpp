#include <fstream>
#include<iomanip>
#define NMAX 20
using namespace std;
ifstream fin("labirint.in");
ofstream fout("labirint.out");

int n,m;
int mat[NMAX][NMAX];
int solnr;
int dl[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};
int startx,starty,targetx,targety,pas;

void citire();
void bordare();
void bkt(int x, int y);
void afisare();

int main()
{
    citire();
    bordare();
    bkt(startx,starty);
    fin.close();
    fout.close();
    return 0;
}

void citire()
{
    int i,j;
    char x;
    fin>>n>>m;
    fin.get(x);
    for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                fin.get(x);
                if(x=='#')
                {
                    mat[i][j]=-1;
                }
                else if(x=='B')
                {
                    targetx=i;
                    targety=j;
                }
                else if(x=='S')
                {
                    startx=i;
                    starty=j;
                }
            }
            fin.get(x);
        }

    //    for(i=1;i<=n;i++)
         //           fin.getline(mat[i]+1,m);

}

void bordare()
{
    int i;
    for(i=0;i<=n+1;i++)
        mat[i][0]=mat[i][m+1]=-1;
    for(i=0;i<=m+1;i++)
        mat[0][i]=mat[n+1][i]=-1;
}


void bkt(int x, int y)
{
        if(x==targetx&&y==targety)
            {
                solnr++;
                afisare();
            }
        else
        {
            int i;
            for(i=0;i<4;i++)
                if(mat[x+dl[i]][y+dc[i]]==0)
                {
                    ++pas;
                    mat[x+dl[i]][y+dc[i]]=pas;
                    bkt(x+dl[i],y+dc[i]);
                    mat[x+dl[i]][y+dc[i]]=0;
                    pas--;
                }
        }
}

void afisare()
{
    int i,j;
    fout<<"Aceasta este solutia numarul "<<solnr<<'\n'<<'\n';;
    for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(mat[i][j]==-1) fout<<setw(3)<<'#';
                else if(mat[i][j]==0) fout<<setw(3)<<' ';
                else fout<<setw(3)<<mat[i][j];
            }
            fout<<'\n';
        }
    fout<<'\n';
}
