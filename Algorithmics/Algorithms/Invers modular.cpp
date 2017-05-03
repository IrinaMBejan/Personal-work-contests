#include <fstream>
#define NMAX 1000


using namespace std;
ifstream fin("inversmodular.in");
ofstream fout("invermodular.out");
int f[NMAX];
int inf[NMAX];

int EuclidExtins(int a, int b, int &x, int&y);
int main()
{
    int i,x,y,T,M;

    fin>>M;
    f[0] = 1;
    for(i=1;i<=NMAX;i++)
    {
        f[i] = (f[i-1]*(i%M))%M;
        EuclidExtins(f[i],M,x,y);
        inf[i] = x;
    }

    fin>>T;
    int n,k;
    while(--T)
    {
        fin>>n>>k;
        fout<<((f[n]*inf[k])%M*inf[n-k])%M<<'\n';
    }

    return 0;
}

int EuclidExtins(int a, int b, int &x, int&y)
{
    if(b == 0)
    { x = 1; y = 0; return a; }

    int x1,y1;
    int d = EuclidExtins(b,a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
    return d;
}
