#include <fstream>

using namespace std;

ifstream fin("exp1.in");
ofstream fout("exp1.out");
int ciur[30001], f[30001];
int main()
{
    int m,n,x,i,j,nrd,ok;
    fin>>m>>n;
    ciur[0]=ciur[1]=1;
    for(i=4;i<=30000;i+=2)
        ciur[i]=1;
    for(i=3;i<=175;i+=2)
    {
        if(ciur[i]==0)
            for(j=i*i;j<=30000;j+=i)
                ciur[j]=1;
    }
    nrd=0;
    for(j=1;j<=n;j++)
    {
        fin>>x;
        while(x%2==0)
        {
            f[2]++;
            x/=2;
        }
        if(x==3||x==5||x==7) f[x]++;
        int s=x,ok=0;;
        for(i=3;i*i<=s;i+=2)
        {
            if(ciur[i]==0)
                while(x%i==0)
                {
                    f[i]++;
                    x/=i;
                    if(i>nrd) nrd=i;
                    ok=1;
                }
             if((i+2)*(i+2)>s&&ok==0)
                {
                    f[x]++;
                    if(x>nrd) nrd=x;
                    break;
                }
        }

    }ok=1;
    for(i=1;i<=nrd;i++)
        if(f[i]) if(f[i]%m!=0) ok=0;
    fout<<ok<<'\n';
    if(ok)
    for(i=1;i<=nrd;i++)
        if(f[i]) fout<<i<<" "<<f[i]/m<<'\n';
    return 0;
}
