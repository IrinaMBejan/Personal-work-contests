#include <fstream>
#include<iomanip>
using namespace std;
ifstream fin("desert.in");
ofstream fout("desert.out");
int n,k;
long double p;


long double dist(int n)
{
    if(n<=2) return (long double) k*n/p;
    return k/((2*n-3)*p)+dist(n-1);
}

int main()
{
    long double d=0;
    fin>>n>>k>>p;
    p=p/100;
    d=dist(n);
    fout << fixed;
    fout<<setprecision(3)<<d<<'\n';
    return 0;
}


