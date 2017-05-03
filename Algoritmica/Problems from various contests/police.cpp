#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
FILE* fin = fopen("police.in","r");
FILE* fout = fopen("police.out","w");

const int NMAX = 1505;
const int MMAX = 4005;

void Citire();
void Afisare();
void Rezolva();
void Do(int,bool);

vector<int> G[NMAX];
queue< vector<int> > sol;
int n,m,nrsol;
int mat[NMAX][NMAX];

int viz[NMAX][NMAX],ok;

vector<int> v;
int grx[NMAX];
int gry[NMAX];

int main()
{
    Citire();
    Rezolva();
    Afisare();
    return 0;
}

void Citire()
{
    fscanf(fin,"%d%d",&n,&m);
    int i,x,y;
    for(i=1; i<=m; i++)
    {
        fscanf(fin,"%d%d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
        mat[x][y] = mat[y][x] = -1;

        mu.push_back(make_pair(x,y));
    }
}

void Rezolva()
{

    int i;
    pair<int, int>::iterator it;
    for(it = mu.begin(); it = mu.end(); it++)
    {
        x = *(it->first);
        y = *(it->second);

        DFSx(x);
        DFSy(y);
    }

}

void Afisare()
{
    int i,j;
    vector<int> v;
    fprintf(fout,"%d\n",nrsol);
    for(i = 1; i <= nrsol; i++)
    {
        while(!sol.empty())
        {
            v = sol.front();
            sol.pop();
            for(j = 0; j<v.size(); j++)
                fprintf(fout,"%d ",v[j]);
            fprintf(fout,"\n");
        }
    }
}

void DFSx(int nod)
{
   for(i = 0; i < G[nod].size(); i++)
        {
            grx[++grx[0]] = G[nod][i];
            DFSx(G[nod][i]);
        }
}

void DFSy(int nod)
{
   for(i = 0; i < G[nod].size(); i++)
        {
            gry[++gry[0]] = G[nod][i];
            DFSy(G[nod][i]);
        }
}

void Do(int nod, bool is)
{
    if(mat[nod][v[0]]!=0)
    {
            v.push_back(v[0]);
            nrsol++;
            sol.push(v);
            v.pop_back();
    }
    else
    {

   int i;
   for(i = 0; i < G[nod].size(); i++)
        if(mat[nod][G[nod][i]] == -1)
        {
            v.push_back(G[nod][i]);

            fprintf(fout,"%d %d\n", nod, G[nod][i]);
            for(int j = 0; j<v.size(); j++)
                fprintf(fout,"%d ",v[j]);
            fprintf(fout,"\n");fprintf(fout,"\n");

            mat[nod][G[nod][i]] = 1;
            mat[G[nod][i]][nod] = 1;
            Do(G[nod][i],true);

            v.pop_back();
        }
}}
