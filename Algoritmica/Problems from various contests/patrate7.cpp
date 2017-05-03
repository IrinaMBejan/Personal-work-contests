#include <fstream>
#include<math.h>
using namespace std;

ifstream fin("patrate7.in");
ofstream fout("patrate7.out");

int n,m;
int x[29];
long long numar;

int main()
{
    fin>>n>>m;
    int i,j,k;
    int p;
    for(i=1; i<=m; i++)
    {
        fin>>x[i];
        p=1;
        for(j=1; j<x[i]; j++)
            p=p*2;
        numar=numar+p;
    }
    fout<<numar<<"\n";
    int lc;
    float g=1;
    for(i=1; i<=n-1; i++)
        g=g*2;
    if(int(sqrt((double)g))==sqrt(g)) lc=int(sqrt((double)g));
    else lc=int(sqrt((double)g))+1;

    p=1;
    int sum=0;
    k=1;
    while (numar>0)
    {
        if (k==x[1])
            numar=numar/2;
        else
        {
            if (numar%2==0)
                sum=sum+p;
            p=p*2;
            numar=numar/2;
        }
        k++;
    }
    sum=p-sum;
    if(sum%lc==0)
       fout<<lc<<" "<<sum/lc<<"\n";
    else
        fout<<sum%lc<<" "<<sum/lc+1<<"\n";
    return 0;
}
