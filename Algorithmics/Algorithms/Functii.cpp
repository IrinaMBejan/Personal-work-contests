#include <iostream>
#define NR 101

using namespace std;

void citeste(int& x, int q[NR]);
void scrie(int x, int q[NR]);

int a[NR], b[NR],n,m;
int main()
{

    citeste(n,a);
    scrie(n,a);
    citeste(m,b);
    scrie(m,b);
    return 0;
}

void citeste(int& x, int q[NR])
{
    int i;
    cin>>x;
    for(i=1;i<=x;i++)
        cin>>q[i];
}

void scrie(int x,int q[NR])
{
    int i;
    for(i=1;i<=x;i++)
        cout<<q[i]<<" ";
    cout<<'\n';
}
