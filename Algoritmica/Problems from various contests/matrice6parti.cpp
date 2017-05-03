#include <fstream>

using namespace std;
ifstream fin("6.in");
ofstream fout("6.out");

int a[101][101];
int main()
{
    int n,i,s,j,jo;
    fin>>n;
    for(i=1;i<=n;i++)
        a[i][i]=1;
    for(i=1;i<=n;i++)
        a[i][n-i+1]=2;
    if(n%2==0) {s=(n/2)-1; jo=n-s+1; }
    else {s=n/2; jo=n-s+1;}
    int in=2;int sf=n-1;
    for(i=1;i<=s;i++)
    {
        for(j=in;j<=sf;j++)
            {a[i][j]=3;a[j][i]=6;}
        in++;
        sf--;
    }
    in=2; sf=n-1;
    for(i=n;i>=jo;i--)
    {
        for(j=in;j<=sf;j++)
        {
            a[i][j]=5; a[j][i]=4;
        }
        in++;
        sf--;
    }




    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            fout<<a[i][j]<<" ";
        fout<<'\n';
    }
    return 0;
}
