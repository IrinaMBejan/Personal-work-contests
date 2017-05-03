#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define NMAX 1004

using namespace std;

FILE* fin = fopen("maxflow.in","r");
FILE* fout = fopen("maxflow.out","w");

int capacitate[NMAX][NMAX], fl[NMAX][NMAX], C[NMAX], viz[NMAX];
int TT[NMAX];
vector<int> G[NMAX];
int N,M;
int flux = 0;
const int INF = 0x3f3f3f3f;

int BFS();
void FluxMinim();
void Citire();
void Afisare();

int main()
{
    Citire();
    FluxMinim();
    Afisare();
    return 0;
}

void Citire()
{
    int i;
    int x,y,z;

    fscanf(fin, "%d%d",&N,&M);

    for( i = 1; i <= M; i++)
    {

        fscanf(fin, "%d %d %d",&x,&y,&z);
        capacitate[x][y] += z;
        G[x].push_back(y);
        G[y].push_back(x);
    }

}

int BFS()
{
    int nod, i,j,vf;
    C[0] = 1;
    C[1] = 1;
    memset(viz, 0, sizeof(viz));
    viz[1] = 1;

    for (i = 1; i <= C[0]; i++)
    {
        nod = C[i];
        if (nod == N) continue;
        for (j = 0; j < G[nod].size(); j++)
            {
                vf = G[nod][j];
                if (capacitate[nod][vf] == fl[nod][vf] || viz[vf]) continue;
                viz[vf] = 1;
                C[ ++C[0] ] = vf;
                TT[vf] = nod;
            }
    }

    return viz[N];
}

void FluxMinim()
{
    int i, j,fmin;
    while(BFS())
        for (i = 0; i < G[N].size(); i++)
        {
            j = G[N][i];
            if (fl[j][N] == capacitate[j][N] || !viz[j]) continue;
            TT[N] = j;

            fmin = INF;
            for (j = N; j != 1; j = TT[j])
                fmin = min(fmin, capacitate[ TT[j] ][j] - fl[ TT[j] ][j]);
            if (fmin == 0) continue;

            for (j = N; j != 1; j = TT[j])
            {
                fl[ TT[j] ][j] += fmin;
                fl[j][ TT[j] ] -= fmin;
            }

            flux += fmin;
        }
}


void Afisare()
{
    fprintf(fout, "%d\n", flux);
}
