#include <iostream>
#define LGMAX 101
using namespace std;

int termeni[LGMAX];
int n;
int s;
void part(int k)
{
    if(s==n)
    {
        for(int i=1;i<k;i++)
            cout<<termeni[i]<<" ";
        cout<<'\n';
    }
    else
        for(int i=termeni[k-1];i<=n-s;i++)
        {
            termeni[k]=i;
            s+=i;
            part( k+1);
            s-=i;
        }
}
int main()
{
    cin>>n;
    termeni[0]=1;
    part(1);
    return 0;
}
