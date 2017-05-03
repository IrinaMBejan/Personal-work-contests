#include <fstream>

using namespace std;

ifstream fin("case1.in");

ofstream fout("case1.out");
int n, i, nr1, nr2 ,nr3, f,b,c;
int main()
{
    int x;
    fin>>n;
    for(i=1;i<=n;i++)
    {
        fin>>x;
        c+=(x%10);
        x/=10;
        f+=(x%10);
        x/=10;
        b+=(x%10);
        x/=10;
        if(x==1) nr1++;
        else if(x==2) nr2++;
        else nr3++;
    }
    fout<<nr1<<'\n'<<nr2<<'\n'<<nr3<<'\n'<<b<<'\n'<<f<<'\n'<<c<<'\n';
    return 0;
}
