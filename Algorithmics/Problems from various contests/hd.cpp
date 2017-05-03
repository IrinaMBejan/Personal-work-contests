#include <fstream>
#define NMax 10001
using namespace std;
ifstream fin("hd.in");
ofstream fout("hd.out");

int dest[NMax], sursa[NMax];
int main()
{
    int N,F,w,i,j,c,q,x,k,nr,oo=1;
    fin>>N>>F;
    w=1;
    int p;
    for(i=1; i<=F; i++)
    {
        fin>>q;
        for(j=1; j<=q; j++)
        {
            fin>>x;
            dest[x]=w;
            sursa[w]=x;
            w++;
        }
    }
    nr=0;
    for(i=1; i<=N; i++)
        if(dest[i]==0&&sursa[i]!=0)
        {
            k=i;
            x=0;
            while(dest[k]==0&&sursa[k]!=0)
            {
                x++;
                dest[k]=k;
                dest[sursa[k]]=0;
                k=sursa[k];
            }
            nr+=x;
        }
        else if(dest[i]!=i&&dest[i]!=0)
        {
            k=dest[dest[i]];
            p=0;
            while(k!=i&&k!=0)
            {
                k=dest[k];
                p++;
            }
            if(k==i)
            {
                nr++;
                dest[dest[k]]=0;
                dest[N+oo]=dest[k];
                sursa[dest[k]]=N+oo;
                dest[i]=0;
                i--;
            }
        }
    fout<<nr<<'\n';
    return 0;
}
