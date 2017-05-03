#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

FILE* fin = fopen("caini.in","r");
FILE* fout = fopen("caini.out","w");

const int NMAX = 105;
const int INF = 0x3f3f3f3f;

vector<int> G[NMAX];
vector<int> config;
int N,M;
int dusman[NMAX];
struct conf
{
    bool T[NMAX], mal;
};
int maxim = -1, nrCaini;
int minloc, minmut;
conf S;

void Citire();
int Configuratie(conf S);
void Generare(int k);
void Afisare();
int NumarMutari(int maxloc);
void Numar(int k, conf *S);

int cmin[2<<12];
queue<int> Q;


int main()
{
    Citire();
    Generare(1);
    int t = NumarMutari(N - maxim);
    if(t != -1)
    {
        minloc = N - maxim + 1;
        minmut = t;
    }
    else
    {
        minloc = N - maxim + 2;
        minmut = NumarMutari( N - maxim + 1);
    }
    Afisare();
    return 0;
}

int NumarMutari(int maxloc)
{
    int i,j;

    memset(cmin,-1, sizeof(cmin));
    cmin[0] = 0;
    while(!Q.empty()) Q.pop();

    conf S,S1;
    int k, k1;
    int start;
    int nrc;
    Q.push(0);

    while(!Q.empty())
    {
        k = Q.front();
        Q.pop();
        Numar(k,&S);
        start = !S.mal;
        for( i = start; i < config.size(); i+=2)
        {
            int k1 = config[i];
            Numar(k1, &S1);
            if(cmin[k1] == -1)
            {
                nrc = 0;
                for(j = 1; j <= N; j++)
                    if(S1.T[j])
                    {
                        if(S.T[j])
                        {
                            nrc = INF; break;
                        }
                    }
                    else
                    {
                        if(!S.T[j]) nrc++;
                    }
                if(nrc <= maxloc)
                {
                    cmin[k1] = cmin[k]+1;
                    if(k1 == 1) return cmin[k1];
                    Q.push(k1);
                }
            }
        }
    }

}

void Afisare()
{
    fprintf(fout,"%d %d\n",minloc, minmut);
}

int Configuratie(conf S)
{
    int rez = 0;
    int i;
    for( i = N; i > 0; i--)
        rez = rez*2 + S.T[i];
    return rez*2 + S.mal;
}

void Numar(int k, conf *S)
{
    int i;
    S->mal = k%2;
    k/=2;
    for( i = 1; i <= N; i++)
    {
        S->T[i] = k%2;
        k/=2;
    }
}
void Generare(int k)
{
    if( k > N)
    {
        if(nrCaini > maxim)
            maxim = nrCaini;
        S.mal = 0;
        config.push_back(Configuratie(S));
        S.mal = 1;
        config.push_back(Configuratie(S));
    }
    else
    {
        int i;
        S.T[k] = 0;
        Generare(k+1);
        if(!dusman[k])
        {
            for( i = 0; i < G[k].size(); i++)
                dusman[G[k][i]]++;
            nrCaini++;

            S.T[k] = 1;
            Generare(k+1);

            for( i = 0; i < G[k].size(); i++)
                dusman[G[k][i]]--;
            nrCaini--;
        }
    }
}
void Citire()
{
    fscanf(fin,"%d",&N);

    fscanf(fin,"%d",&M);

    int a,b;
    for(;M;M--)
    {
        fscanf(fin,"%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
    }
}


