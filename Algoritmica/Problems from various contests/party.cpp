#include <fstream>
#include<cstring>
#define Lgmax 11
#define Mmax 605
using namespace std;
ifstream fin("party.in");
ofstream fout("party.out");

int n, L, m;
char sir[Mmax][Lgmax];
int Nr[Mmax][Mmax];
bool mat[Mmax][ Mmax];

int main()
{
    fin>>n>>L>>m;
    int i;
    for(i=1;i<=m;i++)
            fin>>sir[i];
    int s=strlen(sir[1]);
    int j,i1,j1;
    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
        {
            mat[i][j]=1;
            for(i1=1, j1=0; j1< s-1; i1++,j1++)
               if(sir[i][i1]!=sir[j][j1])
                    {
                        mat[i][j]=0;
                        break;
                    }
        }

    int k;
    for(i=1;i<=m;i++)
        Nr[s][i]=1;

    for(i=1;i<=m;i++)
        for(j=0;j<s;j++)
            Nr[j][i]=0;

   for(i=s+1;i<=L;i++) //i litere
     for(j=1;j<=m;j++)//se termina in j
        {
                for(k=1; k<=m;k++)
                    if(mat[k][j])
                        Nr[i][j]+=Nr[i-1][k];
        }

    int Sol=0;
    for(i=1;i<=m;i++)
        Sol+=Nr[L][i];
    fout<<Sol<<'\n';

    return 0;
}
