#include <fstream>

using namespace std;
ifstream fin("submatrix.in");
ofstream fout("submatrix.out");

int A[101][101];
int Sum[101][101];
int main()
{
    int n,m,i,j,ariamax,s;
    char si[101];
    fin>>n>>m;
    fin.get();
    for(i=1;i<=n;i++)
    {
        fin.get(si,101);
        fin.get();
        for(j=0;j<m;j++)
            A[i][j+1]=si[j]-'0';
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            Sum[i][j]=Sum[i-1][j]+Sum[i][j-1]-Sum[i-1][j-1]+A[i][j];
    ariamax=0; s=0;
    int L1,C2,L2,C1,L1max,C2max,L2max,C1max,aria;
    for(L1=1;L1<=n;L1++)
        for(C1=1;C1<=m;C1++)
            for(L2=1;L2<=n; L2++)
                for(C2=1;C2<=m;C2++)
                {
                        aria=(L2-L1+1)*(C2-C1+1);
                         s=Sum[L2][C2]-Sum[L2][C1-1]+Sum[L1-1][C1-1]-Sum[L1-1][C2];
                        if(s==aria&&aria>ariamax)
                             {
                                  ariamax=aria; L1max=L1; C1max=C1; L2max=L2; C2max=C2;
                             }
                }
    fout<<ariamax<<'\n';
    fout<<L1max<<" "<<C1max<<" "<<L2max<<" "<<C2max<<'\n';
   /* for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            fout<<Sum[i][j]<<" ";
        fout<<'\n';
    }*/
    return 0;
}
