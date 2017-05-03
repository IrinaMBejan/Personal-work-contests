#include <cstdio>
#define NMAX 10001
using namespace std;

FILE* fin=fopen("atelier.in","r");
FILE* fout=fopen("atelier.out","w");

int Sa[NMAX],Sb[NMAX];
int main()
{
    int n,i,maxi=0,nr=0,poz=1,a,b;
    char mem;
    fscanf(fin,"%d",&n);
    Sa[0]=0;
    Sb[0]=0;
    for(i=1;i<=n;i++)
    {
        fscanf(fin,"%d %d",&a,&b);
        Sa[i]=Sa[i-1]+a;
        Sb[i]=Sb[i-1]+b;
    }
    maxi=Sa[1]+(Sb[n]-Sb[1]);
    for(i=2;i<=n-1;i++)
    {
        nr=Sa[i]+(Sb[n]-Sb[i]);
        if(nr>=maxi) {maxi=nr; poz=i;}
    }
    mem='A';
    for(i=1;i<n;i++)
    {
        nr=Sb[i]+(Sa[n]-Sa[i]);
        if(nr>maxi) {maxi=nr; poz=i; mem='B';}
    }
    fprintf(fout,"%d\n%c\n%d\n",maxi,mem,poz);
    return 0;
}
