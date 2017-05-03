#include <fstream>
#define NMAX 100005
using namespace std;
ifstream fin("lista.in");
ofstream fout("lista.out");

int luat[NMAX];
int a[NMAX];

struct muchie
{
    int a, b;
}sol[NMAX];
int k;

int main()
{
    int N;
    fin>>N;
    int i,j;
    for(i=1;i<=N-1;i++)
    {
        fin>>a[i];
        luat[a[i]]++;
    }

    muchie m;

    for(i=1;i<=N-1;i++)
    {
        m.a = a[i];
        for(j=1;j<=N;j++)
            if(luat[j] == 0)
            {
                m.b = j;
                luat[j] = 1;
                break;
            }
        luat[a[i]]--;
        sol[++k] = m;
    }

    for(i=1;i<=k;i++)
    {
        fout<<sol[i].a<<" "<<sol[i].b<<'\n';
    }

    return 0;
}
