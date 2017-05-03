#include <fstream>
#define Nmax 10
using namespace std;
ifstream fin("prime1.in");
ofstream fout("prime1.out");

int p[Nmax];
int N,K;

int main()
{
    fin>>N;
    int i;
    for(i=1;i<=N;i++)
    {
        fin>>p[i];
    }
    fin>>K;

    int sol=0, nr, semn, j;
    for(int i=1;i<(1<<N);i++)
    {
        nr=1; semn=0;
        for(j=0;j<N;j++)
            if(i&(1<<j))
            {
                semn^=1;
                nr*=p[j+1];
            }

        if(!semn)
            semn=-1;
        sol+=(semn*(K/nr));
    }
    fout<<sol<<'\n';
    return 0;
}
