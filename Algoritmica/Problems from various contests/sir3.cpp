#include <fstream>

using namespace std;
ifstream fin("sir3.in");
ofstream fout("sir3.out");

int sol[30];
int vr[200000][25];
int S,n,t;
void bkt(int k)
{
    if(k-1==n)
        if(S==n*n)
        {
            if(t<20)
            {
                for(int i=1; i<=n; i++)
                    fout<<sol[i]<<" ";
                fout<<'\n';
                t++;
            }
            else
            {
                t++;
                for(int i=1; i<=n; i++)
                    vr[t-20][i]=sol[i];
            }
        }
        else;
    else
    {
        for(int i=sol[k-1]; S+i<=n*n; i++)
            if(S+i>=k*k)
            {
                S+=i;
                sol[k]=i;
                bkt(k+1);
                S-=i;
            }
    }
}

int main()
{
    fin>>n;
    sol[0]=1;
    bkt(1);
    for(int i=t-21; i<t-1; i++)
    {
        for(int j=1; j<=n; j++)
            fout<<vr[i-18][j]<<" ";
        fout<<'\n';
    }
    return 0;
}
