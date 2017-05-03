#include <iostream>

using namespace std;

int nrd,nri;
char para[101];
int n;

void gen(int k)
{
    if(k-1==n*2)
        {
            for(int i=1;i<k;i++)
                cout<<para[i];
            cout<<'\n';
        }
    else
    {
        if(nrd<n)
        {
            para[k]='(';
            nrd++;
            gen(k+1);
            nrd--;
        }
        if(nrd>nri)
        {
            para[k]=')';
            nri++;
            gen(k+1);
            nri--;
        }
    }
}

int main()
{
    cin>>n;
    para[1]='(';
    nrd=1; nri=0;
    gen(2);
    return 0;
}
