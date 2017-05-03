#include <iostream>

using namespace std;
int L[100];
int nrs;
int n;

void part(int k)
{
    if(k-1==n)
    {
        for(int i=1; i<=nrs; i++)
        {
            cout<<'{';
            for(int j=1; j<=n; j++)
                if(L[j]==i)
                    cout<<j<<" ";
            cout<<'}';
        }
        cout<<'\n';
    }
    else
    {
        for(int i=1; i<=nrs; i++)
        {
            L[k]=i;
            part(k+1);
        }

        nrs++;
        L[k]=nrs;
        part(k+1);
        nrs--;
    }
}
int main()
{
    cin>>n;
    part(1);
    return 0;
}
