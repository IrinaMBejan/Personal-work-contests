#include <fstream>
#define mod 100003
using namespace std;
ifstream fin("2sah.in");
ofstream fout("2sah.out");

long long int put(long long int baza, long long int exp);
long long int A[5][5], S[3][3], C[3][3],n,k,p;
int main()
{
    fin>>p;
    fin>>n>>k;
    if( p == 1)
        fout<<put(3,k-1);
    else
    {
        long long int i,j,q;
        k=n+2-k;
        for(i=0; i<3; i++)
        {
            S[i][i]=1;
            A[2][i]=1;
        }
        A[0][1]=A[1][2]=1;
        for(; k; k>>=1)
        {
            if(k%2)
            {
                for(i=0; i<3; i++)
                    for(j=0; j<3; j++)
                    {
                        C[i][j]=0;
                        for(q=0; q<3; q++)
                            C[i][j]=(C[i][j]+S[i][q]*A[q][j])%mod;
                    }
                for(i=0; i<3; i++)
                    for(j=0; j<3; j++)
                        S[i][j]=C[i][j];

            }
            for(i=0; i<3; i++)
                for(j=0; j<3; j++)
                {
                    C[i][j]=0;
                    for(q=0; q<3; q++)
                        C[i][j]=(C[i][j]+A[i][q]*A[q][j])%mod;
                }
            for(i=0; i<3; i++)
                for(j=0; j<3; j++)
                    A[i][j]=C[i][j];
        }
        fout<<S[1][2]<<'\n';

    }
    return 0;
}

long long int put(long long int baza, long long int exp)
{
    long long int h;
    if(exp == 0)
        return baza;

    if(exp%2 == 1)
    {
        h = put(baza, exp/2);
        return ((h*h)%mod*baza)%mod;
    }
    else
    {
        h = put(baza, exp/2);
        return (h*h)%mod;
    }
}
