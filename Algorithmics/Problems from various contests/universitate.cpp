#include <fstream>
#include <vector>
#include <cstring>
using namespace std;
ifstream fin("universitate.in");
ofstream fout("universitate.out");

const int NMAX= 105;
const int KMAX= 6;
const int INF = 0x3f3f3f3f;


int F[NMAX][NMAX];

int capacitate[NMAX][NMAX], fl[NMAX][NMAX], C[NMAX], viz[NMAX];
int TT[NMAX];
vector<int> G[NMAX];

int n,m,k,s,d;
int flux;

void Citire();
void CreeazaGraf();
void Afisare();
void FluxMaxim();
int BFS();

int main()
{
    Citire();
 //   FluxMaxim();
    return 0;
}

int convertToNr(char* s)
{
    int nr = 0;
    int len = strlen(s);
    for(int i = len - 1; i>=0;i--)
        nr = nr*10 + (s[i]-'0');
    return nr;
}
void Citire()
{
    char *p;
    char s[50];
    int x, i;
    fin>>n>>m>>k;
    fin.get();
    //sul e 0
    //calculatoarele is 1..n
    //porturile is n+1 ... n+m
    //deviceurile is n+m+1... n+m+k
    //dul e n+m+1+k
    for(i = 1; i <= n; i++)
    {
        G[1].push_back(i+1);
        capacitate[1][i+1] = 1;
        fin.getline(s,30);
        p = strtok(s," ");
        while(p!=NULL)
        {
            x = convertToNr(p);
            G[i+1].push_back(x + n + m+1);
            capacitate[i+1][x+n+m+1] = 1;
            p = strtok(NULL," ");
        }
    }

    for(i = 1; i <= m;i++)
    {
        G[i+n+1].push_back(n+m+k+2);
        capacitate[i+n+1][n+m+k+2] = 1;
        fin.getline(s,30);
        p = strtok(s," ");
        while(p!=NULL)
        {
            x = convertToNr(p);
            G[x+n+1+m].push_back(i+1+n);
            capacitate[x+n+m+1][i+1+n]=1;
            p = strtok(NULL," ");
        }
    }

    for(i = 1; i <= n+m+k+2; i++)
    {
        fout<<i<<'\n';
        for(int j= 0; j<G[i].size(); j++)
            fout<<G[i][j]<<" ";
        fout<<'\n';
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
        if (nod == n+m+k+2) continue;
        for (j = 0; j < G[nod].size(); j++)
            {
                vf = G[nod][j];
                if (capacitate[nod][vf] == fl[nod][vf] || viz[vf]) continue;
                viz[vf] = 1;
                C[ ++C[0] ] = vf;
                TT[vf] = nod;
            }
    }

    return viz[n+m+k+2];
}

void FluxMaxim()
{
    int i, j,fmin;
    while(BFS())
        for (i = 0; i < G[n+m+k+2].size(); i++)
        {
            j = G[n+m+k+2][i];
            if (fl[j][n+m+k+2] == capacitate[j][n+m+k+2] || !viz[j]) continue;
            TT[n+m+k+2] = j;

            fmin = INF;
            for (j = n+m+k+2; j != 1; j = TT[j])
                fmin = min(fmin, capacitate[ TT[j] ][j] - fl[ TT[j] ][j]);
            if (fmin == 0) continue;

            for (j = n+m+k+2; j != 1; j = TT[j])
            {
                fl[ TT[j] ][j] += fmin;
                fl[j][ TT[j] ] -= fmin;
            }

            flux += fmin;

        }
}


