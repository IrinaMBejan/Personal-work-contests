#include <fstream>
#define NMAX 205
#define INF 1000000

using namespace std;
ifstream fin("patrat1.in");
ofstream fout("patrat1.out");

int dl[8]= {-1, 1,-1,1,0, 0,1,-1};
int dc[8] = { 1,-1,-1,1,1,-1,0, 0};


int a[NMAX][NMAX];
int n, m, i, j, k, mmax, nrstele, nrpat, ok, d, iv, jv, lat;

int main()
{
    int n,m,i,j;
    fin>>n>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            fin>>a[i][j];

    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
        {
            ok = 1;
            for (d=0; d<=7; d++)
            {
                iv = i + dl[d];
                jv = j + dc[d];
                if (a[iv][jv] >= a[i][j])
                    ok = 0;
            }
            if (ok)
            {
                a[i][j] = INF;
                nrstele++;
            }
        }
    for (i=1; i<n; i++)
        for (j=i+1; j<=n; j++)
        {
            lat = j-i;
            for (k=1; k+lat<=m; k++)
                if (a[i][k]==INF && a[i][k+lat]==INF && a[j][k]==INF && a[j][k+lat]==INF)
                {
                    nrpat++;
                    if (lat>mmax)
                        mmax = lat;
                }
        }

    fout<<nrstele<<"\n"<<nrpat<<"\n"<<mmax+1;

    return 0;
}
