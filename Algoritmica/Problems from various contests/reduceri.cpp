#include <fstream>
#include <cmath>
#define Nmax 105
using namespace std;
ifstream fin("reduceri.in");
ofstream fout("reduceri.out");

int A[Nmax][Nmax];
int v[Nmax];
int N;


void  Citire();
void DetSubpro();
void Afisare();
int Cost(int i, int j);

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
    fin>>N;
    for(i=1; i<=N; i++)
        fin>>v[i];
}

void DetSubpro()
{
    int i,k,j,maxim;
    for(i=1;i<=N;i++)
        A[i][i]=v[i];
    for(j=1;j<=N;j++)
        for(i=1;i+j<=N;i++)
        {
            //fout<<i<<" "<<i+j<<'\n';
            maxim=Cost(i,i+j);
            for(k=i;k<i+j;k++)
                if(A[i][k]+A[k+1][i+j]>maxim)
                    maxim=A[i][k]+A[k+1][i+j];
            A[i][i+j]=maxim;
        }
}

void Afisare()
{
    fout<<A[1][N]<<'\n';
}

int Cost(int i, int j)
{
    return abs(v[i]-v[j])*(j-i+1);
}
