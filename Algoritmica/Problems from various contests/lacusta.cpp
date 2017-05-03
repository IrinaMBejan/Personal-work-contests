#include <fstream>
#define Nmax 105
#define INF 999999
using namespace std;

ifstream fin("lacusta.in");
ofstream fout("lacusta.out");
int a[Nmax][Nmax];
int S[Nmax][Nmax];
int N,M;


void Citire();
void Initializare();
void DetSubpro();
void Afisare();

int main()
{
    Citire();
    Initializare();
    DetSubpro();
    Afisare();
    return 0;
}

void Citire()
{
    int i,j;
    fin>>N>>M;
    for(i=1; i<=N; i++)
    {
        for(j=1; j<=M; j++)
            fin>>a[i][j];
    }
}

void Initializare()
{
    int i,j;
    for(i=1; i<=N; i++)
        S[1][i]=a[1][i];
    for(j=2;j<=M;j++)
    {
        S[2][j]=a[1][1]+a[1][j]+a[2][j];
    }
    S[2][1]=1000;
}

void DetSubpro()
{
    int i,j,k,min,poz;
    for(i=3; i<=N; i++)
        for(j=1; j<=M; j++)
        {
            min=INF;
            for(k=1; k<=M; k++)
                if(k!=j && S[i-1][k]<min)
                    min=S[i-1][k];
            S[i][j]=a[i][j]+a[i-1][j]+min;
        }
        min=INF;
        for(k=1; k<M; k++)
            if(S[N][k]<min) min=S[N][k];
        S[N][M]=min+a[N][M];

}

void Afisare()
{
   /*int i,j;
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=M;j++)
                        fout<<S[i][j]<<" ";
        fout<<'\n';
    }*/
    fout<<S[N][M]<<'\n';
}
