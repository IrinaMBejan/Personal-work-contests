#include <fstream>
using namespace std;
ifstream fin("infinit.in");
ofstream fout("infinit.out");
long long int fib(int x);
int main()
{
    int Q, a, b;
    fin>>Q;
    for(int i = 1; i <= Q; i++)
    {
        fin>>a>>b;
        fout<< fib(b) - fib(a-1)<<'\n';
    }
    return 0;
}

long long int fib(int x)
{
    if( x == 1) return 1;
   // if( x == 2) return 2;

    int p=0, q=1, S=0, c;
    while(q<x)
    {
        c=p;
        p=q;
        q+=c;
    }
    if( q == x) return p;
    return p+ fib( x - p);
}
