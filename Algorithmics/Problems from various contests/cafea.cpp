#include <fstream>
#define Nmax 10005
#define INF 99999
using namespace std;

ifstream fin("cafea.in");
ofstream fout("cafea.out");

int P[Nmax], D[Nmax];
int T[Nmax];
int N,K;
int main()
{
    int i;
    fin>>N>>K;
    for(i=1;i<=K;i++)
    {
        fin>>P[i]>>D[i];
    }
    for(i=1;i<=N;i++)
        T[i]=INF;
    int cursor = 1;
    for(i=1;i<=N;i++)
    {
        if(P[cursor] == i)
        {
            while(P[cursor] == i)
            {
                T[i+D[cursor]-1] = min(T[i+D[cursor]-1], T[i-1] + D[cursor]);
                cursor++;
            }
        }
        else
            T[i] = min(T[i],T[i-1]);
    }
    fout<<N-T[N]<<'\n';
    return 0;
}
