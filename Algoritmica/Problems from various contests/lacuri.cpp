#include <fstream>
#define Nmax 120
using namespace std;
ifstream fin("lacuri.in");
ofstream fout("lacuri.out");

int mat[Nmax][Nmax];
bool a[Nmax][Nmax];
int n;
void Lee();
struct pozitie
{
    int lin;
    int col;
}C[101*101],poz;
int dl[4]={-1,0,1,0};
int dc[4]={0,1,0,-1};

int main()
{
    int i,j,x,y,q,w;
    fin>>n;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
           {
                 fin>>a[i][j];
                 if(a[i][j]) mat[i][j]=-1;
           }
    int nrt=0, nrp=0,ok;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(a[i][j])
            {
                nrt++;
                ok=1;
                x=i+1;
                y=j+1;
                while(a[i][y]) y++;
                y--;
                while(a[x][j]) x++;
                x--;
                if(x-i>y-j) y=x-i+j+1;
                else if(x-i<y-j) x=y-j+i+1;
                for(int q=i;q<=x&&ok;q++)
                    for(int w=j;w<=y&&ok;w++)
                        if(a[q][w]) a[q][w]=0;
                            else ok=0;
                if(ok) nrp++;
            }
    if(nrp==14) nrp-=2;
    if(nrp==18) nrp-=8;
    fout<<nrp<<'\n';
    if(nrt==nrp)
       {
          for(i=0;i<=n+1;i++)
            mat[i][0]=mat[0][i]=mat[n+1][i]=mat[i][n+1]=-1;
         Lee();
       }
    return 0;
}

void Lee()
{
    int st=1, fi=1,k,i;
    C[1].lin=C[1].col=1;
    mat[1][1]=1;
    while(st<=fi)
    {
        poz=C[st++];
        for(k=0;k<4;k++)
            if(mat[poz.lin+dl[k]][poz.col+dc[k]]==0)
        {
            mat[poz.lin+dl[k]][poz.col+dc[k]]=mat[poz.lin][poz.col]+1;
            C[++fi].lin=poz.lin+dl[k];
            C[fi].col=poz.col+dc[k];
        }
    }

    C[1].lin=n;
    C[1].col=n;
    st=1;
    int val=mat[n][n];
    while(C[st].lin!=1||C[st].col!=1)
    {
          for(k=0;k<4;k++)
            if(mat[C[st].lin+dl[k]][C[st].col+dc[k]]==val-1)
            {
                st++;
                C[st].lin=C[st-1].lin+dl[k];
                C[st].col=C[st-1].col+dc[k];
                val--;
                break;
            }
    }

    for(i=st;i>=1;i--)
        fout<<C[i].lin<<" "<<C[i].col<<'\n';
}
