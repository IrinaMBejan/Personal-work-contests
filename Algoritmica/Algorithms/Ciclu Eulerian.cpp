#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

FILE* fin = fopen("ciclueuler.in","r");
FILE* fout = fopen("ciclueuler.out","w");

void BFS(int vf);
void Citire();
bool EsteEulerian();
void Rezolva();

const int NMAX = 100005;

int N,M;
vector<int> G[NMAX];
vector<int> sol[NMAX];
stack<pair<int, int > > stiv;
bool viz[NMAX];

int main()
{
    Citire();


    return 0;
}

void Citire()
{
    fscanf(fin,"%d %d",&N,&M);
    int x,y;
    while(M--)
    {
        fscanf(fin,"%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
}
