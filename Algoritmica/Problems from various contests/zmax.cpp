#include <fstream>
#define Nmax 501
using namespace std;
ifstream fin("zmax.in");
ofstream fout("zmax.out");

int n,m;
int A[Nmax][Nmax],S[Nmax][Nmax],D[Nmax][Nmax],C[Nmax][Nmax],X[Nmax][Nmax],Y[Nmax][Nmax];

void afisare(int mat[Nmax][Nmax])
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            fout<<mat[i][j]<<" ";
        fout<<'\n';
    }
     fout<<'\n';
}
int main()
{
    int i,j;
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
           {
                fin>>A[i][j];
                if (A[i][j] + X[i][j-1] > A[i][j])
                        X[i][j] = A[i][j] + X[i][j-1];
                else
                        X[i][j] = A[i][j];
            }
         for (j=m;j>=1;j--)
        {
            if (A[i][j] + Y[i][j+1] > A[i][j])
                    Y[i][j] = A[i][j] + Y[i][j+1];
            else
                    Y[i][j] = A[i][j];
        }
    }


    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
           {
               S[i][j]=A[i][j]+X[i][j-1];
               D[i][j]=A[i][j]+Y[i][j+1];
           }

    for(j=2;j<=m;j++)
        C[n-1][j]=A[n-1][j]+D[n][j-1];
    for(i=n-2;i>=1;i--)
    {
        C[i][2] = A[i][2] + D[i+1][1];
        for(j=3;j<=m;j++)
            C[i][j]=max(C[i+1][j-1]+A[i][j],D[i+1][j-1] + A[i][j]);
    }

    long long int Max=-1000000;
    for(i=1;i<=n-2;i++)
    {
        for(j=3;j<=m;j++)
            if(S[i][j]+C[i+1][j-1]>Max) Max=S[i][j]+C[i+1][j-1];
    }

    fout<<Max<<'\n';
    return 0;
}
