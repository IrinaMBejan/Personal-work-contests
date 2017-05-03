#include <fstream>
using namespace std;

ifstream fin("porumb.in");
ofstream fout("porumb.out");

int main()
{
    int m,n,s,st,dr,x,i;
    s=0;
    fin>>n>>m;
    st=m-1;
    dr=n-m;
    for(i=1;i<=n;i++)
    {fin>>x;
    s+=x;}

    if(st>=dr)
        s=s+dr+n-1;
     else if(st<dr)
         s=s+st+n-1;
    fout<<s;
    return 0;
}
