#include <fstream>
#define NMAX 505
using namespace std;
ifstream fin("graf.in");
ofstream fout("graf.out");

bool mat[NMAX][NMAX];
int N, M;
int ST[NMAX];
bool viz[NMAX];


void CitireMatAdiacenta();
void DFSMatAdiacenta(int x);
void DFSRecMatAdiacenta(int x);

int main()
{

    CitireMatAdiacenta();

    int i;
    for(i=1;i<=N;i++)
        if( !viz[i])
            {
                DFSRecMatAdiacenta(i);
            }

    return 0;
}

void CitireMatAdiacenta()
{
    int i, j, x, y;
    fin>>N>>M;

    for(i = 1; i <= M ; i++)
    {
        fin>>x>>y;
        mat[x][y] = mat[y][x] = true;
    }
}

void DFSMatAdiacenta(int x)
{
    int k=0;
    int i;

    ST[++k] = x; viz[x] = 1; fout<<x<<" ";

    while( k >= 0 )
    {
        x = ST[k];

        for( i = 1; i <= N; i++)
            if( !viz[i] && mat[x][i] )
            {
                ST[ ++k ] = i;
                fout<<i<<" ";
                viz[i] = 1;
                break;
            }

        if(ST[k] == x) k--;
    }

}

void DFSRecMatAdiacenta(int x)
{
    int i;

    viz[x] = 1;
    fout<<x<<" ";

    for( i = 1; i <= N; i++)
         if( !viz[i] && mat[x][i] )
            DFSRecMatAdiacenta(i);
}
