#include <fstream>

using namespace std;

ifstream fin("prodnr.in");
ofstream fout("prodnr.out");

char c;
int p[15000], f[100000];
long nr, n, k, nrd, i, j;
int main()
{

    for (i=2; i*i<=99999; i++)
        if (f[i]==0)
        {
            p[nrd++]=i;
            for (j=i*i; j<=99999; j+=i)
                f[j]=1;
        }
    for (; i<=99999; i++)
        if (f[i]==0) p[nrd++]=i;
         c=fin.get();
    while (c!='\n')
    {
        nr++;
        n=c-'0';
        k=0;
        for (int i=0; i<n; i++)
        {
            c=fin.get();
            k=k*10+c-'0';
        }
        i=0;
        while (k>1)
        {
            while (k%p[i]==0) f[p[i]]++, k/=p[i];
            i++;
        }
        c=fin.get();
    }
    fout<<nr<<'\n';
    for (int i=0; i<nrd; i++)
        if (f[p[i]]) fout<<p[i]<<' '<<f[p[i]]<<'\n';
    return 0;
}
