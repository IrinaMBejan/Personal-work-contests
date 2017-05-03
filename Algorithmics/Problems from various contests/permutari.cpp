#include <iostream>
#include <algorithm>
using namespace std;

int a[100];
int compare(int a, int b)
{
    return a<b;
}
int main()
{
    int n,i,ok,aux,j;
    cin>>n;
    for(i=1;i<=n;i++)
        a[i]=i;
    ok=0;
    while(!ok)
    {
        for(i=1;i<=n;i++)
            cout<<a[i]<<" ";
        cout<<'\n';
        i=n-1;
        while(a[i]>a[i+1]&&i>=1) i--;
        if(i==0) ok=1;
        else
        {
            j=n;
            while(a[j]<a[i]&&j>=1) j--;
            aux=a[i];
            a[i]=a[j];
            a[j]=aux;
            sort(a+i+1,a+n+1,compare);
        }
    }
    return 0;
}
