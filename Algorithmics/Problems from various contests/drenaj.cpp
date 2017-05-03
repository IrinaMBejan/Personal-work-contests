#include <fstream>
#define Nmax 120
using namespace std;
ifstream fin("drenaj.in");
ofstream fout("drenaj.out");

bool mat[Nmax][Nmax];
int a[Nmax][Nmax];

void Lee();

struct pozitie
{
    int lin;
    int col;
} C[101*101],poz;

int dl[4]= {-1,0,1,0};
int dc[4]= {0,1,0,-1};

int main()
{
    int i,j,n,m;
    fin>>n>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            fin>>a[i][j];


    for(i=0; i<=n+1; i++)
        a[i][0]=a[i][m+1]=10001;


    for(i=0; i<=m+1; i++)
        a[0][i]=a[n+1][i]=10001;

    int st, fi,k,nr,counter=0;

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(!mat[i][j])
            {
                counter++;
                nr=a[i][j];
                bool ok=false;
                st=fi=1;
                C[1].lin=i;
                C[1].col=j;
                mat[i][j]=1;
                for(int q=0; q<4; q++)
                    if(a[i+dl[q]][j+dc[q]]<nr)
                        ok=true;
                while(st<=fi)
                {
                    poz=C[st++];
                    for(k=0; k<4; k++)
                        if(!mat[poz.lin+dl[k]][poz.col+dc[k]]&&a[poz.lin+dl[k]][poz.col+dc[k]]==nr)
                        {
                            mat[poz.lin+dl[k]][poz.col+dc[k]]=1;
                            C[++fi].lin=poz.lin+dl[k];
                            C[fi].col=poz.col+dc[k];
                            for(int q=0; q<4; q++)
                                if(a[poz.lin+dl[k]+dl[q]][poz.col+dc[k]+dc[q]]<nr)
                                    ok=true;
                        }
                }
                if(ok)
                    counter--;
            }
    fout<<counter<<'\n';
    return 0;
}
