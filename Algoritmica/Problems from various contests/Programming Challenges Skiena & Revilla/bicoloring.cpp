#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>
using namespace std;

ofstream fout("pp.out");
const int NMAX = 205;
vector<int> G[NMAX];
int color[NMAX];
int N,M;
int DFS(int x, int pS)
{
    int i;
    int ok = 1;
    color[x] = pS;
    for(i=0;i<G[x].size(); i++)
        if(color[G[x][i]] == -1)
        {
            ok = ok && DFS(G[x][i], !pS);
        }
        else if(color[G[x][i]] == pS)
            return 0;
    return ok;
}

int main()
{
    int i,a,b;
    while(1)
    {
        cin>>N;
        if(N == 0) return 0;
        cin>>M;
        while(M--)
        {
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        memset(color,-1,sizeof(color));
        if(DFS(1,0))
            cout<<"BICOLORABLE.";
        else cout<<"NOT BICOLORABLE.";
        cout<<'\n';
        for(i=0;i<N;i++)
            G[i].clear();

    }
    return 0;
}
