#include <fstream>

using namespace std;

ifstream fin("sah.in");
ofstream fout("sah.out");
 int a[1001][1001];
int d,k,xi,yi,xj,yj,i,j,m,p,n;
int main()
{

    fin>>n;
    fin>>d;
    fin>>k;
    int h;
    for(i=1;i<=d;i++)
    {
        fin>>xi>>yi;
        a[xi][yi]=68;
    }
    for(i=1;i<=k;i++)
    {
        fin>>xi>>yi;
        a[xi][yi]=88;
    }
    fout<<a[1][1]<<'\n';
    for(i=1;i<=n;i++)
     {for(j=1;j<=n;j++)
     fout<<a[i][j]<<" "; fout<<'n'; }
      /*
    for(i=2;i<=n;i++)
    {
        for(h=1;h<=i;h++)
        fout<<a[i][h]<<" ";
        fout<<'\n';
    }*/
}
