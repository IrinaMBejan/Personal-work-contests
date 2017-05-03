#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
FILE* fin = fopen("arthur.in","r");
FILE* fout = fopen("arthur.out","w");


const int NMAX = 201;
const int INF = 0x3f3f3f3f;

int N,M,k,p;
int xi, yi, xc, yc;

int dln[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dcn[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dlc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dcc[8] = {1, 2, 2, 1, -1,-2, -2, -1};
int cn[NMAX][NMAX];
int cc[NMAX][NMAX];

int cmin[NMAX];
int pre[NMAX];
bool viz[NMAX];
vector<int> G[NMAX];
struct obiectiv
{
    int x, y;
} h[NMAX];

int c[NMAX][NMAX];
char l[NMAX][NMAX];
queue<obiectiv> Q;
vector<obiectiv> solutie;
int pren[NMAX*1000], prec[NMAX*1000];
void Citire();
void Bordare(int mat[NMAX][NMAX]);
void LeeNormal(obiectiv a, obiectiv b);
void CreazaGraf();
void Rezolva();
void InitializareDijkstra();
void Dijkstra();
int LeeCalare(obiectiv a, obiectiv b, bool afisare);
int LeeNormal(obiectiv a, obiectiv b, bool afisare);
void Afisare();

int main()
{
    Citire();
    Rezolva();
    CreazaGraf();
    InitializareDijkstra();
    Dijkstra();
    Afisare();
    return 0;
}

void Bordare(int mat[NMAX][NMAX])
{
    int i;
    for(i = 0; i <= N+1; i++)
        mat[i][0]= mat[i][M+1] = -1;
    for(i = 0; i <= M+1; i++)
        mat[0][i] = mat[N+1][i] = -1;
}

void Citire()
{
    fscanf(fin,"%d%d%d%d",&N,&M,&k,&p);
    fscanf(fin,"%d%d",&h[0].x, &h[0].y);
    fscanf(fin,"%d%d",&h[p+1].x, &h[p+1].y);

    for ( int i = 1; i <= p ; i++)
        fscanf(fin,"%d%d",&h[i].x, &h[i].y);
}

void Rezolva()
{
    int i,j, d1, d2;
    for(i = 0; i <= p; i++)
        for(j = i+1; j <= p+1; j++)
        {
            d1 = LeeNormal(h[i], h[j], false);
            d2 = LeeCalare(h[i], h[j], false);
            if(d1 < d2 || d2 > k || i == 0)
                {
                    c[i][j] = c[j][i] = d1;
                    l[i][j] = l[j][i] = 'j';
                }
            else
                {
                    c[i][j] = c[j][i] = d2;
                    l[i][j] = l[j][i] = 'c';
                }
        }
}

void CreazaGraf()
{
    int i,j;
    for ( i = 0; i <= p ; i++)
        for(j = i+1; j <= p+1; j++)
        {
            G[i].push_back(j);
            G[j].push_back(i);
        }
}

void InitializareDijkstra()
{
    int i;
    for(i = 0; i <= p+2 ; i++)
    {
        cmin[i] = INF;
        pre[i] = 0;
    }

    cmin[0] = 0;
    pre[0] = 0;
    viz[0] = 1;

    for( i = 0; i < G[0].size(); i++)
    {
        cmin[G[0][i]] = c[0][G[0][i]];
        pre[G[0][i]] = 0;
    }
}

void Dijkstra()
{
    int minim, i, vfMinim;
    bool ok = 1;
    while(ok)
    {
        minim = INF;
        for(i = 0; i <= p+2; i++)
            if( !viz[i] && cmin[i] < minim)
            {
                minim = cmin[i];
                vfMinim = i;
            }

        if(minim != INF)
        {
            viz[vfMinim] = 1;
            for( i = 0; i < G[vfMinim].size(); i++)
                if( c[vfMinim][G[vfMinim][i]] + cmin[vfMinim] < cmin[G[vfMinim][i]])
                {
                    cmin[G[vfMinim][i]] = c[vfMinim][G[vfMinim][i]] + cmin[vfMinim];
                    pre[G[vfMinim][i]] = vfMinim;
                }
        }
        else ok = 0;
    }
}

void Afisare()
{
    int q;
    fprintf(fout,"%d\n", cmin[p+1]);
    int varfCurent = p+1;
    pre[0] = -1;
    while(pre[varfCurent] != -1)
    {
        if(l[pre[varfCurent]][varfCurent] == 'j')
            LeeNormal(h[pre[varfCurent]], h[varfCurent], true);
        else
            LeeCalare(h[pre[varfCurent]], h[varfCurent], true);
       varfCurent = pre[varfCurent];
    }

    fprintf(fout,"%d %d\n", h[0].x, h[0].y);
    for(int i = solutie.size() - 1; i>=0; i--)
        fprintf(fout,"%d %d\n", solutie[i].x, solutie[i].y);

    fprintf(fout,"\n");
}

int LeeNormal(obiectiv a, obiectiv b, bool afisare)
{
    memset(cn, 0, sizeof(cn));
    Bordare(cn);
    while(!Q.empty()) Q.pop();

    if(afisare)
        memset(prec,0,sizeof(prec));

    Q.push(a);
    obiectiv p,poz;
    int i;

    while(!Q.empty() || cn[b.x][b.y] == 0)
    {
        poz = Q.front();
        Q.pop();
        for(i = 0; i <8; i++)
        if(cn[poz.x+dln[i]][poz.y + dcn[i]] == 0)
        {
            p.x = poz.x + dln[i];
            p.y = poz.y + dcn[i];
            cn[p.x][p.y] = cn[poz.x][poz.y]+1;
            pren[p.x*1000+p.y] = poz.x*1000+poz.y;
            Q.push(p);
        }

    }
    if(afisare)
    {
        obiectiv curent;
        int x = b.x, y = b.y, z;
        while(x!= a.x || y!= a.y)
        {
            curent.x = x; curent.y = y;
            solutie.push_back(curent);

            z = x*1000+y;
            x = pren[z]/1000;
            y = pren[z]%1000;
        }
    }
    return cn[b.x][b.y];
}

int LeeCalare(obiectiv a, obiectiv b, bool afisare)
{
    memset(cc, 0, sizeof(cc));
    Bordare(cc);
    while(!Q.empty()) Q.pop();
    if(afisare)
        memset(prec,0,sizeof(prec));

    Q.push(a);
    obiectiv p,poz;
    int i;

    while(!Q.empty() || cc[b.x][b.y] == 0)
    {
        poz = Q.front();
        Q.pop();

        for(i = 0; i <8; i++)
            if(cc[poz.x+dlc[i]][poz.y + dcc[i]] == 0 && poz.x + dlc[i] <= N && poz.x + dlc[i] >0 && poz.y + dcc[i] <= M && poz.y + dcc[i] >0)
        {
            p.x = poz.x + dlc[i];
            p.y = poz.y + dcc[i];
            cc[p.x][p.y] = cc[poz.x][poz.y]+1;
            prec[p.x*1000+p.y] = poz.x*1000+poz.y;
            Q.push(p);
        }
    }
    if(afisare)
    {
        obiectiv curent;
        int x = b.x, y = b.y, z;
        while(x!= a.x || y!= a.y)
        {
            curent.x = x; curent.y = y;
            solutie.push_back(curent);

            z = x*1000+y;
            x = prec[z]/1000;
            y = prec[z]%1000;
        }
    }
    return cc[b.x][b.y];
}
