#include <fstream>
#include<math.h>
using namespace std;
ifstream fin("pitag.in");
ofstream fout("pitag.out");
int main()
{
    long long int b,c,a,n;
    fin>>a;
    n=a*a;
    int d;
    for (d=a-1; d>=1; d--)
         if (n%d==0)
         {
             b=(a*a/d-d)/2;
             c=b+d;
             if(a*a+b*b==c*c)
             fout<<b<<" "<<c<<'\n';
         }

    return 0;
}
