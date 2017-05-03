#include <fstream>
#define Nmax 105
using namespace std;
ifstream fin("matrixdel.in");
ofstream fout("matrixdel.out");

int L[Nmax], C[Nmax],mat[Nmax][Nmax];
int N,M;
int main()
{
    fin>>N>>M;
    int i,j,x,p;
    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
            fin>>mat[i][j];
    fin>>p;
    for(i=1;i<=p;i++)
        fin>>x, L[x]=1;
    fin>>p;

    for(i=1;i<=p;i++)
        fin>>x, C[x]=1;

    for(i=1;i<=N;i++)
        if(!L[i])
        {
            for(j=1;j<=M;j++)
                if( !C[j])
                    fout<<mat[i][j]<<" ";
    fout<<'\n';
        }
    return 0;
}
