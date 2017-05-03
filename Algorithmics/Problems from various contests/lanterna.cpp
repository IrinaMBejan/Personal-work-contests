#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
FILE* fin = fopen("lanterna.in","r");
FILE* fout = fopen("lanterna.out","w");

const int NMAX = 51;
const int KMAX = 1001;
const int DMax = 50000;
const int INF = 30000000;

int N,K,tip[NMAX], M;

int c[NMAX][NMAX];
int t[NMAX][NMAX];
int kMin, timpMin;
int tMin[NMAX][KMAX];
bool inC[NMAX][KMAX];

struct conf
{
    int i,  k;
};
queue<conf> Q;

void Citire();
void Afisare();
int TimpMinim(int kmax);

int main()
{
    Citire();
    int li = 1, ls = K - 1, mij;
    timpMin = TimpMinim(K);
    kMin = K;
    while(li <= ls)
    {
        mij = (li + ls)/2;
        if( TimpMinim(mij) == timpMin )
        {
            kMin = mij;
            ls = mij-1;
        }
        else
        {
            li = mij+1;
        }
    }
    Afisare();
    return 0;
}
// timpul in care se ajunge de la 1 la N cu o lanterna de timpul kmax
int TimpMinim(int kmax)
{
    int i,j, k, q, p;
    for(i = 1; i <= N; i++)
        for(j = 0; j <= kmax; j++)
            {
                tMin[i][j] = INF;
                inC[i][j] = 0;
            }
    tMin[1][0] = 0; inC[1][0] = 1;
    conf temp;
    temp.i = 1;
    temp.k = 0;

    int timp = INF;
    Q.push(temp);
    while(!Q.empty())
    {
        temp = Q.front();
        i = temp.i;
        k = temp.k;
        Q.pop();
        if(tMin[i][k] < timp)
            for( j = 1; j <= N; j++)
                if( t[i][j] < INF && k + c[i][j] <= kmax)
        {
            p = tMin[i][k] + t[i][j];
            q = k + c[i][j];
            if(tip[j]) q = 0;
            if(p < tMin[j][q])
            {
                tMin[j][q] = p;
                if( j == N && tMin[j][q] < timp)
                    timp = tMin[j][q];
                if( ! inC[j][q] && tMin[j][q] < timp)
                {
                    inC[j][q] = 1;
                    temp.i = j;
                    temp.k = q;
                    Q.push(temp);
                }
            }
            inC[i][k] = 0;
        }
    }
    return timp;
}
void Afisare()
{
    fprintf(fout,"%d %d\n", timpMin, kMin);
}

void Citire()
{
    fscanf(fin, "%d%d", &N,&K);
    int i;
    for( i = 1; i <= N; i++)
        fscanf(fin,"%d", &tip[i]);
    fscanf(fin,"%d",&M);
    int j;
    for( i = 1; i <= N; i++)
        for( j = 1; j <= N; j++)
    {
        t[i][j] = INF;
        c[i][j] = KMAX + 1;
    }
    int a, b, w, timp;
    for( i = 1; i <= M; i++)
        {
            fscanf(fin,"%d%d%d%d",&a, &b, &timp, &w);
            c[a][b] = w; c[b][a] = w;
            t[a][b] = timp; t[b][a] = timp;
        }
}


