#include <cstdio>
#define NMAX 100002
using namespace std;
FILE* fin=fopen("vase.in","r");
FILE* fout=fopen("vase.out","w");


struct substanta
{
    char di;
    int vol;
} a[NMAX];


int main()
{
    int n,i,x,q;
    long long int st=0,dr=0;
    long long int s=0,ss=0;
    fscanf(fin,"%d",&n);
    char c;
    for(i=1; i<=n; i++)
    {
        fscanf(fin,"%d %c",&a[i].vol,&a[i].di);
        s+=a[i].vol;
    }
    fprintf(fout,"%lld\n",s/2);


    fscanf(fin,"%d",&x);
    for(i=1; i<x; i++)
        ss+=a[i].vol;
    ss/=2;
    i=x;
    if(a[i].di=='S')
    {
        st = -ss-a[i].vol/2;
        dr = -ss + a[i].vol/2;
    }
    else
    {
        st = ss-a[i].vol/2;
        dr = ss + a[i].vol/2;
    }

    for(i = x+1 ; i<=n ; ++i)
    {
        if(a[i].di=='S')
        {
            st = st+a[i].vol/2;
            dr = dr + a[i].vol/2;
        }
        else
        {
            st = st-a[i].vol/2;
            dr = dr - a[i].vol/2;
        }
    }
    if(st>=0)
        fprintf(fout,"%lld D\n%lld D\n",dr,st);
    else if(dr<=0)
    {
        st*=(-1);
        dr*=(-1);
        fprintf(fout,"%lld S\n%lld S\n",st,dr);
    }
    else
    {
        st*=(-1);
        fprintf(fout,"%lld S\n%lld D\n",st,dr);
    }
    return 0;
}
