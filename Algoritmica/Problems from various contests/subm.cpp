#include <fstream>

using namespace std;
ifstream fin("subm.in");
ofstream fout("subm.out");
long long int fib[50];
int main()
{
    long long int a1=1,a2=1,a3;
    for(int i=1;i<=50;i++)
    {
        fib[i]=a1;
        a3=a1+a2;
        a1=a2;
        a2=a3;
    }

    int N, T, x, p, current, i;

    fin>>N;
    fin>>T;

    while(T)
    {
        fin>>x;
        i = N; current = fib[i]; p = 1;
        while(1)
        {
            if( x > current )
                {
                    current += fib[--i];
                    p++;
                }
            else
                if( x <= current )
                {
                    fout<<p<<' ';
                    if(x-1 == current-fib[i])
                        break;
                    else
                        x+=fib[i]+fib[i-1]-1;
                }

        }
        fout<<'\n';
        --T;
    }
    return 0;
}

