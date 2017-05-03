#include <cstdio>
#include<vector>
using namespace std;
FILE* fin = fopen("arce.in","r");
FILE* fout = fopen("arce.out","w");

const int NMAX = 5005;
int n,m;
vector<int> G[NMAX];
int main()
{
    Citire();
    Afisare();
    return 0;
}

void Citire()
{
    fscanf(fin,"%d%d",&n,&m);
    int i;
    for(i= 1; i<=m; i++)
        {
            fscanf(fin,"%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
            gr[x]++;
            gr[y]++;
        }
}
