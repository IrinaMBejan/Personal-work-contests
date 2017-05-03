#include <cstdio>
#include <algorithm>
#include <queue>
#define NMAX 755
using namespace std;

FILE* fin = fopen("volum.in","r");
FILE* fout =fopen("volum.out","w");

int A[NMAX][NMAX];
bool viz[NMAX][NMAX];
bool inQ[NMAX][NMAX];
int N,M;
long long int sol;
int dirx[4] = {-1,1,0,0};
int diry[4] = {0,0,-1,1};

int main()
{
    fscanf(fin,"%d %d",&N,&M);
    int i,j;
    for(i=1;i<=N;++i)
        for(j=1;j<=M;++j)
            fscanf(fin,"%d",&A[i][j]);

    for(i = 0; i<=M+1; ++i)
        viz[0][i] = viz[N+1][i] = 1;

    for(i = 0; i<=N+1; ++i)
        viz[i][0] = viz[i][M+1] = 1;

    for(i = 1; i <= N; ++i)
    {
        Q.push(make_pair(-A[i][1],make_pair(i,1)));
        Q.push(make_pair(-A[i][M],make_pair(i,M)));
        inQ[i][1] = inQ[i][M] = true;
    }

    for(i = 2; i < M; ++i)
    {
        Q.push(make_pair(-A[1][i],make_pair(1,i)));
        Q.push(make_pair(-A[N][i],make_pair(N,i)));
        inQ[1][i] = inQ[N][i] = true;
    }

    while(Q.size())
    {
        Nr = 1;
        Q2[Nr] = (Q.top()).second;
        H = -(Q.top()).first;
        viz[Q2[1].first][Q2[1].second] = true;
        Q.pop();

        for(i=1;i<=Nr;++i)
        {
            x = Q2[i].first;
            y = Q2[i].second;
            for(j = 0; j<4; ++j)
            {
                xn = x + dirx[j];
                yn = y + diry[j];
                if(viz[xn][yn]) continue;
                if(A[xn][yn]<=H)
                {
                    sol += (long long int) H - A[xn][yn];
                    Q2[++Nr] = make_pair(xn,yn);
                    viz[xn][yn] = true;
                }
                else
                {
                    if(inQ[xn][yn]) continue;
                    Q.push(make_pair(-A[xn][yn],make_pair(xn,yn)));
                    inQ[xn][yn] = true
                }
            }
        }
    }

    fprintf(fout,"%d\n",sol);
    return 0;
}
