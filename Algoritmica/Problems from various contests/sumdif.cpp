#include <fstream>
#include<cstring>
#include<algorithm>
#define Nmax 1005
using namespace std;
ifstream fin("sumdif.in");
ofstream fout("sumdif.out");

int N;
int K;
struct carton
{
    int S;
    int a, b;
} P[Nmax];

int compare(carton a, carton b)
{
    return a.S>b.S;
}

int main()
{
    fin>>N>>K;
    int i;
    for(i=1; i<=N; i++)
    {
        fin>>P[i].a>>P[i].b;
        P[i].S=P[i].a+P[i].b;
    }
    sort(P+1, P+N+1,compare);
    int Sum=0;
    for(i=1; i<=K; i++)
        Sum+=max(P[i].a,P[i].b);
    for(i=K+1; i<=N; i++)
        Sum-=min(P[i].a,P[i].b);
    fout<<Sum<<'\n';
}
