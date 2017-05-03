#include<fstream>
#define NMAX 1001
using namespace std;
ifstream fin("noroc.in");
ofstream fout("noroc.out");

int a[NMAX],q[NMAX];
int main()
{
    int i, n,k;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>q[i];
        a[i]=a[i-1]+q[i]*q[i];
    }
    for(i=1; i<=n; i++)
    {
        a[i]=a[i]%n;
        if(a[i]==0)
        {
            fout<<i<<'\n';
            for(k=1; k<=i; k++)
                fout<<q[k]<<" ";
            fout<<'\n';
            return 0;
        }
    }
    int j;
    for(i=1; i<n; i++)
        for(j=i+1; j<=n; j++)
            if(a[i]==a[j])
            {
                fout<<j-i<<'\n';
                for(k=i+1; k<=j; k++)
                    fout<<q[k]<<" ";
                fout<<'\n';
                return 0;
            }
    return 0;
}
