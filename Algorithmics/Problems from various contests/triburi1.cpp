#include <fstream>

using namespace std;
ifstream fin("triburi1.in");
ofstream fout("triburi1.out");

int sol[10],w[20],solsave[10],n,k,p,uz[30];
int contor;
void bkt(int q)
{
    if(q-1==k)
    {
        contor++;
        if(contor==p)
            for(int i=1; i<=k; i++)
                solsave[i]=sol[i];
    }
    else
    {
        for(int  i = 1; i <= k; i++)
        {
            sol[q] = i;
            bkt(q+1);
        }
    }
}

int main()
{
    int x;
    fin>>n>>k>>p;
    for(int i=1; i<=n; i++)
    {
        fin>>x;
        uz[x]++;
    }
    bkt(1);
    for(int i=1; i<=27; i++)
        if(uz[i])
        {
            for(int j=1; j<=k; j++)
                fout<<(char)(63+solsave[j]+i);
            fout<<'\n';
        }
    return 0;
}
