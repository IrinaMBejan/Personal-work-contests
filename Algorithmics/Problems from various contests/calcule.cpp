#include <fstream>
#define Nmax 100005
#define Rmax 50005
#define MOD 20011
using namespace std;
ifstream fin("calcule.in");
ofstream fout("calcule.out");
void Citire();
long long int CerintaA();
int CerintaB();
int CautaBin(int x);

int v[Nmax];
int fina[Nmax];
int R[Rmax];
int N,K;
int Nrs;

int main()
{
    Citire();
    fout<<CerintaA()<<'\n';
    fout<<CerintaB()<<'\n';
    return 0;
}

void Citire()
{
    fin>>N>>K;
    int i;
    for(i=1; i<=N; i++)
        fin>>v[i];
}

int CerintaB()
{
    int i;
    int nr=0;
    long long int S=0;
    for(i=1; i<=N; i++)
    {
        S=(S+v[i])%K;
        R[S]++;
    }
    nr=((R[0]%MOD)*((R[0]%MOD)+1)/2)%MOD;

    for(i=1; i<K; i++)
        nr=(nr+((R[i]%MOD)*((R[i]%MOD)-1)/2)%MOD)%MOD;

    return nr;
}

long long int CerintaA()
{
    int poz;
    int i;
    for(i=1; i<=N; i++)
    {
        poz=CautaBin(v[i]);
        fina[poz]=v[i];
        if(poz==Nrs)
            Nrs+=1;
    }
    return Nrs;
}

int CautaBin(int x)
{
    int st, dr, mij;
    st=0;
    dr=Nrs;
    while(st<dr)
    {
        mij=(st+dr)/2;
        if(fina[mij]>=x)
            st=mij+1;
        else
            dr=mij;
    }
    return st;
}

