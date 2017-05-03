#include <fstream>
#include <iomanip>

using namespace std;
ifstream fin("triunghi3.in");
ofstream fout("triunghi3.out");
int T[2][100];

int main()
{
    int i,j,n, lc, lp;
    int s=1;
    fin>>n;
//S(n) = 2^n - 2
    for(i=1;i<=n;i++)
        {
            s*=2;
            s%=2011;
        }
    s-=2;

	fout<<s<<'\n';

    return 0;
}
