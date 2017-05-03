#include <fstream>
#define Nmax 1005
using namespace std;

ifstream fin("Quick.in");
ofstream fout("Quick.out");
int DIV(int st, int dr);
void Quick(int st, int fi);

int a[Nmax], b[Nmax];

void Quick(int st, int fi)
{
    if (st<fi)
    {
        int poz=DIV(st, fi);
        Quick(st, poz-1);
        Quick(poz+1,fi);
    }
}

int DIV(int st, int dr)
{
    int pivot = a[st];

    while (st<dr)
               {//liber la stanga
                //caut in dreapta un element mai mic decat pivotul
                while (st<dr && a[dr]>=pivot) dr--;
                a[st]=a[dr];
                //liber la drepta
                //caut in stanga un element mai mare decat pivotul
                while (st<dr && a[st]<=pivot) st++;
                a[dr]=a[st];
               }
    a[st]=pivot;
    return st;

}
int n;

int main()
{
    fin>>n;
    for(int i=1; i<=n; i++)
        fin>>a[i];

    Quick(1,n);

    for(int i=1; i<=n; i++)
        fout<<a[i]<<" ";
    return 0;
}
