#include <cstdio>

using namespace std;
FILE* fin=fopen("235.in","r");
FILE* fout=fopen("235.out","w");
int caubin(long long int a[23], int na, long long int target);

long long int a5[23],a3[23];
int k[40001];
int main()
{
    int n,j,n3,n5,nr;
    long long int x,i;
    fscanf(fin,"%d",&n);
    for(i=1,j=1; i<=2000000000; i*=5,j++)
        a5[j]=i;
    n5=j;
    for(i=1,j=1; i<=2000000000; i*=3,j++)
        a3[j]=i;
    n3=j;
    nr=0;
    int m=0;
    for(i=1; i<=n; i++)
    {
        fscanf(fin,"%lld",&x);
        if(caubin(a5,n5,x)!=0)
        {
            nr++;
            k[++m]=1;
        }
        else if(caubin(a3,n3,x)!=0)
        {
            nr++;
            k[++m]=0;
        }
    }

    fprintf(fout,"%d\n",nr);

    x=2; int s=0;
    int nr2=0;
    while(x<=m)
    {
        for(i=1;i<=x;i++)
            s+=k[i];
        if(s==x/2) nr2++;
        for(i=x+1;i<=m;i++)
        {
            s=s-k[i-x]+k[i];
            if(s==x/2) nr2++;
        }
        x*=2;
        s=0;
    }
    fprintf(fout,"%d\n",nr2);
    return 0;
}

int caubin(long long int a[23], int na, long long int target)
{
    int st = 1, fi = na,mid;
    while (st <= fi)
    {
        mid = st + (fi-st)/2;
        if(a[mid] == target)
            return mid;
        else if(a[mid] < target)
            st = mid+1;
        else
            fi = mid-1;
    }
    return 0;
}
