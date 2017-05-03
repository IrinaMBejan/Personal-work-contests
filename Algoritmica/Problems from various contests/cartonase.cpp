#include <fstream>
#define Nmax 20
using namespace std;
ifstream fin("cart.in");
ofstream fout("cart.out");

int N,K;
int prim[100];
int p[Nmax];
int put (int x, int exp);
int main()
{
    fin>>N>>K;
    int i,x,j;

    for(i=0;i<=100;i++)
        prim[i]=999999;

    for(i=1;i<=N;i++)
    {
        int counter = 0;
        fin>>x;
        if(x = 1)
            prim[x] = 1;
        if(x%2==0)
        {
            while(x%2==0)
                {
                    x/=2;
                    counter++;
                }
            if(counter < prim[2]) prim[2] = counter;
        }

        for(j=3;j*j<=x;j+=2)
            if(x%j==0)
            {
                counter = 0;
                while(x%j==0)
                {
                    x/=j;
                    counter++;
                }
                if(counter < prim[j]) prim[j] = counter;
            }

        if(x) prim[x] = 1;
    }
    K--;

    N=0;
    for(i=1;i<=100;i++)
        if(prim[i]<999999)
            p[++N] = put(i, prim[i]);

    long long int sol=0, nr;
    int semn;
    for(int i=1;i<(1<<N);i++)
    {
        nr=1; semn=0;
        for(j=0;j<N;j++)
            if(i&(1<<j))
            {
                semn^=1;
                nr*=1LL*p[j+1];
            }

        if(!semn)
            semn=-1;
        sol+=(1LL*semn*(K/nr));
    }
    fout<<sol<<'\n';
    return 0;
}

int put (int x, int exp)
{
    int nr = 1;
    while(exp)
    {
        nr*=x;
        exp--;
    }
    return nr;
}
