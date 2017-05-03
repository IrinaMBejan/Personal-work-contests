#include <fstream>
#define NMAX 10005
using namespace std;
ifstream fin("hperm.in");
ofstream fout("hperm.out");

int n,M;
int H[NMAX];
int T[NMAX][NMAX];
void CalculeazaCombinari(int w);
int Rez(int n);

int main()
{
    fin>>n>>M;

    CalculeazaCombinari(n);
    for(int i = 1; i<=n;i++)
    {
        for(int j = 1; j<=i; j++)
            fout<<T[i][j]<<" ";
        fout<<'\n';
    }

    for(int i = 1;i<=n;i++)
        H[i] = -1;

    H[1] = 1;
    H[2] = 2;
    fout<<Rez(n)<<'\n';

    return 0;
}

void CalculeazaCombinari(int w)
{
    T[0][0] = T[1][0] = T[0][1] = 1;
    for(int i=1; i<=w; i++)
    {
        T[i][1] = T[i][i] = 1;
        for(int j =2; j<=i;j++)
            T[i][j] =(T[i-1][j-1] + T[i-1][j])%M;
    }
}

int Rez(int n)
{
    if(H[n] != -1) return H[n];

    int s = 1;
    while(s<=n)
        s= s<<1;
    s=s>>1;

    if(n <= s + s>>1)
    {
        for(int q = 1; q<=n-1;q++)
            H[n]+= ((T[n-1][q]*Rez(n-s<<1))%M*Rez(s<<1-1))%M;;
    }
    else
    {
        for(int q = 1; q<=n-1;q++)
            H[n]+= ((T[n-1][q]*Rez(s-1))%M*Rez(n-s<<1-1))%M;
    }

    return H[n];
}
