#include <fstream>
#define Nmax 105
#define MOD 997
using namespace std;
ifstream fin("vizibil.in");
ofstream fout("vizibil.out");

long long int s[Nmax][Nmax];
long long int Comb[Nmax], rez;

void Citire();
void Afisare();
void Combinari();
void DetS();
int N,P,Q;

int main()
{
    int k;
    Citire();
    Combinari();
    DetS();
    if(P==1)
        rez=s[N-1][Q-1];
    else
        if(Q==1)
         rez=s[N-1][P-1];
        else
            for(k=P;k<=N-Q+1; k++)
             rez=(rez+s[k-1][P-1]*s[N-k][Q-1]*Comb[k-1])%MOD;
        Afisare();
    return 0;
}

void Citire()
{
    fin>>N>>P>>Q;
}

void Afisare()
{
    fout<<rez<<'\n';
}

void Combinari()
{
    long long int C[Nmax];
    int i,j;
    C[0]=Comb[0]=C[1]=1;
    for(i=2;i<N;i++)
    {
        for(j=1;j<i;j++)
            Comb[j]=(C[j]+C[j-1]%MOD);
        Comb[i]=1;
        for(j=1;j<=i;j++) C[j]=Comb[j];
    }
}

void DetS()
{
    int i,j;
    s[1][1]=1;
    for(i=2;i<N;i++)
        s[i][1]=(s[i-1][1]*(i-1))%MOD;
    for(i=2;i<N;i++)
        for(j=2; j<=i;j++)
            s[i][j]=(s[i-1][j-1]+(i-1)*s[i-1][j])%MOD;
}
