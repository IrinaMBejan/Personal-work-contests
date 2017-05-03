#include <fstream>
using namespace std;

int a[100];
ifstream fin("permutari.in");
ofstream fout("permutari.out");

int main()
{
    int n,i,ok,aux,j;
    fin>>n;
    for(i=1; i<=n; i++)
        a[i]=i;
    ok=0;
    int st,dr;
    while(!ok)
    {
        for(i=1; i<=n; i++) fout<<a[i]<<" ";
        fout<<'\n';

        i=n-1;
        while (a[i]>a[i+1] && i>=1) i--;
        if (i==0) ok=1;
        else
        {
            j=n;
            while (a[j]<a[i]) j--;
            aux=a[i];
            a[i]=a[j];
            a[j]=aux;
            for (st=i+1,dr=n; st<dr; st++,dr--)
            {
                aux=a[st];
                a[st]=a[dr];
                a[dr]=aux;
            }


        }
    }
    return 0;
}
