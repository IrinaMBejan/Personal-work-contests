#include <fstream>

using namespace std;
ifstream fin("robinson.in");
ofstream fout("robinson.out");

int a[52][52];
int main()
{
    int n,m,x,y,i,j;
    fin>>m>>n>>x>>y;
    for(i=0; i<m; i++)
    {
        a[1][i+1]=n+i;
        a[i+1][1]=n+i;
    }
    for(i=2; i<=m; i++)
        for(j=2; j<=m; j++)
            a[i][j]=(a[i-1][j]+a[i][j-1])%1000;
    fout<<a[m][m]<<'\n';
    while(x<=m&&y<=m&&a[x][y]!=-1)
    {
        fout<<x<<" "<<y<<'\n';
        if(a[x][y]%4==0)
        {
            a[x][y]=-1;
            x--;
        }
        else if(a[x][y]%4==1)
        {
            a[x][y]=-1;
            y++;
        }
        else if(a[x][y]%4==2)
        {
            a[x][y]=-1;
            x++;
        }
        else if(a[x][y]%4==3)
        {
            a[x][y]=-1;
            y--;
        }

    }
    return 0;
}
