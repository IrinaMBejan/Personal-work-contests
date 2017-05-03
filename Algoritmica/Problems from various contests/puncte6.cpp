#include <fstream>
using namespace std;
ifstream fin("puncte6.in");
ofstream fout("puncte6.out");
int poz[500000];
int X[2000],Y[2000];
int maxi,i,x,y,n,n1,j,nrp,nrabs,marcate,gasite,b1,b2,nr0,nrd;

int main()
{
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>x>>y;
        if(x==y)  b1++;
        if(x==-y) b2++;
        if(x==0 && y==0) nr0++;
        poz[i]=i;
        X[x+1000]++;
        Y[y+1000]++;
    }
    b1=b1-nr0;
    b2=b2-nr0;
    maxi=0;
    for(i=1; i<=1999; i++)
    {
        if(X[i]>maxi)maxi=X[i];
        if(Y[i]>maxi)maxi=Y[i];
    }
    fout<<maxi<<'\n';
    if(b1==0 && b2==0) nrd=0;
    else if(b2+nr0>1 && b1+nr0>1) nrd=b1*b2+2;
    else nrd=b1*b2+1;
    fout<<nrd<<'\n';
    i=1;
    while(marcate<n-1)
    {
        marcate++;
        poz[i]=0;
        do
        {
            i++;
            if(i>n) i=1;
        }
        while(poz[i]==0);
        do
        {
            i++;
            if(i>n) i=1;
        }
        while(poz[i]==0);
        do
        {
            i++;
            if(i>n) i=1;
        }
        while(poz[i]==0);
    }
    nrp=1;
    while(poz[nrp]==0)nrp++;
    i=1;
    while(nrp>0)
    {
        while(X[i]==0)i++;
        nrabs=X[i];
        while(nrabs>0 && nrp>0)
        {
            nrp--;
            nrabs--;
        }
        i++;
    }
    fout<<i-1001<<'\n';
    return 0;
}
