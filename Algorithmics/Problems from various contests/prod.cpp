#include <fstream>
#define Nmax 1000
#define INF 999999999999999999
using namespace std;
ifstream fin("prod.in");
ofstream fout("prod.out");

long long int Nrmin[Nmax][Nmax];
int N;
long long int D[Nmax];

void Citire();
void Dinamica();
void Solutie(int i, int j);
void Afisare();

int main()
{
    Citire();
    Dinamica();
    Afisare();
    return 0;
}

void Citire()
{
    int i;
    fin>>N;
    for (i=0; i<=N; i++)
        fin>>D[i];
}

void Dinamica()
{
    int i,j;
    for (i=1; i<N; i++)
        Nrmin[i][i+1]=D[i] * D[i-1]*D[i+1];

    int k,z, kmin;
    long long int minim,t;
    for (z=3;  z<=N;  z++)
        for (i=1; i<=N-z+1; i++)
        {
            j = i+z-1;
            minim=INF;
            for (k=i+1; k<=j; k++)
            {
                t=Nrmin[i][k-1]+Nrmin[k][j]+D[k-1]*D[i-1]*D[j];
                if (minim>t)
                    minim=t, kmin=k;
            }
            Nrmin[i][j]=minim;
            Nrmin[j][i]=kmin;
        }
}

void Solutie(int i, int j)
{
    if(i==j-1)
    {
        fout<<"A"<<i<<"xA"<<i+1;
    }
    else if(i==j)
        fout<<"A"<<i;
    else
    {

        fout<<"(";
        Solutie(i,Nrmin[j][i]-1);
        fout<<")x(";
        Solutie(Nrmin[j][i],j);
        fout<<")";
    }
}

void Afisare()
{
    fout<<Nrmin[1][N]<<'\n';
    Solutie(1,N);
}
