#include <fstream>
#include<algorithm>
#include<math.h>
using namespace std;
ifstream fin("divider.in");
ofstream fout("divider.out");

int compare(int a, int b)
{
    return a<b;
}
int aq[250];
int main()
{
    int a,b,n,k,i,j;
    fin>>a>>b>>n;
    k=0;
    aq[++k]=1;
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            aq[++k]=pow((double)a,i)*pow((double)b,j);
    sort(aq+1,aq+k+1,compare);
    for(i=1;i<=k;i++)
    {
        fout<<aq[i]<<" ";
        while(aq[i]==aq[i+1])
            i++;
    }
    return 0;
}
