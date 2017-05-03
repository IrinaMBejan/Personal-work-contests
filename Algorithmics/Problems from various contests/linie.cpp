#include <fstream>

using namespace std;
ifstream fin("linie.in");
ofstream fout("linie.out");

int sol[20],mat[20][20];
int n,S,D,Smax,Dmax,solmax[20];

int abs(int x, int y)
{
    if(x>y) return x-y;
    else return y-x;
}
void bkt(int k)
{
    if(k-1==n)
    {
        S=0,D=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sol[i];j++)
                S+=mat[i][j];
            for(int j=sol[i]+1;j<=n;j++)
                D+=mat[i][j];
        }
            if((Smax!=0&&Dmax!=0&&abs(S,D)<abs(Smax,Dmax))||(Smax==0&&Dmax==0))
            {
                Smax=S;
                Dmax=D;
                for(int i=1;i<=n;i++)
                    solmax[i]=sol[i];
            }
    }
    else
    {
        sol[k]=sol[k-1];
        bkt(k+1);

        if(sol[k-1]-1!=0)
        {
            sol[k]=sol[k-1]-1;
            bkt(k+1);
        }
        if(sol[k-1]+1!=n)
        {
            sol[k]=sol[k-1]+1;
            bkt(k+1);
        }
    }
}

int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            fin>>mat[i][j];

    for(int i=1;i<=n-1;i++)
    {
        sol[1]=i;
        bkt(2);
    }
    fout<<Smax<<'\n'<<Dmax<<'\n';
    for(int i=1;i<=n;i++)
        fout<<solmax[i]<<" ";
    fout<<'\n';
    return 0;
}
