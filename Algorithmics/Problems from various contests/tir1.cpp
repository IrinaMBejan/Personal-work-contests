#include <fstream>
#include<algorithm>
#define NMAX 51
#define PMAX 1001
using namespace std;
ifstream fin("tir1.in");
ofstream fout("tir1.out");

int val[NMAX],nrmin[PMAX],vec[PMAX];
int main()
{
    int n,k,i,minim,s=0,x;
    fin>>n;
    fin>>k;
    for(i=1; i<=n; i++)
        fin>>val[i];
    sort(val+1,val+n+1);
    for(x=1; x<=k; x++)
    {
        minim=k+10;
        s++;
        for(i=1; i<=n; i++)
            if(val[i]<=x)
                if(minim>1+nrmin[x-val[i]]&&(nrmin[x-val[i]]!=0||x-val[i]==0))
                {
                    minim=1+nrmin[x-val[i]];
                    vec[s]=x-val[i];
                }
        if(minim==k+10) nrmin[x]=0;
        else nrmin[x]=minim;
    }
    fout<<nrmin[k]<<'\n';
    if(nrmin[k]!=0)
    {
        s=k;
        int nr,last=k;
        while(s!=0)
        {
            nr=s-vec[last];
            fout<<nr<<" ";
            s=vec[last];
            last=last-nr;
        }
        fout<<'\n';
    }
    return 0;
}
