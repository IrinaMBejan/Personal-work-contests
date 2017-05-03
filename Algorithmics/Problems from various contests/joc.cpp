#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("joc.in");
ofstream fout("joc.out");

struct cel
{
    int c[3];
    int val;
} dp[3][5001][3];
int T[3][5001];
int main()
{
    int n,k,i,j;
    fin>>n>>k;
    for(i=1; i<=n; i++)
        fin>>T[1][i];
    for(i=1; i<=n; i++)
        fin>>T[2][i];

    dp[1][1][1].val = dp[1][1][2].val = T[1][1];
    dp[1][1][1].c[1] = 1;
    dp[1][1][2].c[2] = 0;

    dp[2][1][1].val = dp[2][1][2].val = T[1][1]+T[2][1];
    dp[2][1][1].c[1] = dp[2][1][2].c[2] = 1;

    cel e;
    e.val = -99999999;
    e.c[1] = e.c[2] = k;

    for(j=2; j<=n; j++)
    {
        for(i=1; i<=2; i++)
        {
            if(dp[i][j-1][1].val > dp[i][j-1][2].val)
            {
                if(dp[i][j-1][1].c[i]<k)
                {
                    dp[i][j][1] = dp[i][j-1][1];
                    dp[i][j][1].val += T[i][j];
                    dp[i][j][1].c[i]++;
                }
                else if(dp[i][j-1][2].c[i]<k)
                {
                    dp[i][j][1] = dp[i][j-1][2];
                    dp[i][j][1].val += T[i][j];
                    dp[i][j][1].c[i]++;
                }
                else
                {
                    dp[i][j][1] = e;
                }
            }
            else
            {
                if(dp[i][j-1][2].c[i]<k)
                {
                    dp[i][j][1] = dp[i][j-1][2];
                    dp[i][j][1].val += T[i][j];
                    dp[i][j][1].c[i]++;
                }
                else if(dp[i][j-1][1].c[i]<k)
                {
                    dp[i][j][1] = dp[i][j-1][1];
                    dp[i][j][1].val += T[i][j];
                    dp[i][j][1].c[i]++;
                }
                else
                    dp[i][j][1] = e;
            }

        }
        if(i!=n)
        for(i=1; i<=2; i++)
        {
            dp[i][j][2] = dp[3-i][j][1];
            dp[i][j][2].val += T[i][j];
            dp[i][j][2].c[1] = dp[i][j][2].c[2] = 0;
        }
    }
    fout<<max(dp[2][n][1].val,dp[2][n][2].val)<<'\n';

    return 0;
}
