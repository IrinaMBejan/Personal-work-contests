#include <fstream>
#define Nmax 1005
using namespace std;

ifstream fin("Merge.in");
ofstream fout("Merge.out");

int a[Nmax], b[Nmax];

void Merge(int st, int fi)
{
    if (fi>st)
    {
        Merge(st, (st+fi)/2);
        Merge((st+fi)/2+1,fi);

        int p=st,  q=(st+fi)/2+1, z=st;
        while (p<=(st+fi)/2 && q<=fi)
        {
            if(a[p]<a[q])
                b[z++]=a[p++];
            else
                b[z++]=a[q++];
        }
        while(p<=(st+fi)/2)
            b[z++]=a[p++];

        while(q<=fi)
            b[z++]=a[q++];


        for(int i=st; i<=fi; i++)
            a[i]=b[i];
    }
}
int n;

int main()
{
    fin>>n;
    for(int i=1; i<=n; i++)
        fin>>a[i];

    Merge(1,n);

    for(int i=1; i<=n; i++)
        fout<<a[i]<<" ";
    return 0;
}
