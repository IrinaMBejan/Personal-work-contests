#include <fstream>
#define NMAX 90001
using namespace std;

ifstream fin("swap.in");
ofstream fout("swap.out");

char s[NMAX];
int stiva[NMAX];
int main()
{
    int n,i,l=0,c=0,nr=0;
    fin>>n;
    fin.get();
    fin.get(s,n+1);
    for(i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            l++;
            stiva[l]=i;
        }
        if(s[i]==')')
            {
                c+=(i-stiva[l]);
                if(l> 1 && stiva[l] == i - 1)
                    nr++;
                l--;
            }

    }
    if(nr!=0) fout<<c<<'\n'<<c-2<<'\n'<<nr<<'\n';
    else fout<<c<<'\n'<<"-1"<<'\n'<<nr<<'\n';
    return 0;
}
