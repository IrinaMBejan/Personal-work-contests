#include <fstream>

using namespace std;
ifstream fin("expresie.in");
ofstream fout("expresie.out");

int a[1001];
int main()
{
    long long int n,maxp,maxs,poz1,poz2,i,p;
    long long int s;
    fin>>n;
    s=0;
    maxp=0;
    maxs=0;
    for(i=1;i<=n;i++)
    {
        fin>>a[i];
        s+=a[i];
    }
    long long int poz,maxx=0;
    for(i=1;i<n;i++)
    {
        p=a[i]*a[i+1];
        if(p>maxp) {maxs=maxp; poz2=poz1; maxp=p;poz1=i;}
        else if(p>maxs) {maxs=p; poz2=i;}
        p*=a[i+2];
        if(p>maxx) {maxx=p; poz=i;}
    }
    if(s-a[poz1]-a[poz1+1]-a[poz2]-a[poz2+1]+maxp+maxs>s-a[poz]-a[poz+1]-a[poz+2]+maxx)
    fout<<s-a[poz1]-a[poz1+1]-a[poz2]-a[poz2+1]+maxp+maxs<<'\n';
    else fout<<s-a[poz]-a[poz+1]-a[poz+2]+maxx<<'\n';
    return 0;
}
