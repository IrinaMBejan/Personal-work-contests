#include <fstream>
#include <algorithm>
#define NMAX 1005
using namespace std;
ifstream fin("arb.in");
ofstream fout("arb.out");

int N;
int d[NMAX];
int a[NMAX];
int s;

void gen(int k);
void afisareArb();

int main()
{
    fin>>N;
    d[0] = 1;
    gen(1);
    return 0;
}

void gen(int k)
{
    if(k==N+1)
        {
            if(s == 2*N-2)
                afisareArb();
        }
    else
    {
        int i;
        for(i=d[k-1]; i<N && s<=2*N-2;i++)
        {
            d[k] = i;
            s += i;
            gen(k+1);
            s -= i;
        }
    }
}

void afisareArb()
{

    int terminal, neterminal;
    for(terminal = 1; terminal <N; terminal++)
    {
       for(neterminal = terminal+1; neterminal<N && d[neterminal] == 1; neterminal++);
       a[terminal] = neterminal;
       d[neterminal]--;
    }
    int i;
    for(i=1;i<=N; i++)
        fout<<a[i]<<" ";
        fout<<'\n';

}
