#include <fstream>
#include<iomanip>
#define NMAX 25
using namespace std;
ifstream fin("monkey.in");
ofstream fout("monkey.out");

int n,m;
char mat[NMAX][NMAX];
int dl[4]= {-1,0,1,0};
int dc[4]= {0,1,0,-1};
int pas,pasmax;
bool uz[27];

void citire();
void bordare();
void bkt(int x, int y);
void afisare();

int main()
{
    citire();
    bordare();
    bkt(1,1);
    fout<<pasmax<<'\n';
    fin.close();
    fout.close();
    return 0;
}

void citire()
{
    int i;
    fin>>n>>m;
    fin.get();
    for(i=1; i<=n; i++)
        fin.getline(mat[i]+1,m+1);
    uz[mat[1][1]-'A']=1;
    pas=1;
}

void bordare()
{
    int i;
    for(i=0; i<=n+1; i++)
        mat[i][0]=mat[i][m+1]=mat[1][1];
    for(i=0; i<=m+1; i++)
        mat[0][i]=mat[n+1][i]=mat[1][1];
}

bool cannotmove(int x, int y)
{
    int i;
    for(i=0; i<4; i++)
        if(uz[mat[x+dl[i]][y+dc[i]]-'A']==0)
            return 0;
    return 1;
}

void bkt(int x, int y)
{
    if(cannotmove(x,y))
    {
        if(pas>pasmax) pasmax=pas;
    }
    else
    {
        int i;
        for(i=0; i<4; i++)
            if(uz[mat[x+dl[i]][y+dc[i]]-'A']==0)
            {
                pas++;
                uz[mat[x+dl[i]][y+dc[i]]-'A']=1;
                bkt(x+dl[i],y+dc[i]);
                uz[mat[x+dl[i]][y+dc[i]]-'A']=0;
                pas--;

            }
    }
}
