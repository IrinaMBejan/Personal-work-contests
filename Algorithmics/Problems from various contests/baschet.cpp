#include <fstream>

using namespace std;
ifstream fin("baschet.in");
ofstream fout("baschet.out");

int main()
{
    int n,a[32],s,l,i,lmax,smax;
    fin>>n;
    i=2;
    fin>>a[1];
    lmax=0;
    smax=0;
    while(i<=n)
    {
        l=0;
        fin>>a[i];
        while(a[i]==a[i-1])
         {
             l++;
             i++;
             fin>>a[i];
         }
         l++;
         s=l*a[i-1];
         if(l>lmax) { lmax=l; smax=s;}
         s=0;
         i++;
    }
    fout<<lmax<<" "<<smax<<" ";
return 0;
}
