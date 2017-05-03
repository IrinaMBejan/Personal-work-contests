#include <fstream>
#include<algorithm>
using namespace std;
ifstream fin("vintage.in");
ofstream fout("vintage.out");

struct masina
{
    int val;
    int cost;
    int nr;

}a[1001];

int compare(masina a, masina b)
{
    return(a.val>b.val||(a.val==b.val&&a.cost<b.cost));
}
int main()
{
    int n,m,i;
    long long int vmax=0,cmin=0;
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>a[i].cost>>a[i].val;
        a[i].nr=i;
    }
    sort(a+1,a+n+1,compare);
    for(i=1;i<=m;i++)
    {
        vmax+=a[i].val;
        cmin+=a[i].cost;
    }
    fout<<vmax<<" "<<cmin<<'\n';
    for(i=1;i<=m;i++)
        fout<<a[i].nr<<" ";
    return 0;
}
