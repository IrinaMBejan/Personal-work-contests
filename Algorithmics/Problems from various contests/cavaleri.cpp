#include <fstream>
#define MOD 9973
using namespace std;
ifstream fin("cavaleri.in");
ofstream fout("cavaleri.out");

int F[100005];
int main()
{
    int N;
    fin>>N;
    int a1=1, a2=1, a3;
    int i;
    F[1]=1;
    for(i=2;i<=N;i++)
    {
        F[i]=(a1+a2)%MOD;
        a1=a2;
        a2=F[i];
    }

    fout<<(F[N]+F[N-2]+2)%MOD<<'\n';
    return 0;
}
