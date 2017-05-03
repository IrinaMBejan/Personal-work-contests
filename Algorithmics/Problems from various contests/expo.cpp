#include <fstream>
#include<math.h>
using namespace std;

ifstream fin("expo.in");
ofstream fout("expo.out");

int main()
{
    long long int h,w,n,l,a,b,c,c1,c2;
    fin>>h>>w>>n;
    if(h>w) l=n*h;
    else l=n*w;

    a=-1;
    b=l+1;
    while(b-a>1)
    {
        c=(b+a)/2;
        c1=c/h;
        c2=c/w;
        if(c1*c2<n)
            a=c;
        else
            b=c;
    }
    fout<<b;


    return 0;
}
