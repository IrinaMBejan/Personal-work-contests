#include <cstdio>
#include <vector>
#define KMAX 15
#define NMAX 2001
using namespace std;
FILE* fin = fopen("ubuntzei.in","r");
FILE* fout = fopen("ubuntzei.out","w");

int N,M,K;
int C[KMAX];
int d[NMAX][1<<KMAX];
vector<int> G[NMAX];

int main()
{
    fscanf(fin,"%d %d %d",&N,&M,&K);
    int i;
    for(i=1;i<=K;i++)
        fscanf(fin,"%d",&C[i]);
    printf("%d",1<<0);
    int a,b,dist;
    while(M--)
    {
        fscanf(fin,"%d %d %d",&a, &b, &dist);
        d[a][1<<b] = dist;
        d[b][1<<a] = dist;
    }

    return 0;
}

