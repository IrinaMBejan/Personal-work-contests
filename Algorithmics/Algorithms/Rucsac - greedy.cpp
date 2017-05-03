#include <fstream>
#define Nmax 1005
#define Gmax 1005
using namespace std;
ifstream fin("rucsac.in");
ofstream fout("rucsac.out");
int N, val[Nmax],g[Nmax],G;
int Smax[Gmax];
int last[Gmax];
bool fol[Nmax][Gmax];
int main()
{
    int i;
    fin>>N;
    for(i=1;i<=N;i++)
        fin>>g[i];
    for(i=1;i<=N; i++)
        fin>>val[i];
    fin>>G;
    int j,gmax=0,k, nr=0;
    for(j=1;j<=G;j++)
        Smax[j]=-1;
    for(j=1; j<=N; j++)
        for(i=gmax; i>=0; i--)
            if(Smax[i] !=-1 &&  i+g[j]<=G)
            {
                if(Smax[i+g[j]]==val[j]+Smax[i] && i+g[j] == G)
                    nr++;
                if(Smax[i+g[j]]<val[j]+Smax[i] && !fol[j][i])
                {
                            if(i+g[j]>gmax)
                                gmax=i+g[j];
                            Smax[i+g[j]]=val[j]+Smax[i];
                            //
                            if(i+g[j]==G)
                                nr=1;
                            for(k=1;k<=N;k++)
                                fol[k][i+g[j]]=fol[k][i];
                            fol[j][i+g[j]]=1;
                }

            }
    fout<<Smax[G]<<'\n';
    for(i=1;i<=N;i++)
        if(fol[i][G])
            fout<<i<<" ";
    fout<<'\n'<<nr<<'\n';
    return 0;
}
