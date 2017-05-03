#include <fstream>
#define Lm 100002
using namespace std;
ifstream fin("maxbin.in");
ofstream fout("maxbin.out");
int s0[Lm],d0[Lm],s1[Lm],d1[Lm];
bool a[Lm];
int main()
{
    int n,k,i,j,nr1,nr0,nrm, nrmax=-1,poz;
    fin>>n>>k;
    for(i=1;i<=n;i++)
        fin>>a[i];/*s0[i] = numarul de zerouri consecutive din stanga pozitiei i
d0[i] = numarul de zerouri consecutive din dreapta pozitiei i
s1[i] = numarul de valori 1 consecutive din stanga pozitiei i
d1[i] = numarul de valori 1 consecutive din dreapta pozitiei i*/
    a[0]=99;
    a[n+1]=99;
    nr0=nr1=0;
    for(i=1;i<=n;i++)
    {
        s0[i]=nr0;
        s1[i]=nr1;
        if(a[i]==0&&a[i-1]==0) nr0++;
        else if(a[i]==1&&a[i-1]==1) nr1++;
        else
        {
            if(a[i]==0) {nr1=0; nr0=1;}
            else if(a[i]==1){nr0=0; nr1=1;}
        }
    }
    nr0=0;
    nr1=0;
    for(i=n;i>=1;i--)
    {
        d1[i]=nr1;
        d0[i]=nr0;
        if(a[i]==0&&a[i+1]==0) nr0++;
        else if(a[i]==1&&a[i+1]==1) nr1++;
        else
        {
            if(a[i]==0) {nr1=0;nr0=1;}
            else if(a[i]==1) {nr0=0; nr1=1;}
        }
    }
    for(i=1;i<=n;i++)
        if(a[i]==1)
        {
            if(a[i]==1&&a[i+1]==0)
                {
                    if(d0[i]>k) nrm=k+s1[i]+1;
                    else nrm=d0[i]+s1[i]+1;
                    if(nrm>nrmax) {
                            nrmax=nrm; poz=i+1;}
                }
             if(a[i]==1&&a[i-1]==0)
                {
                    if(s0[i]>k) nrm=k+d1[i]+1;
                    else nrm=s0[i]+d1[i]+1;
                    if(nrm>nrmax)
                        {nrmax=nrm; if(s0[i]>k) poz=i-k-1;else poz=i-s0[i]-1;}
                }
        }
        fout<<nrmax<<" "<<poz<<'\n';
    return 0;
}
