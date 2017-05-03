#include <iostream>
#include<cmath>
#define NMAX 100
using namespace std;
int sol[NMAX];
int n;
void bkt(int k)
{
    int i,j;
    bool ok;
    if(k-1==n)
    {
        for(i=1;i<=n;i++)
            cout<<sol[i]<<" ";
        cout<<'\n';
    }
    else
    {
        //plasez o dama pe linia k
        for (i=1; i<=n; i++)
             //pot pune dama pe coloana i?
        {
            ok=1;
            for (j=1; j<k; j++)
                 if (sol[j]==i ||k-j==abs(sol[j]-i)) {ok=0; break;}
            if (ok)
            {
                sol[k]=i; bkt(k+1);
            }
        }
    }

}

int main()
{
    cin>>n;
    bkt(1);
    return 0;
}
