#include <cstdio>
#include<cstring>
#define NMAX 4001
using namespace std;

bool DP[NMAX][NMAX];
char a[4005],b[4005],c[8010];
int max(int a, int b)
{
    if (a>b) return a;
    return b;
}
int main()
{

    freopen("interclasare.in","r",stdin);
    freopen("interclasare.out","w",stdout);
    int T,i,k,j,n=0,m=0;
    scanf("%d",&T);
    for(k=1; k<=T; k++)
    {
        scanf("%s %s %s\n", &a, &b, &c);
        DP[0][0]=1;
        n=strlen(a);
        m=strlen(b);
        for(i=0; i<=n; ++i)
            for(j=0; j<=m; ++j)
                if(i||j)
                {
                    DP[i][j]=0;
                    if(i&&a[i-1]==c[i+j-1]) DP[i][j]=max(DP[i][j], DP[i-1][j]);
                    if(j&&b[j-1]==c[i+j-1]) DP[i][j]=max(DP[i][j], DP[i][j-1]);
                }
        printf("%d\n",DP[n][m]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
