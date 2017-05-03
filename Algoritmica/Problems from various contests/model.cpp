#include <fstream>
#include <algorithm>
using namespace std;
#define NMAX 1005
ifstream fin("model.in");
ofstream fout("model.out");

int N;
struct pat
{
    int lg;
    int cul;
}s[NMAX];
int mat[NMAX][NMAX];
int cadr[NMAX];
int comp(pat a, pat b)
{
    return (a.lg<b.lg);
}
int main()
{
    fin>>N;
    int i;
    for(i=1;i<=N;i++)
        {
            fin>>s[i].lg;
            s[i].cul = i;
        }
    sort(s+1,s+N+1,comp);
    int last = 0,j;
    for(i=1;i<=N;i++)
    {
        for(j=last;j<=s[i].lg/2;j++)
            cadr[j] = s[i].cul;

        last = s[i].lg/2;
    }
    int c;
    int n = s[N].lg;
    for(c=1;c<=n/2;c++)
    {
        for(i=c;i<=n-c+1;i++)
           {
                mat[c][i]=mat[i][n-c+1]=mat[i][c]=mat[n-c+1][i]=cadr[n/2-c];
           }
    }
    fout<<n<<'\n';
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
                fout<<mat[i][j]<<" ";
        fout<<'\n';
    }
    return 0;
}
