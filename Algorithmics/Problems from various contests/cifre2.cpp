#include <fstream>

using namespace std;
ifstream fin("cifre2.in");
ofstream fout("cifre2.out");

int main()
{
    int n,s=0,cif,p=1,m=0;
    fin>>n>>cif;
    fout<<n;
    while(n>=cif)
    {
        if(n%10>cif) s+=(n/10+1)*p;
       // else if(n%10==cif) s+=(n/10)*p+m+1;
        else s+=(n/10)*p;
        m+=(n%10)*p;
        n/=10;
        m*=10;
    }
    fout<<s;
    return 0;
}
