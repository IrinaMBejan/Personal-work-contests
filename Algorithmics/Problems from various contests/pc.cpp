#include <fstream>
#define Nmax 45
using namespace std;
ifstream fin("pc.in");
ofstream fout("pc.out");

long long int mat[Nmax][Nmax];
int G,V;
int main()
{
    fin>>G>>V;
    int i,j;
    for(i=0;i<=G;i++)
        mat[i][0]=i;
    for(i=1;i<=G;i++)
        for(j=1;j<=V;j++)
            mat[i][j]=1+mat[i-1][j-1]+mat[i-1][j];
    fout<<mat[G][V]<<'\n';
    return 0;
}
