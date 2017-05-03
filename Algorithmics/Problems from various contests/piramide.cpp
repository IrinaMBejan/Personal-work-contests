#include <fstream>

using namespace std;
ifstream fin("piramide.in");
ofstream fout("piramide.out");


int n,x,k,y;
int p=1,l=2,mmax,nr=0,pmax=1,ppr=1,last=3,px;
int main()
{
    fin>>n>>x>>k>>y;
    while(last<=n)
    {
        if(x>=ppr && x<=last) px=p;
        while(k && y>=ppr && y<=last)
        {
            nr++,k--;
            if(k) fin>>y;
        }
        if(nr>mmax)
        {
            mmax=nr;
            pmax=p;
        }
        ++p;
        ++l;
        nr=0;
        ppr=last+1;
        last+=l*(l+1)/2;
    }
    if(n<last)
    {
        p--;
        last=ppr-1;
    }
    fout<<px<<'\n'<<p<<'\n'<<n-last<<'\n';
    if(mmax) fout<<pmax<<'\n';
    else fout<<"0\n";
    return 0;
}
