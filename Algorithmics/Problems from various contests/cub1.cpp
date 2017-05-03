#include <fstream>
#include <vector>
#include <utility>
#define Nmax 120
using namespace std;
ifstream fin("cub1.in");
ofstream fout("cub1.out");

int C[Nmax][Nmax][3];
vector < pair<int, int> > impur[Nmax];
int N,K;
bool mat[Nmax][Nmax][3];

int main()
{
    int i,j,x,y,z;
    fin>>N>>K;
    for(i=1;i<=K;i++)
    {
        fin>>x>>y>>z;
        impur[z].push_back(make_pair(x,y));
    }

    int lc=1, lp=0;
    for(i=0;i<impur[1].size(); i++)
                    mat[impur[1][i].first][impur[1][i].second][lp]=1;

    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
            if(!mat[i][j][lp])
                C[i][j][lp] = 1;

    int p;
    int minim,maxi=0,nrmax=0;
    for(p=2; p<=N; p++)
    {
        for(i=1;i<=N;i++)
            for(j=1;j<=N;j++)
                mat[i][j][lc]=0;

        for(i=0;i<impur[p].size();i++)
            mat[impur[p][i].first][impur[p][i].second][lc] = 1;

        for(j=1;j<=N;j++)
            if(!mat[1][j][lc])
                C[1][j][lc]=1;

        for(i=1; i<=N; i++)
            if(!mat[i][1][lc])
                C[i][1][lc]=1;

        for(i=2; i<=N; i++)
            for(j=2; j<=N; j++)
                if(!mat[i][j][lc])
                {
                    minim = min(C[i-1][j-1][lc], C[i][j-1][lc]);
                    minim = min(minim, C[i-1][j][lc]);
                    minim = min(minim, C[i][j-1][lp]);
                    minim = min(minim, C[i-1][j-1][lp]);
                    minim = min(minim, C[i-1][j][lp]);
                    minim = min(minim, C[i][j][lp]);
                    C[i][j][lc] = 1 + minim;
                    if (C[i][j][lc]>maxi)
                    {
                        maxi=C[i][j][lc];
                        nrmax=1;
                    }
                    else if(C[i][j][lc]==maxi)
                        nrmax++;
                }

        lc=1-lc;
        lp=1-lp;
    }
    fout<<maxi<<'\n'<<nrmax-1<<'\n';
    return 0;
}
