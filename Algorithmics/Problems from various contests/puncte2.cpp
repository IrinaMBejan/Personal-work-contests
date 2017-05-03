#include <fstream>

using namespace std;
ifstream fin("puncte2.in");
ofstream fout("puncte2.out");
long long int N;
long long int Nr[20];
int main()
{
    fin>>N;
    Nr[1]=1;
    int i,j;
    for(i=2;i<=N;i++)
    {
       Nr[i] = Nr[i-1]*2;
       for(j=1;j<=i-2;j++)
            Nr[i]+= (1ll*Nr[j]*Nr[i-j-1]);
    }
    fout<<Nr[N]<<'\n';
    return 0;
}
