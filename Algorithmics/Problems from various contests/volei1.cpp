#include <fstream>
#include <algorithm>
#define Nmax 2005
using namespace std;
ifstream fin("volei1.in");
ofstream fout("volei1.out");


int comp(int a, int b)
{
    return a<b;
}

int f[Nmax];
int b[Nmax];
int plas[Nmax];
int N,M;
int main()
{
    int i,j;
    fin>>N;
    for(i=1; i<=N; i++)
        fin>>f[i];
    f[N+1] = f[1];
    f[0] = f[N];
    fin>>M;
    for(i=1; i<=M; i++)
        fin>>b[i];
    sort(b+1, b+M+1, comp);

    int u,k=0;
    for(i=1; i<=M; i++)
    {
        u=0;
        for(j=1; j<=N; j++)
            if(plas[j]==0 && b[i]>max(f[j],f[j+1]))
            {
                u=j;
                break;
            }
        if(u>0)
        {
            plas[u] = b[i];
            k++;
        }
    }

    fout<<k<<'\n';
    for(i=1; i<=N; i++)
        if(plas[i])
            fout<<f[i]<<" -"<<plas[i]<<" ";
        else
            fout<<f[i]<<" ";
    fout<<'\n';

    return 0;
}
