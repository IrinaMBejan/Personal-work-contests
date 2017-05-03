#include <fstream>
#include <algorithm>
#define NMAX 1005
using namespace std;
ifstream fin("grad.in");
ofstream fout("grad.out");

int N;
int d[NMAX];
int a[NMAX];
int main()
{
    int i, s = 0;
        fin>>N;
    for(i=1;i<=N;i++)
        {
            fin>>d[i];
            s+=d[i];
        }
    if(s == 2*N-2)
    {
        sort(d+1, d+N+1);
        int terminal, neterminal;
        for(terminal = 1; terminal <N; terminal++)
        {
            for(neterminal = terminal+1; neterminal<N && d[neterminal] == 1; neterminal++);
            a[terminal] = neterminal;
            d[neterminal]--;
        }
    }

    for(i=1;i<=N; i++)
        fout<<a[i]<<" ";




    return 0;
}
