#include <fstream>

using namespace std;
ifstream fin("anagramabil.in");
ofstream fout("anagramabil.out");

int a[10],q[10];
int main()
{
    unsigned long int n,copie,cp,i,nr=0,copie2;
    fin>>n;
    copie=n;
    copie2=n;
    while(n>0)
    {
        a[n%10]++;
        n/=10;
    }
    for(i=1;i<=8;i++)
    {
        copie+=copie2;
        cp=copie;
        while(cp>0)
        {
            q[cp%10]++;
            cp/=10;
        }
        int ok=1;
        for(int k=0;k<=9;k++)
        {
            if(q[k]!=a[k]) ok=0;
            q[k]=0;
        }
        if(ok) nr++;
        if(ok&&nr==1)
            fout<<"DA"<<'\n'<<i+1;
        else if(ok)fout<<i+1;
    }
    if(nr==0)
        fout<<"NU";
    fout<<'\n';
    return 0;
}
