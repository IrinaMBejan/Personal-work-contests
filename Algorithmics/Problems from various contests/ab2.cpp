#include <fstream>
#define MAX_A 30005
using namespace std;
ifstream fin("ab2.in");
ofstream fout("ab2.out");
int N, A, B, nr[MAX_A];

int main()
{
    int i,j,n;
    fin>>N>>A>>B;
    n = N;
    for (i=A-1; i>=0; --i)
    {
        nr[i]=min(n-i, B);
        n-=nr[i];
    }
    for (i=0; i<A; ++i)
    {
        for (j=n+nr[i]; j>n; --j)
            fout<<j<<' ';
        n += nr[i];
    }
    fout<<'\n';
    return 0;
}
