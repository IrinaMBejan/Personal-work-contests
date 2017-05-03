#include <fstream>
#define NMAX 1001
using namespace std;
ifstream fin("kperms.in");
ofstream fout("kperms.out");

int PD[NMAX][NMAX];
int main()
{
    int N,K,i,j;
    fin>>N>>K;
    PD[1][1]=1;
    for(i=2; i<=N; i++)
        for(j=1; j<=K; j++)
            {
                PD[i][j]=(i-j+1)*PD[i-1][j-1] + j*PD[i-1][j];
                PD[i][j]%=666013;
            }
    fout<<PD[N][K]<<'\n';
    return 0;
}
