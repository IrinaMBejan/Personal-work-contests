#include <fstream>
#include<algorithm>
using namespace std;
ifstream fin("patrate2.in");
ofstream fout("patrate2.out");
struct bloc
{
    int in;
    int sf;
}p[1001];

int compare(int a, int b)
{
    return a<b;
}
int q[1001];
int main()
{
    int n,k,j,h,i,nr;
    fin>>n>>h;
    k=0;
    for(i=1;i<=n;i++)
    {
        fin>>p[i].in>>p[i].sf;
        p[i].sf+=p[i].in;
        q[++k]=p[i].in;
        q[++k]=p[i].sf;
    }
    sort(q+1,q+k,compare);
    int st=1,out=1,stmax,outmax,nrmax=0;
    while(st!=k||out!=k)
    {
        nr=0;
        for(i=q[st];i<=q[out];i++)
            if(i>=p[i].in&&i<=p[i].fi) nr++;
        if(nr>=h)
            out++;
        else
            { if(nr>nrmax) stmax=st; outmax=out; st++; out=st; }
    }
    fout<<stmax<<" "<<outmax<<'\n';
    return 0;
}
