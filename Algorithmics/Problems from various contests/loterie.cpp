#include <cstdio>
using namespace std;
FILE* fin=fopen("loterie.in","r");
FILE* fout=fopen("loterie.out","w");

bool p[55*2003];
int fol[55*2003];
int a[55];

int main()
{
    int n,nr=0,minim = 0,m,i,j,smax=0;
    fscanf(fin,"%d %d",&n,&m);
    for(int i=1; i<=n; i++)
    {
        fscanf(fin,"%d",&a[i]);
        if(a[i]<minim) minim = a[i];
    }
    if(minim<0)
    {
        minim*=(-1);
        minim++;
    }

    smax = 0;
    for(i=1;i<=n;i++)
    {
        a[i]+=minim;
        smax+= a[i];
    }

    p[0]=1;
    for(i=1; i<=n; i++)
    {
        for(j=smax-1; j>=0; j--)
            if(p[j]&& fol[j]< m)
                {
                    p[j+a[i]]=1;
                    fol[j+a[i]] = fol[j]+1;
                }
    }
    for(i=1; i<=smax; i++)
        if(p[i] && fol[i] == m) nr++;
    fprintf(fout,"%d\n",nr);
    return 0;
}
