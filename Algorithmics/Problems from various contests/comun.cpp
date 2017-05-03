#include <fstream>
#include <cstring>
#define Nmax 205
#define INF 999999
using namespace std;
ifstream fin("comun.in");
ofstream fout("comun.out");

int A[Nmax], B[Nmax];
int N,M,K;
int LCS[Nmax][Nmax];
int Cost[Nmax][Nmax];

void Citire();
void Subproblema();
void Afisare();
int abs(int x);

int main()
{
    Citire();
    Subproblema();
    Afisare();
    return 0;
}

void Citire()
{
    fin>>N>>M;
    int i;
    for(i=1; i<=N; i++)
        fin>>A[i];
    for(i=1; i<=M; i++)
        fin>>B[i];
}

void Subproblema()
{
    int i,j;
    for(i=1; i<=N; i++)
        for(j=1; j<=M; j++)
            if(A[i]==B[j])
                LCS[i][j]=1+LCS[i-1][j-1];
            else
            {
                if(LCS[i][j-1]>LCS[i-1][j])
                    LCS[i][j]=LCS[i][j-1];
                else
                    LCS[i][j]=LCS[i-1][j];

            }
    int ok=0;
    i=1;
    while( i<=M)
    {
        if(A[1]==B[i])
            ok=1;
        if(!ok)
            Cost[1][i]=INF;
        else
            Cost[1][i]=(i-1)*A[1];
        i++;
    }

    ok=0;
    i=1;
    while( i<=N)
    {
        if(A[i]==B[1])
            ok=1;
        if(!ok)
            Cost[i][1]=INF;
        else
            Cost[i][1]=(i-1)*B[1];
        i++;
    }

    for(i=2; i<=N; i++)
        for(j=2; j<=M; j++)
        {
            if(A[i]==B[j])
            {
                if(LCS[i][j]==1)
                    Cost[i][j]=abs(i-j)*A[i];
                else
                    Cost[i][j]=abs(i-j)*A[i]+Cost[i-1][j-1];

                if(LCS[i-1][j]==LCS[i][j] && Cost[i-1][j]<Cost[i][j])
                    Cost[i][j]=Cost[i-1][j];
                if(LCS[i][j-1]==LCS[i][j] && Cost[i][j-1]<Cost[i][j])
                    Cost[i][j]=Cost[i][j-1];
            }
            else
            {
                if(LCS[i-1][j] > LCS[i][j-1])
                    Cost[i][j] = Cost[i-1][j];
                if(LCS[i-1][j] < LCS[i][j-1])
                    Cost[i][j] = Cost[i][j-1];
                if(LCS[i-1][j] == LCS[i][j-1])
                    Cost[i][j] = min(Cost[i-1][j] , Cost[i][j-1]);
            }
        }
}

void Afisare()
{
    int i;
    fout<<Cost[N][M]<<'\n';
}

int abs(int x)
{
    if(x<0)
        return x*(-1);
    return x;
}
