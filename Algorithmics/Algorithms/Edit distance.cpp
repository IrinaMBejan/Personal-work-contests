#include <fstream>
#include <cstring>
#define Nmax 205
#define INF 999999
using namespace std;
ifstream fin("edit.in");
ofstream fout("edit.out");

char A[Nmax], B[Nmax];
int N,M,K;
int Cmin[Nmax][Nmax];
int sol[Nmax];
int c[7];
char op[7][10]= {"","copy","insert","delete","replace","twiddle","kill"};

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
    fin.getline(A,Nmax);
    N=strlen(A);
    fin.getline(B,Nmax);
    M=strlen(B);
    int i;
    for(i=1; i<=6; i++)
        fin>>c[i];
}

void Subproblema()
{
    int i,j;
    for(j=0; j<M; j++)
        Cmin[N][j]=c[2]*(M-j);
    for(i=0; i<N; i++)
        Cmin[i][M]=min(c[6], c[3]*(N-i));
    int minim;
    for(i=N-1; i>=0; i--)
        for(j=M-1; j>=0; j--)
        {
            minim=c[2]+Cmin[i][j+1];

            if(A[i]==B[j] && c[1]+Cmin[i+1][j+1]<minim)
                minim=c[1]+Cmin[i+1][j+1];
            //       if(c[2]+Cmin[i][j+1]<minim)
            //      minim=c[2]+Cmin[i][j+1];
            if(c[3]+Cmin[i+1][j]<minim)
                minim=c[3]+Cmin[i+1][j];
            if(c[4]+Cmin[i+1][j+1]<minim)
                minim=c[4]+Cmin[i+1][j+1];
            if(i+1<N && j+1<M && A[i]==B[j+1]&& A[i+1] == B[j] && c[5]+Cmin[i+2][j+2]<minim)
                minim=c[5]+Cmin[i+2][j+2];
            if(c[6]+Cmin[N][j]<minim)
                minim=c[6]+Cmin[N][j];

            Cmin[i][j]=minim;
        }
}

void DetSol()
{
    int i=0;
    int j=0;
    while(i<N || j<M)
    {
        if(A[i]==B[j] && c[1]+Cmin[i+1][j+1]==Cmin[i][j])
            i++,j++, sol[++K]=1;
        else if(c[2]+Cmin[i][j+1]==Cmin[i][j])
            j++, sol[++K]=2;
        else  if(c[3]+Cmin[i+1][j]==Cmin[i][j])
            i++, sol[++K]=3;
        else  if(c[4]+Cmin[i+1][j+1]==Cmin[i][j])
            i++, j++, sol[++K]=4;
        else   if(i+1<N && j+1<M && A[i]==B[j+1]&& A[i+1] == B[j] && c[5]+Cmin[i+2][j+2]==Cmin[i][j])
            i+=2, j+=2, sol[++K]=5;
        else
            sol[++K]=6, i=N;
    }
}

void Afisare()
{
    /*
          for(i=1;i<=N;i++)
            {
                for(j=1;j<=M;j++)
                    fout<<LCS[i][j]<<" ";
                fout<<'\n';
            }*/
    int i;
    fout<<Cmin[0][0]<<'\n';
    for(i=1; i<=K; i++)
        fout<<op[sol[i]]<<'\n';
}
