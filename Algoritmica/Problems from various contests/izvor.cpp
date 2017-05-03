#include <fstream>

using namespace std;
ifstream fin("izvor.in");
ofstream fout("izvor.out");

int sol[10],mat[25][25],trecut[25];
long long int nr;
int N,P,M;

void bkt(int k)
{
    if(k-1==M)
        if(mat[sol[M]][sol[1]]!=-1)
    {
        bool ok=0;
        for(int i=1;i<=M;i++)
            if(mat[sol[i]][sol[i+1]]==1)
            {
                ok=1;
                break;
            }
        if(ok) nr++;
    }
    else;
    else
    {
        for(int i=1;i<=N;i++)
            if(mat[sol[k-1]][i]!=-1&&trecut[i]==0)
            {
                    trecut[i]=1;
                    sol[k]=i;
                    bkt(k+1);
                    trecut[i]=0;

            }
    }

}

int main()
{
    fin>>N>>P>>M;
    int x,y,t;
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            mat[i][j]=-1;
    for(int i=1;i<=P;i++)
    {
        fin>>x>>y>>t;
        mat[x][y]=t;
        mat[y][x]=t;
    }
    for(int i=1;i<=N;i++)
    {
        sol[1]=i;
        trecut[i]=1;
        bkt(2);
        trecut[i]=0;
    }
    fout<<nr<<'\n';
    return 0;
}
