#include <fstream>
#include <cstring>
#define Nmax 205
using namespace std;
ifstream fin("LCS.in");
ofstream fout("LCS.out");

char A[Nmax], B[Nmax];
int N,M,K;
int LCS[Nmax][Nmax];
char sol[Nmax];
int dir[Nmax][Nmax];

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

        for(i=1;i<=N;i++)
        {
            for(j=1;j<=M;j++)
                fout<<LCS[i][j]<<" ";
            fout<<'\n';
        }
}

void DetSol()
{
    int i=1;
    int j=1;
    while(dir[i][j])
    {
        if(dir[i][j]==1)
        {
            sol[++K]=A[i];
            i++;
            j++;
        }
        else if(dir[i][j]==2) j++;
        else i++;
    }
}

void Afisare()
{
    int i;
    fout<<LCS[1][1]<<'\n';
    for(i=1; i<=K; i++)
        fout<<sol[i]<<" ";
    fout<<'\n';
}
