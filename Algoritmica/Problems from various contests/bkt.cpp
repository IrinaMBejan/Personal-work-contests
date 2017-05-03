#define Dudica "Dudescu Alexandru"
#include <cstdio>

using namespace std;
FILE *f1=fopen("ornament.in","r"),*f2=fopen("ornament.out","w");
bool ok=1,use[16];
struct patrat { short int n,e,s,v; } a[16];
int opt,N,sol[16],nr;
int l;

void afis();
void backt(int k);
int valid(int k);

int main()
{
    fscanf(f1,"%d",&N);

    if(N==4)l=2;
    else if(N==9)l=3;
    else l=4;

    int i;
    for(i=0;i<N;++i)
        fscanf(f1,"%d %d %d %d",&a[i].n,&a[i].e,&a[i].s,&a[i].v);
    fscanf(f1,"%d",&opt);
    ok=1;
    backt(0);
    if(opt==2)
        fprintf(f2,"%d\n",nr);

    return 0;
}

void afis()
{
        int i,j;
        for(i=l-1;i>=0;--i)
        {
            for(j=0;j<l;++j)
                fprintf(f2,"%d ",sol[i*l+j]+1);
            fprintf(f2,"\n");
        }
}

void backt(int k)
{
    if(ok)
    {
        int j=0,b;
        for(j=0;j<N;++j)
        if(!use[j])
        {
            use[j]=1;
            sol[k]=j;
            b=0;
            if(k==0) b=1;
            else if( k/l==0 && k%l>0 && a[sol[k]].v==a[sol[k-1]].e) b=1;
            else if( k%l==0 && a[sol[k]].s==a[sol[k-l]].n) b=1;
            else if( a[sol[k]].v==a[sol[k-1]].e&&a[sol[k]].s==a[sol[k-l]].n)b=1;
            if(b)
                if(k==N-1)
                    if(opt==1)
                        {
                            ok=0;
                            afis();
                        }
                    else
                        ++nr;
            else backt(k+1);
            use[j]=0;
        }
    }
}

//Our greatest weakness lies in giving up. The most certain way to succeed is always to try just one more time.
