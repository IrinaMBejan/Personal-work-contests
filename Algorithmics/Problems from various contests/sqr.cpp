#include <fstream>

using namespace std;

ifstream fin("sqr.in");
ofstream fout("sqr.out");

int a[100001], prod[1001];
int main()
{
    int n, x, f, max=0, i, p=1;
    fin>>n;
    prod[0]=1;
    prod[1]=1;
    for (i=1; i<=n; i++)
        {
            fin>>x;
            f=2;
            do
                {
                    while (x%f==0)
                        {
                            a[f]++;
                            x/=f;
                        }
                    f++;
                    if (f>max) max=f;
                }
            while (x>1);
        }
    for (i=1; i<=max; i++)
        if (a[i])
         if (a[i]%2==1)
        //    p*=i;
             {
                 int j;
                 unsigned long t=0;
                 for (j=1; j<=prod[0]; j++)
                    {
                        prod[j]=prod[j]*i+t;
                        t=prod[j]/10;
                        prod[j]%=10;
                    }
                 while  (t)
                    {
                        prod[0]++;
                        prod[prod[0]]=t%10;
                        t/=10;
                    }
             }
    for (i=prod[0]; i>=1; i--)
            fout<<prod[i];
          //  fout<<p<<'\n';
    return 0;
}
