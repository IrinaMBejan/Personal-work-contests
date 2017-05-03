#include <cstdio>

using namespace std;
FILE* fin=fopen("nr01.in","r");
FILE* fout=fopen("nr01.out","w");

bool subm[40];
int m;
long long int q;
int b;

void convert();

int main()
{
    int n,i;
    fscanf(fin,"%d %d",&m,&b);
    q=0;
    while(q<=m)
    {
        convert();
        if(q<=m) fprintf(fout,"%lld\n",q);
        for(i=30;i>0&&subm[i]==1;i--) subm[i]=0;
        subm[i]=1;
    }
    return 0;
}

void convert()
{
    long long int p=1,i;
    q=0;
    for(i=30;i>=1;i--)
    {
        q+=(subm[i]*p);
        p*=b;
    }
}
