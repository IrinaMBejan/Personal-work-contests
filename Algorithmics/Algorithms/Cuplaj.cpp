#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define NMAX 1004
#define INF 0x3f3f3f3f
using namespace std;

FILE* fin = fopen("cuplaj.in","r");
FILE* fout = fopen("cuplaj.out","w");

int cap[NMAX][NMAX],fl[NMAX][NMAX],C[NMAX],viz[NMAX];
int TT[NMAX];

vector<int> G[NMAX];

int N,M;
int flux = 0;
int st, fi;

int BFS();
void FluxMaxim();
void Citire();
void Afisare();
void Test();

int main()
{
    Citire();
    FluxMaxim();
    Afisare();
    Test();
}


void Citire()
{
    int i;
    int x,y,E,n,m;

    fscanf(fin, "%d %d %d",&n,&m,&E);

    st = n+m+2;
    fi = n+m+1;

    N = n+m+1;

    for (i = 1; i <= E; i++)
    {
        fscanf(fin,"%d %d", &x, &y);
        y+=n;

        cap[x][y] = 1;
        cap[y][x] = -1;
        G[x].push_back(y);
        G[y].push_back(x);

        if(!viz[x])
        {
            cap[st][x] = 1;
            G[st].push_back(x);
            viz[x] = 1;
        }

        if(!viz[y])
        {
            cap[y][fi] = 1;
            G[y].push_back(fi);
            viz[y] = 1;
        }
    }
}

void FluxMaxim()
{
    int i,j,fmin;
    while(BFS()) //2.1 cauta lant de ameliorare
        for( i = 0; i < G[N].size(); i++) //2.2 amelioram fluxul
        {
            j = G[N][i];
            if(fl[j][N] == cap[j][N] || !viz[j]) continue;

            TT[N] = j;

            fmin = INF;
            for (j = N; j != 1; j = TT[j])
                fmin = min(fmin, cap[ TT[j] ][j] - fl[ TT[j] ][j]);

            //nu avem ce ameliora
            if (fmin == 0) continue;

            //amelioram
            for (j = N; j != 1; j = TT[j])
            {
                fl[ TT[j] ][j] += fmin;
                fl[j][ TT[j] ] -= fmin;
            }

            flux += fmin;
        }
}

int BFS() //MARCAJ FF
{
    int nod, i, j, vf;

    C[0] = 1;
    C[1] = st;

    memset(viz, 0, sizeof(viz));

    viz[0] = 1;

    for( i = 1; i<= C[0]; i++)
    {
        nod = C[i];

        if (nod == N) continue;
        for (j = 0; j < G[nod].size(); j++)
        {
                vf = G[nod][j];
                //conditii: f(x,y) < c(x,y) cu x marcat si y nemarcat
                if (fl[nod][vf] == cap[nod][vf] || viz[vf]) continue;

                //marcam y cu +nod
                viz[vf] = 1;
                C[ ++C[0] ] = vf;
                TT[vf] = nod;
            }
    }
    return viz[N]; //daca e marcat f => am gasit lant de ameliorare
}


void Afisare()
{
    fprintf(fout,"%d\n",flux);
    for(int i = 1; i < N+1; i++)
    {
        for(int j = 0; j <G[i].size(); j++)
            if(fl[i][G[i][j]] > 0)
            {
                fprintf(fout,"%d %d\n", i, G[i][j]-N);
            }
    }

}


void Test()
{
    fprintf(fout,"\n\n\n");
    for(int i = 0; i < N+M+1; i++)
    {
        fprintf(fout,"%d\n", i);
        for(int j = 0; j <G[i].size(); j++)
        {
            fprintf(fout,"%d ",G[i][j]);
        }
        fprintf(fout,"\n\n");
    }

}
