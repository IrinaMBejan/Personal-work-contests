#include <iostream>

using namespace std;

int cmmmdc(int a, int b)
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
    int i, n, a[11],rez,dc;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>a[i];
    rez=a[1];
    for(i=2;i<=n;i++)
        rez=rez*a[i]/cmmmdc(rez,a[i]);
    cout<<rez<<'\n';
    return 0;
}


