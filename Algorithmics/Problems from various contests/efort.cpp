#include <fstream>

using namespace std;
ifstream fin("efort.in");
ofstream fout("efort.out");
long long int S[101];
int main()
{
    int n,i,k,zk,x;
    long long int s=0;
    fin>>n>>k;
    S[1]=2;
    S[2]=3;
    i=2;
    while(S[i]>0)
        S[++i]=S[i-1]+S[i-2];
    for(i=1; i<=50; i++)
        S[i]+=S[i-1];
    zk=k;
    for(i=1; i<=n; i++)
    {
        fin>>x;
        if(x<zk) zk-=x;
        else
        {
            x-=zk;
            zk=k;
            s+=k+S[x];
        }
    }
    s+=k-zk;
    fout<<s<<'\n';
    return 0;
}
