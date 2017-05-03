#include <fstream>
#define DMAX 10000
using namespace std;

ifstream fin("arme.in");
ofstream fout("arme.out");

int nr[DMAX];
int main()
{
    int n, m, x, i, s, nmax=0,j;
    fin>>n>>m;
    s=n+m;
    for (i=1; i<=s; i++)
        {
            fin>>x;
            nr[x]++;
            if(x>nmax) nmax=x;
        }
    s=0;
    for (i=nmax; i>=0 && n>0; i--)
               for(j=1;j<=nr[i] && n>0;j++)
                    {
                        s+=i;
                        n--;
                    }
    fout<<s<<'\n';
    return 0;
}
