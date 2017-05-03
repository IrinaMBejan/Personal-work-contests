#include <fstream>
#define NMAX 1501
using namespace std;
ifstream fin("pseudobil.in");
ofstream fout("pseudobil.out");

bool mat[2*NMAX-1][2*NMAX-1];
int Sum[2*NMAX-1][2*NMAX-1];
int main()
{
    int p,n,k,d,i,S=0;
    fin>>p;
    fin>>n>>k>>d;
    //cerinta 1
    if(p==1)
    {
        i=1;
        d--;
        while(d>1)
        {
            S+=2*i;
            i+=2;
            d-=2;
        }
        S+=i;
        fout<<S<<'\n';
        return 0;
    }
    //cerinta 2
    if(p==2)
    {
        int x,y,m,S=0,L1,C1,L2,C2,j,cx,cy;
        for(i=1;i<=k;i++)
        {
            fin>>x>>y;
            mat[x+y-1][n-x+y]=1;
        }
        for(i=1;i<=2*n-1;i++)
            for(j=1;j<=2*n-1;j++)
                Sum[i][j]=Sum[i-1][j]+Sum[i][j-1]+mat[i][j]-Sum[i-1][j-1];
        fin>>m;
        for(i=1;i<=m;i++)
        {
             fin>>x>>y;
             cx=x+y-1;
             cy=n-x+y;
            L1=cx;
            C1=cy-d;
            L2=cx+d;
            C2=cy;
            S=Sum[L2][C2]-Sum[L2][C1-1]-Sum[L1-1][C2]+Sum[L1-1][C1-1];
            fout<<S<<'\n';
        }
    }
    return 0;
}
