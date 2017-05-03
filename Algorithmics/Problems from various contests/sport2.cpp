#include <iostream>
#include<algorithm>
using namespace std;

struct elev
{
    int nr;
    int luat;
} a[1001];


int compare(int a, int b)
{
    return a>b;
}
int cmmdc(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int n,i,p,q,nr,qi,j;
    long long int rez=1;
    cin>>n;
    for(i=1; i<=n; i++)
        cin>>a[i].nr;
    for(i=1; i<=n; i++)
        if(a[i].luat==0)
        {
            p=i;
            qi=i;
            q=-1;
            nr=1;
            while(p!=q)
            {
                q=a[a[qi].nr].nr;
                qi=a[qi].nr;
                a[qi].luat=1;
                nr++;
            }
            rez=rez*nr/cmmdc(rez,nr);
        }
    cout<<rez<<'\n';
    return 0;
}
