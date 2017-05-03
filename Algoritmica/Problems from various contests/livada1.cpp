#include <cstdio>

using namespace std;
FILE*  fin=fopen("livada1.in","r");
FILE*  fout=fopen("livada1.out","w");

int v[700001];
int main()
{
    int m,n,p,q,lmax,i,j,ll,nr,cand,k;
    fscanf(fin,"%d %d %d",&m,&n,&p);
    lmax=0;
    q=0;
    int maj=n/2+1;
    for(i=1; i<=m; i++)
    {
        cand=-1;k=0;
        for(j=1; j<=n; j++)
        {
            fscanf(fin,"%d",&v[j]);
            if(!k)
            {
                cand=v[j];
                k=1;
            }
            else if(cand==v[j]) k++;
            else k--;
        }
        nr=0;
        j=1;
        if(v[1]==cand) nr++;
        while(j<n)
        {
            ll=0;
            k=j+1;
            if(v[k]==cand) nr++;
            while(v[j]==v[k])
            {
                k++;
                if(v[k]==cand) nr++;
                ll++;
            }
            if(ll>lmax) lmax=ll;
            j=k;
        }
        if(nr>=maj) q++;
    }
    fprintf(fout,"%d\n%d\n",q,lmax+1);
    return 0;
}
