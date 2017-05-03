#include <fstream>

using namespace std;
ifstream fin("cubinvers.in");
ofstream fout("cubinvers.out");

int n, conf[30], sol[11],solmax[11],uz[30],nrz,test[30],nrmax=-1;

void bkt(int k)
{
    if(k-1==nrz)
    {
        int p=1;
        for(int i=1; i<=n; i++)
            if(conf[i]==0) test[i]=sol[p++];
            else test[i]=conf[i];
        int nr=0,aux;
        while(test[n]!=1)
        {
            int val=test[n];
            int st=n-val+1,dr=n;
            for(int j=0; j<=(dr-st)/2; j++)
                aux=test[st+j],test[st+j]=test[dr-j], test[dr-j]=aux;
            nr++;
        }
        if(nr>nrmax)
        {
            nrmax=nr;
            for(int i=1; i<=n; i++)
                solmax[i]=sol[i];
        }
    }
    else
    {
        for(int i=1; i<=n; i++)
            if(uz[i]==0)
            {
                sol[k]=i;
                uz[i]=1;
                bkt(k+1);
                uz[i]=0;
            }
    }
}
int main()
{
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        fin>>conf[i];
        if(conf[i]!=0)
            uz[conf[i]]=1;
        else nrz++;
    }
    if(conf[n]!=1)
        bkt(1);
    else
    {
        int q=1;
        nrmax=0;
        for(int i=1; i<=n; i++)
            if(uz[i]==0)
                solmax[q++]=i;
    }
    fout<<nrmax<<'\n';
    int p=1;
    for(int i=1; i<=n; i++)
        if(conf[i]==0) conf[i]=solmax[p++];
    for(int i=1; i<=n; i++)
        fout<<conf[i]<<" ";
    fout<<'\n';
    return 0;
}
