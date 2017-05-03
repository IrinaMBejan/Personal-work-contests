#include <fstream>

using namespace std;
ifstream fin("numere2.in");
ofstream fout("numere2.out");

int a[301];
bool ve[150001];
int main()
{
    int n,x,i,j,smax=0;
    fin>>n;
    //fout<<sizeof(a)+sizeof(ve);
    for(int i=1; i<=n; i++)
    {
        fin>>a[i];
        smax+=a[i];
    }
    ve[0]=1;
    for(i=1; i<=n; i++)
    {
        for(j=smax-1; j>=0; j--)
            if(ve[j])
                ve[j+a[i]]=1;
    }
    i=1;
    int q,lmax=0;
    while(i<=150000)
    {
        q=i;
        while(ve[i]==1)
            i++;
        if(i-q>lmax) lmax=i-q;
        i++;
    }
    fout<<lmax<<'\n';
    return 0;
}
