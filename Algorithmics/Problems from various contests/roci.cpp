#include <cstdio>

using namespace std;

FILE* fin=fopen("roci.in","r");
FILE* fout=fopen("roci.out","w");
int a[10001];
int main()
{
    int n,i,j,s=0,x;
    fscanf(fin,"%d",&n);
    for(i=1;i<=n;i++)
    {

        fscanf(fin,"%d",&x);
        if(a[x-1]) a[x-1]--;
         a[x]++;
    }
    for(i=1;i<=10000;i++)
        s+=a[i];
    fprintf(fout,"%d\n",s);
    return 0;
}
