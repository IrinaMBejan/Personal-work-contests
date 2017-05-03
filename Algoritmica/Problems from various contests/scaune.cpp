#include <fstream>
#define MOD 30103
using namespace std;
ifstream fin("scaune.in");
ofstream fout("scaune.out");

int N;
long long int p;
int main()
{
    fin>>N;
    p=1;
    for(int i=3;i<=2*N-1;i+=2)
        p=(p*i)%MOD;
    fout<<p<<'\n';
    return 0;
}
