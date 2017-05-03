#include <fstream>

using namespace std;
ifstream fin("coduri.in");
ofstream fout("coduri.out");

int main()
{
    int n,i;
    long long int s;
    fin>>n;
    s=n*(n+1)*(2*n+1)/6;
    s=s*s*s*s;
    for(i=1;i<=n;i++)
        fout<<s*i<<'\n';
    return 0;
}
