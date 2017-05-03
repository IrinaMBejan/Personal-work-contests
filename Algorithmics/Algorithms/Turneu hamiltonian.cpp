#include <cstdio>
#include <vector>
#define NMAX 1005
using namespace std;
FILE* fin = fopen("th.in","r");
FILE* fout = fopen("th.out","w");
bool ok[NMAX], viz[NMAX];
int N,M,lg;
int dp[NMAX];
vector<int> G[NMAX];

void DFS(int nod)
{
    int i;
    viz[nod] = 1;
    dp[++lg] = nod;
    for(i=0;i<G[nod].size();i++)
        if(viz[G[nod][i]] == 0)
            DFS(G[nod][i]);
}

int main()
{
    fscanf(fin,"%d %d",&N,&M);
    int i,a,b;
    for(i=1;i<=M;i++)
    {
        fscanf(fin,"%d %d",&a, &b);
        if(b == 3) ok[a]=1;
        else G[a].push_back(b);

    }
    DFS(1);

    int k;
    for(k = 1; ok[dp[k]] && k<=lg; k++);

    for(i = 1; i<k; i++)
        fprintf(fout,"%d ", dp[i]);
    fprintf(fout,"%d ",3);
    for(i = k; i<=lg; i++)
        fprintf(fout,"%d ", dp[i]);


    return 0;
}
