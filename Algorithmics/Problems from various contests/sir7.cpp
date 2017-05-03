#include <fstream>

using namespace std;
ifstream fin("sir7.in");
ofstream fout("sir7.out");

int main()
{
    int n,i,r;
    long long int s;
    s=0;
    fin>>n;
    for(r=1;r<=n/2;r++)
    {
        i=n-2*r;
        while(i>0)
        {
            s=s+i;
            i=i-r;
        }
    }
    fout<<s;
    return 0;
}
