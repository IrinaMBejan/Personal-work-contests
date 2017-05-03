#include <fstream>
#include<algorithm>
#define Nmax 10005

using namespace std;
ifstream fin("sport.in");
ofstream fout("sport.out");

int H[Nmax], G[Nmax];
int main()
{
    int N,i,j;
    fin>>N;
    for(i=1; i<=N; i++)
        fin>>H[i], G[i]=H[i];
    sort(G+1,G+N+1);
    int poz, max = 0;

    for (i=1; i<=N; i++)
    {
        poz=i;
        for (j=1; j<=N && poz<=N; j++)
            if ( H[j]==G[poz] ) poz++;
        if (poz-i>max) max=poz-i;
    }

    fout<<N-max<<'\n';
    return 0;
}
