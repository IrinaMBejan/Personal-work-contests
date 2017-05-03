#include <fstream>
#define MOD 9901
using namespace std;
ifstream fin("covor.in");
ofstream fout("covor.out");

long long int m,k;
long long int DeterminaPerechi(long long int m);
long long int CalcAranjamente(long long int n, long long int k);


int main()
{
    fin>>m>>k;
    fout<<CalcAranjamente(DeterminaPerechi(m),k)<<'\n';
    return 0;
}

long long int CalcAranjamente(long long int n,long long int k)
{
    if(k>n) return 0;
    long long int A=1;
    long long int i;
    for(i=0;i<=k-1;i++)
        A=1LL*(((n-i)%MOD)*A)%MOD;
    return A;
}

long long int DeterminaPerechi(long long int M)
{
    long long int n=1,i,c=0;
    if(M%2==0)
    {
        while(M%2==0)
        {
            c++;
            M/=2;
        }
        n*=(2*c+1);
    }
    for (i=3;i*i<=M;i+=2)
    {
        if(M%i==0)
        {
            c=0;
            while(M%i==0)
            {
                c++;
                M/=i;
            }
            n*=(2*c+1);
        }
    }
    if(M!=1)
        n*=3;
    return n;
}

