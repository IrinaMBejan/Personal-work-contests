#include <cstdio>

using namespace std;
FILE* fin=fopen("ssm.in","r");
FILE* fout=fopen("ssm.out","w");

int main()
{
    int n,i,st,fi,poz;
    long long int s=0,bestsum=-999999999999,mmin=0,x;
    fscanf(fin,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fin,"%lld",&x);
        s+=x;
        if(s-mmin>bestsum)
        {
            bestsum=s-mmin;
            fi=i;
            st=poz+1;
        }
        if(mmin>s)
        {
            mmin=s;
            poz=i;
        }
    }
    fprintf(fout,"%lld %d %d\n",bestsum,st,fi);
    return 0;
}
