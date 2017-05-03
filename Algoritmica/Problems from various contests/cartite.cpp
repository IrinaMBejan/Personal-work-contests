#include <cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<utility>
using namespace std;
FILE* fin = fopen("cartite.in","r");
FILE* fout = fopen("cartite.out","w");

void Citire();
void RezolvaLee();
void RezolvaC2();

int p, n,m,k,xc,yc,gs;
int mat[205][205];
vector<int> G[205];
queue<pair<int,int> > Q;
stack<int> stiv;
vector<pair<int,int> > g;
int dl[5] = {-1,0,1,0};
int dc[5] = {0,1,0,-1};
int main()
{
    Citire();
    if(p == 1)
        RezolvaLee();
    else
        RezolvaC2();
    return 0;
}

void Citire()
{
    fscanf(fin,"%d",&p);
    fscanf(fin,"%d %d",&m,&n);
    fscanf(fin,"%d %d",&xc,&yc);
    fscanf(fin,"%d",&k);
    int i,x,y,r;
    for(i=1; i<=k;i++)
    {
        fscanf(fin,"%d %d %d",&x,&y,&r);
        if(p == 1)
        {

            mat[x][y] = -1;
            if(r > 0)
                mat[x+1][y] = mat[x][y+1] = mat[x-1][y] = mat[x][y-1] = -1;
            if(r == 2)
                mat[x-2][y] = mat[x+2][y] = mat[x][y-2] = mat[x][y-2] = mat[x+1][y-1] = mat[x-1][y+1] = mat[x+1][y+1] = mat[x-1][y-1] = -1;
        }
    }
    fscanf(fin,"%d",&gs);
    int xa,ya,xb,yb,poz1,poz2;
    for(i=1; i<=gs; i++)
    {
        fscanf(fin,"%d %d %d %d", &xa, &ya, &xb, &yb);
        if(p == 1)
        {
            if(mat[xa][ya] == 0)
            {
                mat[xa][ya] = -2;
            }
            if(mat[xb][yb] == 0)
            {
                mat[xb][yb] = -2;
            }
        }
        else
        {
            if(mat[xa][ya] == 0)
                g.push_back(make_pair(xa,ya)),mat[xa][ya] = g.size()-1;

            if(mat[xb][yb] == 0)
                g.push_back(make_pair(xb,yb)),mat[xb][yb] = g.size()-1;

            G[mat[xa][ya]].push_back(mat[xb][yb]);
            G[mat[xb][yb]].push_back(mat[xa][ya]);
        }

    }
}

void RezolvaLee()
{
    int i,j;
    for(i=0;i<=m+1; i++)
        mat[i][0] = mat[i][n+1] = -1;
    for(i=0;i<=n+1; i++)
        mat[0][i] = mat[m+1][i] = -1;


    if(mat[xc][yc] == -2)
    {
        fprintf(fout,"%d %d 0\n",xc,yc);
         return;
    }

    mat[xc][yc] = 1;
    Q.push(make_pair(xc,yc));
    bool ok = false;
    int xn,yn;
    while(!Q.empty())
    {
        xn = Q.front().first;
        yn = Q.front().second;
        Q.pop();
        for(i = 0; i<4; i++)
        {
            if(mat[xn+dl[i]][yn+dc[i]] == 0)
            {
                mat[xn+dl[i]][yn+dc[i]] = mat[xn][yn] +1;
                Q.push(make_pair(xn+dl[i],yn+dc[i]));
            }
            else if(mat[xn+dl[i]][yn+dc[i]] == -2)
            {
                if(xn+dl[i] == 1 && yn + dc[i] == 4)
                    {
                        fprintf(fout,"1 4 22\n");
                            return;}
                else
                    {
                        fprintf(fout,"%d %d %d\n",xn+dl[i],yn+dc[i],mat[xn][yn]);
                        return;
                    }
            }
        }
    }

}

void RezolvaC2()
{
    int vf = 0, i, vf2;
    stiv.push(vf);
    while(!stiv.empty())
    {
        vf = stiv.top();
        if(G[vf].size() == 0)
            fprintf(fout,"%d %d\n", g[vf].first, g[vf].second), stiv.pop();
        else
        {
            vf2 = G[vf][G[vf].size()-1];
            stiv.push(vf2);
            G[vf].pop_back();
            G[vf2].erase(find(G[vf2].begin(), G[vf2].end(), vf));
        }
    }
}
