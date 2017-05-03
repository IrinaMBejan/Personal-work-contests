#include <iostream>
#define NMAX 1001
using namespace std;

int e[NMAX],res[NMAX];
int main()
{
    int i,n,m,ok=0;
    cin>>n>>m;
    for(i=1; i<=m; i++)
        res[i]=i;
    while(!ok)
    {
        for(i=1; i<=m; i++)
            cout<<res[i]<<" ";
        cout<<'\n';
        i=m;
        while(res[i]==n-m+i&&i>=0)
            i--;
        if(i==0) ok=1;
        else
        {
            res[i]++;
            for(int k=i+1; k<=m; k++)
                res[k]=res[i]+k-i;
        }
    }
    return 0;
}
