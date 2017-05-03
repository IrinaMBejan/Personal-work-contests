#include <fstream>
#define Nmax 120
using namespace std;
ifstream fin("rebus.in");
ofstream fout("rebus.out");

bool mat[Nmax][Nmax];
char a[Nmax][Nmax];

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
    int i,j,n,m;
    fin>>n>>m;

    for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
                  fin>>a[i][j];


    for(i=0;i<=n+1;i++)
            a[i][0]=a[i][m+1]='#';


    for(i=0;i<=m+1;i++)
           a[0][i]=a[n+1][i]='#';

     int st, fi,k, nr=0;

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i][j]=='*')
            {
                nr++;
                st=fi=1;
                C[1].lin=i;
                C[1].col=j;
                while(st<=fi)
                {
                        poz=C[st++];
                        int stanga=0,dreapta=0,sus=0,jos=0;
                        int q1=1,q2=1;
                        while(a[poz.lin][poz.col-q1]=='*'||a[poz.lin][poz.col-q1]=='&') {stanga++; q1++;}
                        while(a[poz.lin][poz.col+q2]=='*'||a[poz.lin][poz.col+q2]=='&') {dreapta++; q2++;}

                        if(a[poz.lin][poz.col-q1]=='#'&&a[poz.lin][poz.col+q2]=='#')
                        {
                            for(k=-q1+1;k<q2;k++)
                                if(a[poz.lin][poz.col+k]!='&')
                            {
                                C[fi].lin=poz.lin;
                                C[fi++].col=poz.col+k;
                                a[poz.lin][poz.col+k]='&';
                            }
                        }

                        q1=1,q2=1;
                        while(a[poz.lin-q1][poz.col]=='*'||a[poz.lin-q1][poz.col]=='&') {jos++; q1++;}
                        while(a[poz.lin+q2][poz.col]=='*'||a[poz.lin+q2][poz.col]=='&') {sus++; q2++;}

                        if(a[poz.lin-q1][poz.col]=='#'&&a[poz.lin+q2][poz.col]=='#')
                        {
                            for(k=-q1+1;k<q2;k++)
                                if(a[poz.lin+k][poz.col]!='&')
                            {
                                C[fi].lin=poz.lin+k;
                                C[fi++].col=poz.col;
                                a[poz.lin+k][poz.col]='&';
                            }
                        }
                }
        }
    fout<<nr<<'\n';
    return 0;
}
