#include <fstream>
#include<algorithm>
#include<string.h>
using namespace std;
ifstream fin("pluton.in");
ofstream fout("pluton.out");
long int Ord(long int x);

struct ofiter
{
    long int nr;
    long int nrod;
} a[4002];


int compare(ofiter a, ofiter b)
{
    return a.nrod<b.nrod;
}

int main()
{
    int n,i;
    fin>>n;
    for(i=1;i<=n;i++)
    {
       fin>>a[i].nr;
       a[i].nrod=Ord(a[i].nr);
    }
    sort(a+1,a+n+1,compare);
    int nrp=0;
    int lungmax=0;
    int nrmax=0;
    int poz,p;
    for(i=1;i<=n;i++)
    {
        p=i;
        while(i<=n&&a[i].nrod==a[i+1].nrod)
            i++;
        nrp++;
        if(i-p+1>lungmax) {lungmax=i-p+1; poz=p; nrmax=1;}
        else if(i-p+1==lungmax) nrmax++;
    }
    fout<<nrp<<'\n'<<lungmax<<'\n'<<nrmax<<'\n';
    for(i=poz+lungmax-1;i>=poz;i--)
        fout<<a[i].nr<<" ";
    fout<<'\n';
    return 0;
}


long int Ord(long int x)
{
    int a[11];
    int nr,i,j;
    for(i=0;i<=9;i++)
        a[i]=0;
    while(x)
    {
        a[x%10]++;
        x/=10;
    }
    for(i=9;i>=0;i--)
        for(j=1;j<=a[i];j++)
            nr=nr*10+i;
    return nr;
}
