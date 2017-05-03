#include <fstream>

using namespace std;
ifstream fin("cifru5.in");
ofstream fout("cifru5.out");

int a[100001], c[10];
int main()
{
    int N,i,j,nrm,nrmax,nrnmin,nmin,max;
    fin>>N;
    max=-1;
    for(i=1; i<=N; i++)
    {
        fin>>a[i];
        if(a[i]>max) max=a[i];
    }
    fout<<max<<'\n';
    nrmax=343534;
    nmin=-1;
    nrnmin=-1;
    for(i=0; i<=9; i++)
    {
        nrm=0;

        for(j=1; j<=N; j++)
        {
            if(a[j]<i)// de la 3 la 9
            {
                if(i-a[j]<a[j]+10-i)
                    nrm+=i-a[j];
                else nrm+=a[j]+10-i;
            }
            else // de la 9 la 3
            {
                if(i+10-a[j]<a[j]-i)
                    nrm+=i+10-a[j];
                else nrm+=a[j]-i;
            }
        }
        if(nrm<nrmax)
        {
            nrmax=nrm;
            nmin=i;
            nrnmin=1;
        }
        else if(nrm==nrmax)
        {
            nrnmin++;
        }
    }
    fout<<nrmax<<'\n'<<nmin<<'\n'<<nrnmin<<'\n';
    return 0;
}
