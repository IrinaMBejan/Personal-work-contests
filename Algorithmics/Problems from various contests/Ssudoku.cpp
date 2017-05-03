#include <fstream>

using namespace std;
ifstream fin("sudoku.in");
ofstream fout("sudoku.out");
int nr;
bool mcuz[10][10], mluz[10][10], mruz[10][10];
int mat[10][10];
struct spatiu
{
    int l,c,val;
} V[82];

int reg(int i, int j);
void bkt(int k)
{
    if(k-1==nr)
    {
        for(int i=1; i<=nr; i++)
            mat[V[i].l][V[i].c]=V[i].val;
        for(int i=1; i<=9; i++)
        {
            for(int j=1; j<=9; j++)
                fout<<mat[i][j];
            fout<<'\n';
        }
    }
    else
    {
        for(int i=1; i<=9; i++)
            if(mcuz[V[k].c][i]==0&&mluz[V[k].l][i]==0&&mruz[reg(V[k].l,V[k].c)][i]==0)
            {
                mcuz[V[k].c][i]=1;
                mluz[V[k].l][i]=1;
                mruz[reg(V[k].l,V[k].c)][i]=1;
                V[k].val=i;
                bkt(k+1);
                mcuz[V[k].c][i]=0;
                mluz[V[k].l][i]=0;
                mruz[reg(V[k].l,V[k].c)][i]=0;
            }
    }

}
int main()
{
    int i,j;
    char c;
    for(i=1; i<=9; i++)
    {
        for(j=1; j<=9; j++)
        {
            fin>>c;
            mat[i][j]=c-'0';
            mcuz[j][mat[i][j]]=1;
            mluz[i][mat[i][j]]=1;
            mruz[reg(i,j)][mat[i][j]]=1;
            if(mat[i][j]==0)
                V[++nr].l=i,V[nr].c=j;
        }
    }
    bkt(1);
    return 0;
}

int reg(int i, int j)
{
    if(i<=3&&j<=3) return 1;
    if(i<=3&&4<=j&&j<=6) return 2;
    if(i<=3&&7<=j) return 3;
    if(4<=i&&i<=6&&j<=3) return 4;
    if(4<=i&&i<=6&&4<=j&&j<=6) return 5;
    if(4<=i&&i<=6&&7<=j) return 6;
    if(7<=i&&j<=3) return 7;
    if(7<=i&&4<=j&&j<=6) return 8;
    if(7<=i&&7<=j) return 9;
}
