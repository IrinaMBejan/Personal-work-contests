#include <fstream>

using namespace std;
ifstream fin("banda1.in");
ofstream fout("banda1.out");
int n,gmax, g1,g2,nr,nrmin;
int g[25];
int sum[100];

void bkt(int k, int nr)
{
    int aux;
    if(k==n+1)
        if(nr<nrmin)
            nrmin=nr;
        else;
    else
    {
         for (int j=1; j<=2; j++)
        {
            if (sum[j]+g[k]<=gmax)
            {
                sum[j]=sum[j]+g[k];
                bkt(k+1,nr);
                sum[j]=sum[j]-g[k];
            }
            else
            {
                aux=sum[j];
                sum[j]=g[k];
                nr++;
                if (nr<nrmin) bkt(k+1,nr);
                sum[j]=aux;
                nr--;
            }
       }
    }
}

int main()
{
    fin>>n>>gmax;
    for(int i=1;i<=n;i++)
        fin>>g[i];
    nrmin=n;
    nr=2;
    bkt(1,nr);
    fout<<nrmin<<'\n';
    return 0;
}
