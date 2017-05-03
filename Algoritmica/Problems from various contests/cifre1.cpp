#include <fstream>
#include<math.h>
using namespace std;
ifstream fin("cifre1.in");
ofstream fout("cifre1.out");
int main()
{
    int i, nr;
    long long int s=0, x=1, n, h, p;
    fin>>n;
    if (n>=10)
        s+=9;
    if (n>=100)
        s+=180;
    if (n>=1000)
        s+=2700;
    if (n>=10000)
        s+=36000;
    if (n>=100000)
        s+=450000;
    if (n>=1000000)
        s+=5400000;
    if (n>=10000000)
        s+=63000000;
    if (n>=100000000)
        {
            s+=720000000;
            h=n-99999999;
            fout<<s+(9*h);
        }
    else
        {
            p=n;
            nr=0;
            while (p)
                {
                    nr++;
                    p/=10;
                }
            for (i=1; i<nr; i++)
                x*=10;
            fout<<s+((n-x+1)*nr);
        }
    return 0;
}
