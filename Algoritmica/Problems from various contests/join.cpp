#include <fstream>
#define Nmax 35
#define INF 999999999999999999
#define Max 5
using namespace std;

ifstream fin("join.in");
ofstream fout("join.out");

long long int Nrmin[Nmax][Nmax];

int N;

int P[Max][Max];
int R[Nmax][Nmax][Max][Max];
int Val[Nmax][Nmax];

void Citire();
void Dinamica();
void Afisare();
void Prep();
int Calc(int A[Max][Max], int B[Max][Max], int P[Max][Max]);

int main()
{
    Citire();
    Prep();
    Dinamica();
    Afisare();
    return 0;
}

void Citire()
{
    int i,j,a,b;
    fin>>N;
    for (i=1; i<=N; i++)
        {
            fin>>Val[i][i];
            for(j=1;j<=Val[i][i];j++)
            {
                fin>>a>>b;
                R[i][i][a][b]++;
            }
        }
}

int Calc(int A[Max][Max], int B[Max][Max], int P[Max][Max])
{
    int k1,k2,k3,t;
    int S=0;
    for(k1=1;k1<Max;k1++)
        for(k2=1;k2<Max;k2++)
        {
            P[k1][k2]=0;
            if(A[k1][k2])
              for(k3=1;k3<Max;k3++)
               if(B[k2][k3])
                {
                    t=A[k1][k2]*B[k2][k3];
                    P[k1][k3]=t;
                    S+=t;
                }
        }
    return S;
}

void Prep()
{
        int z,i,j;
        for (i=1; i<N; i++)
            Val[i][i+1]=Calc(R[i][i],R[i+1][i+1],R[i][i+1]);
        for (z=3;  z<=N;  z++)
             for (i=1; i<=N-z+1; i++)
                {
                        j = i+z-1;
                        Val[i][j]=Calc(R[i][j-1], R[j][j],R[i][j]);
                }

}
void Dinamica()
{
    int i,j;
    for (i=1; i<N; i++)
        Nrmin[i][i+1]=Val[i][i]*Val[i+1][i+1];

    int k,z, kmin;
    long long int minim,t;
    for (z=3;  z<=N;  z++)
        for (i=1; i<=N-z+1; i++)
        {
            j = i+z-1;
            minim=INF;
            for (k=i+1; k<=j; k++)
            {
                t=Nrmin[i][k-1]+Nrmin[k][j]+Val[i][k-1]*Val[k][j];
                if (minim>t)
                    minim=t;
            }
            Nrmin[i][j]=minim;
        }
}

void Afisare()
{
    fout<<Nrmin[1][N]<<'\n';
}
