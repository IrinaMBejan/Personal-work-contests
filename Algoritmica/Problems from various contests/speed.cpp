#include <fstream>
#define Nmax 300
#define INF -100000000
using namespace std;
ifstream fin("speed.in");
ofstream fout("speed.out");

int Emax[Nmax+5][Nmax+5],Smax[Nmax+5][Nmax+5],v[Nmax+5][Nmax+5];
int N;
void Citire();
int Dinamica();

int main()
{
    Citire();
    fout<<Dinamica()<<'\n';
    return 0;
}

void Citire()
{
    fin>>N;
    int i,j;
    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
            fin>>v[i][j];
}

int Dinamica()
{
    int i,j;
    Smax[1][1]=1, Emax[1][1]=1;
    for(i=2;i<=N;i++)
        {
           Emax[1][i]=Emax[1][j-1] + v[1][j-1] - v[1][j];
           Smax[i][1]=Smax[i-1][1] + v[i-1][1] - v[i][1];
        }

    for(i=2;i<=N;i++)
        for(j=2;j<=N;j++)
        {
            Emax[i][j]=max(0,Emax[i][j-1] + v[i][j-1] - v[i][j]);
            Emax[i][j]=max(Emax[i][j],(Smax[i][j-1] + v[i][j-1] - v[i][j])/2);
            Smax[i][j] = max(0, Smax[i-1][j] + v[i-1][j] - v[i][j]);
            Smax[i][j]=max(Smax[i][j],(Emax[i-1][j] + v[i-1][j] - v[i][j])/2);
        }
    for(i=1;i<=N;i++)
        {for(j=1;j<=N;j++)
        fout<<Emax[i][j]<<" ";
        fout<<'\n';}
    return max(Smax[N][N], Emax[N][N]);
}
