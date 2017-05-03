#include <fstream>
#define NMAX 21
using namespace std;
ifstream fin("adevar.in");
ofstream fout("adevar.out");

int A[NMAX][NMAX], F[NMAX][NMAX],sol[NMAX];

int main()
{
    int n,i,j,k,l,x,ok;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>k;
        for(j=1; j<=k; j++)
        {
            fin>>x;
            A[i][x]=1;
        }
        fin>>l;
        for(j=1; j<=l; j++)
        {
            fin>>x;
            F[i][x]=1;
        }
    }
    ok=0;
    while(!ok)
    {
        ok=1;
        for(i=1; i<=n&&ok; i++)
        {
            if(!sol[i])
                for(j=1; j<=n&&ok; j++)
                {
                    if(A[i][j]==1&&sol[j]==1) ok=0;
                    if(F[i][j]==1&&sol[j]==0)  ok=0;
                }
            if(sol[i])
            {
                int q=0;
                for(j=1; j<=n&&ok; j++)
                    if(A[i][j]==1&&sol[j]==1||F[i][j]==1&&sol[j]==0) q++;
                if(q==0) ok=0;
            }
        }
        if(!ok)
        {
            for(j=n; j>0&&sol[j]==1; j--) sol[j]=0;
            if(j!=0)
                sol[j]=1;
            else ok=1;
        }


    }
    for(i=1; i<=n; i++)
        fout<<sol[i]<<'\n';
    return 0;
}
