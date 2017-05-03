#include <iostream>
#define LMAX 1001
using namespace std;

bool subm[LMAX];
int main()
{
    int n,ok=1,i,k;
    cin>>n;
    i=1;
    while(!subm[0])
    {
        for(i=1;i<=n;i++)
            cout<<subm[i];
        cout<<'\n';
        for(i=n;i>0&&subm[i]==1;i--) subm[i]=0;
        subm[i]=1;
    }
    return 0;
}
