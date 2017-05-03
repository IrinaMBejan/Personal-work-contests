#include <fstream>
#include <cstring>
#define Nmax 205
using namespace std;
ifstream fin("codul.in");
ofstream fout("codul.out");

char A[Nmax], B[Nmax];
int N,M,K;
int LCS[Nmax][Nmax];
char sol[Nmax];
int dir[Nmax][Nmax];
int LgMax;

void Citire();
void Subproblema();
void DetSol();
void Afisare();

int main()
{
    Citire();
    Subproblema();
    DetSol();
    Afisare();
    return 0;
}

void Citire()
{
    fin.getline(A+1,Nmax);
    N=strlen(A+1);
    fin.getline(B+1,Nmax);
    M=strlen(B+1);
}

void Subproblema()
{
    int i,j;
    for(i=N; i>=1; i--)
        for(j=M; j>=1; j--)
            if(A[i]==B[j])
            {
                LCS[i][j]=1+LCS[i+1][j+1];
                dir[i][j]=1;
            }
            else
            {
                if(LCS[i][j+1]>LCS[i+1][j])
                {
                    LCS[i][j]=LCS[i][j+1];
                    dir[i][j]=2;
                }
                else
                {
                    LCS[i][j]=LCS[i+1][j];
                    dir[i][j]=3;
                }
            }
    LgMax=LCS[1][1];
}

void DetSol()
{
    K=1;
    int cLgMax=LgMax;
    int sti=1, stj=1,ti=1,tj=1,i,j;
    while(K<=LgMax)
    {
        for(i=sti; i<=N; i++)
            for(j=stj; j<=M; j++)
                if(LCS[i][j]==cLgMax)
                    if(A[i]==B[j] && A[i]>sol[K])
                    {
                        sol[K]=A[i];
                        ti=i+1;
                        tj=j+1;
                    }
        cLgMax--;
        sti=ti;
        stj=tj;
        K++;
    }
}

void Afisare()
{
    fout<<sol+1<<'\n';
}
