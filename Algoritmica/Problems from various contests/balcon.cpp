#include <fstream>

using namespace std;
ifstream fin("balcon.in");
ofstream fout("balcon.out");

int a[201],q[51][51];

int main()
{
    int n,i,j,x;
    fin>>n;
    int w=n;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
        {
            fin>>x;
            a[x]++;
        }
    int lc=1, cc=1,k=0;
    while(n>=0)
    {
        for(i = cc; i <= n; i++)
        {
            while(a[k]==0) k++;
            q[lc][i]=k;
            a[k]--;
            if(a[k]==0) k++;
        }
        for(i=lc+1; i<=n; i++)
        {
            while(a[k]==0) k++;
            q[i][n]=k;
            a[k]--;
            if(a[k]==0) k++;
        }
        for(i = n - 1; i >= cc; i--)
        {
            while(a[k]==0) k++;
            q[n][i]=k;
            a[k]--;
            if(a[k]==0) k++;
        }
        for(i = n - 1; i >= lc + 1; i--)
        {
            while(a[k]==0) k++;
            q[i][cc]=k;
            a[k]--;
            if(a[k]==0) k++;
        }
        n--;
        lc++;
        cc++;
    }
    for(i=1; i<=w; i++)
    {
        for(j=1; j<=w; j++)
            fout<<q[i][j]<<" ";
        fout<<'\n';
    }
    return 0;
}
