#include <fstream>
#include<cmath>
#define Nmax 505
#define Kmax 205
using namespace std;
ifstream fin("produs.in");
ofstream fout("produs.out");

double Cmin[Nmax][Kmax];
int N,K,C;
int nr[Nmax];
int nrc[Nmax][Kmax];

void Citire();
void Dinamica();
double loga(int a, int b);
void Afisare(int i, int j);

int main()
{
    Citire();
    Dinamica();
    Afisare(1,K);
    return 0;
}

void Citire()
{
    int i;
    double x;
    fin>>N>>K>>C;
    for (i=1; i<=N; i++)
        fin>>nr[i];
}

void Dinamica()
{
    int i,j;

    for (i=1; i<=N; i++)
        if(N-i+1<=C && nr[i]!=0)
            Cmin[i][0]=loga(i,N);
        else
            Cmin[i][0]=-1;

    for(j=1;j<=K;j++)
        Cmin[N][j]=-1;

    int p,maxi;
    double T;
    for(j=1; j<=K; j++)
        for(i=N-1; i>=1; i--)
        {
            if(N-i+1<j+1 || nr[i]==0 || N-i+1>(j+1)*C)
                Cmin[i][j]=-1;
            else
            {
                maxi=-1;
                for(p=1; p<=C; p++)
                    if(Cmin[i+p][j-1]!=-1 && nr[i+p]!=0)
                        {
                            T=loga(i, i+p-1)+Cmin[i+p][j-1];
                            if(maxi<T)
                                {
                                    maxi=T;
                                    nrc[i][j]=p;
                                }
                        }
                 Cmin[i][j]=maxi;
            }
        }
}

double loga(int a, int b)
{
    int num=0,i;
    for(i=a;i<=b;i++)
        num=num*10+nr[i];
    return log10((double)num);
}


void Afisare(int i, int j)
{
    int q;
    if(j==0)
    {
        for(q=i;q<=N;q++)
            fout<<nr[q];
        fout<<'\n';
    }
    else
    {
        for(q=i; q<=i+nrc[i][j]-1; q++)
            fout<<nr[q];
        fout<<"*";
        Afisare(i+nrc[i][j],j-1);
    }
}
