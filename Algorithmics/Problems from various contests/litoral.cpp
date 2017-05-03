#include <cstdio>
#include <vector>
#include <queue>
#include <bitset>
using namespace std;
FILE* fin = fopen("litoral.in","r");
FILE* fout = fopen("litoral.out","w");

const int NMAX = 1005;
const int INF = 0x3f3f3f3f;

int V[NMAX];
int cz[NMAX];
int c[NMAX][NMAX];


vector<int> G[NMAX];
int nA, nB, ns;

void Citire();
void BellmanFord();


bitset<NMAX> inCoada;
queue<int> coada;
vector<int> cmin(NMAX, INF);
int pre[NMAX];

int main()
{
    Citire();
    BellmanFord();
    fprintf(fout,"%d\n", cmin[nA+nB+2*ns+1]);
    return 0;
}

void BellmanFord()
{
    coada.push(0);
    inCoada[0].flip();
    cmin[0] = 0;

    while (!coada.empty())
    {
        int x = coada.front();
        coada.pop();
        inCoada[x] = false;

        for(int i = 0; i < G[x].size(); i++)
            if(cmin[x] < INF && cmin[x] + c[x][G[x][i]] < cmin[G[x][i]])
            {
                cmin[G[x][i]] = cmin[x] + c[x][G[x][i]];
                if(!inCoada[G[x][i]])
                    {
                        coada.push(G[x][i]);
                        inCoada[G[x][i]] = true;
                        pre[G[x][i]] = x;
                    }
            }
    }
}


void Citire()
{
    int xf,yf,x,y,co,d;
    fscanf(fin,"%d%d",&x, &y);
    V[0] =  x*60+y;

    fscanf(fin,"%d%d",&xf, &yf);
    fscanf(fin,"%d%d",&nA, &nB);

    int i, ok = false;

    for(i = 1; i <= nA; i++)
    {
        fscanf(fin,"%d%d%d",&x, &y, &co);
        V[i] = x*60+y;
        cz[i] = co;
        //mereu cand se face o muchie x, i, costul dintre ele va fi cz[i];
        if( !ok && V[i] >= V[0])
            {
                G[0].push_back(i);
                c[0][i] = cz[i];
                ok = 1;
            }
        if( i != 1 )
            {
                G[i-1].push_back(i);
                c[i-1][i] = cz[i];
            }
    }

    ok = false;
    for(i = nA + 1; i <= nA + nB; i++)
    {
        fscanf(fin,"%d%d%d",&x, &y, &co);
        V[i] = x*60+y;
        cz[i] = co;
        if( i != nA + 1)
            {
                G[i-1].push_back(i);
                c[i-1][i] = cz[i];
            }
    }

    fscanf(fin,"%d",&ns);
    int a, b, j;

    for(j = nA + 1; j <= nA + nB && V[j] < xf*60+yf; j++);
    G[j-1].push_back(nA+nB+2*ns+1);
    c[j-1][nA+nB+2*ns+1] = 0;


    for(i = nA + nB + 1; i <= nA + nB + 2*ns; i+=2)
    {
        fscanf(fin,"%d%d%d%d%d%d", &d, &x, &y, &a, &b, &co);
        V[i] = x*60+y;
        V[i+1] = a*60+b;
        cz[i] = cz[i+1] = 0;
        if( d == 0 )
        {
            G[i].push_back(i+1);
            c[i][i+1] = co;

            for(j = 1; j <= nA && V[j] < V[i]; j++);
            G[j-1].push_back(i);
            c[j-1][i] = cz[i];


            for(j = nA + 1; j <= nA + nB +1 && V[j] < V[i+1]; j++);
            G[i+1].push_back(j);
            c[i+1][j] = cz[j];
            if(V[i+1] == V[j]) c[i+1][j]+=cz[i+1];
        }
        else
        {
            G[i+1].push_back(i);
            c[i+1][i] = co;

            for(j = 1; j <= nA && V[j] <= V[i]; j++);

            if(j < nA+1 && V[i]<V[j])
            {
                G[i].push_back(j);
                c[i][j] = cz[j];
            }

            for(j = nA + 1; j <= nA + nB +1 && V[j] <= V[i+1]; j++);
            if( j!=nA+1 && V[j-1] < V[i+1])
            {
                G[j-1].push_back(i+1);
                c[j-1][i+1] = cz[i+1];
            }
        }
    }
/* last;
            for(j= nA + nB + 1; j <= nA+nB+ns; j++)
                if(j%2 == 0)
                {
                    if(V[j] <= )
                }*/
    V[nA + nB + 2*ns +1 ] = xf*60+yf;


    for(j = 0; j <= nA + nB + 2*ns+1; j++)
    {
        fprintf(fout,"\n%d     ", j);
        for(i = 0; i < G[j].size(); i++)
                fprintf(fout,"%d (%d cu costul %d)   ", G[j][i],V[G[j][i]], c[j][G[j][i]] );
}
}


