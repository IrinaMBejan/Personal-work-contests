#include <fstream>

using namespace std;

ifstream fin("betasah.in");
ofstream fout("betasah.out");
char a[1001][1001];
int main()
{
    int n, d, k,m,i,j,p,x,y,albe[1002],dame[1003][3];
    fin>>n>>d>>k;
    for(i=1;i<=n;i++)
        albe[i]=i;
    for(i=1;i<=n;i++)
        for(j=1;j<=i;j++)
         a[i][j]=='0';
    for(i=1;i<=d;i++)
    {
        fin>>x>>y;
        a[x][y]='D';
        dame[i][1]==x;
        dame[i][2]==y;
    }
    for(i=1;i<=d;i++)
        fout<<dame[i][1]<<" "<<dame[i][2];
    for(i=1;i<=k;i++)
    {
        fin>>x>>y;
        a[x][y]='G';
        albe[x]--;
    }
    int maxx=albe[1];
    for(i=2;i<=n;i++) {if(maxx<albe[i]) maxx=albe[i];}
    fout<<maxx<<'\n';
    for(i=1;i<=n;i++)
    {
    for(j=1;j<=i;j++)
        fout<<a[i][j]<<" ";
     fout<<'\n';
    }
    return 0;
}
