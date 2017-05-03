#include <fstream>
#include<cmath>
#define Nmax 81

using namespace std;
ifstream fin("remi.in");
ofstream fout("remi.out");

int N,K;
int  v[Nmax];
int S;
int d[Nmax][Nmax][Nmax]; //pen minima pt a grupe formate din gr i..j;

void Citire();
void DetSubpro();
void Afisare();

int main()
{
    Citire();
    DetSubpro();
    Afisare();
    return 0;
}

void Citire()
{
    int i;
    fin>>N>>K;
    for(i=1; i<=N; i++)
    {
        fin>>v[i];
        S+=v[i];
    }
    S/=K;
}

void DetSubpro()
{
    int i,j,l,k;
    for(i=1; i<=N; i++)
        for(j=1; j<=N; j++)
        {
            d[1][i][j]=0;
            for(k=i; k<=j; k++)
                d[1][i][j]+=v[k];
            d[1][i][j]=abs(d[1][i][j]-S);
        }
    int niv,mini,tai;
    for(niv=2; niv<=K; niv++)
        for(i=1; i<=N; i++)
            for(j=i+niv-1; j<=N; j++)
            {
                mini=1000000;
                for(tai=i; tai<j; tai++) //pt a obt niv grupe, taiem i...p in l grupe si p+1..j in niv-l grupe
                    for(l=1; l<=min(niv-1,tai-i+1) && niv-l<=j-tai; l++)
                        if(mini>d[l][i][tai]+d[niv-l][tai+1][j]) mini=d[l][i][tai]+d[niv-l][tai+1][j];
                d[niv][i][j]=mini;
            }
}

void Afisare()
{
    fout<<d[K][1][N]<<'\n';
}
