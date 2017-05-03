#include <cstdio>
#include <fstream>
#include <vector>
#define NMAX 100005
using namespace std;
//FILE* fin=fopen("ctc.in","r");
//FILE* fout=fopen("ctc.out","w");
ifstream fin("ctc.in");
ofstream fout("ctc.out");

vector< int > G[NMAX];
vector< int > GT[NMAX];
vector< int > ap[NMAX];

int N, M;
bool viz[NMAX];
int post[NMAX];
int k;
int nr;

void CitireListeAdiacenta();
void DFS1(int x);
void DFS2(int x);
void Afisare();

int main()
{

    CitireListeAdiacenta();

    //PARCURGERE 1
    int i;
    for( i = 1; i <= N; ++i)
        if( !viz[i] )
                DFS1(i);

    //PARCURGERE 2
    for( i = N; i >= 1; --i)
        if( viz[post[i]] )
                {
                    nr++;
                    DFS2(post[i]);
                }
    Afisare();
    return 0;
}

void CitireListeAdiacenta()
{
    int i, x, y;
   // fscanf(fin,"%d %d",&N,&M);
    fin>>N>>M;
    for(i = 1; i <= M ; ++i)
    {
        fin>>x>>y;// fscanf(fin,"%d %d",&x,&y);
        G[x].push_back(y);
        GT[y].push_back(x);
    }
    fin.close();
}

void DFS1(int x)
{
    int i;
    viz[x] = 1;
    for( i = 0; i < G[x].size(); ++i)
         if( !viz[G[x][i]] )
               DFS1(G[x][i]);
    post[++k] = x;
}

void DFS2(int x)
{
    int i;
    viz[x] = 0;
    ap[nr].push_back(x);
    for( i = 0; i < GT[x].size(); ++i)
         if( viz[GT[x][i]] )
               DFS2(GT[x][i]);
}

void Afisare()
{
   // fprintf(fout,"%d\n",nr);
    fout<<nr<<'\n';
    int i,j;
    for(i = 1; i <= nr; ++i)
    {
        for( j = 0; j < ap[i].size(); ++j)
                fout<<ap[i][j]<<" ";//fprintf(fout,"%d ",j);
        fout<<'\n';//fprintf(fout,"\n");
    }
    fout.close();
}
