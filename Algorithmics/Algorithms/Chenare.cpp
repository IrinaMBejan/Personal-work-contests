#include <fstream>

using namespace std;
ifstream fin("chenare.in");
ofstream fout("chenare.out");
int a[101][101];
int main()
{
    int n,i,j,c,s,k;
    fin>>n;
    k=1;
    int lin=(n+1)/2; int col=lin;
    a[lin][col]=1;
    int q=1;
    while(k<=n*n)
    {
        for(i=col+1;i<=col+q;i++)
        {
                k++;
                a[lin][i]=k;
        }
        for(i=lin+1;i<=lin+q;i++)
        {
            k++;
            a[i][col+q]=k;
        }
        for(i=col+q-1;i>=col-1;i--)
        {
            k++;
            a[lin+q][i]=k;
        }
        for(i=lin+q-1;i>=lin-1;i--)
        {
            k++;
            a[i][col-1]=k;
        }
        q+=2;
        lin--;
        col--;
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            fout<<a[i][j]<<"    ";
        fout<<'\n';
    }
    return 0;
}
