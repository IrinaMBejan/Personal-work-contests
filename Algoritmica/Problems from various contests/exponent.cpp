#include <cstdio>

using namespace std;

FILE* fin=fopen("exponent.in","r");
FILE* fout=fopen("exponent.out","w");

int a[30001];

int main()
{
    int x, d, n, f, i;
    fscanf(fin,"%d %d", &n, &d);
    for (i=1; i<=n; i++)
        {
            fscanf(fin,"%d", &x);
            f=3;
            while (x%2==0)
                   {
                            a[2]++;
                            x/=2;
                   }
           while (x>1)
               {
                    while (x%f==0)
                        {
                            a[f]++;
                            x/=f;
                        }
                    f+=2;
               }
         }
    int p=0,k=999999,ok,initial=d;
    f=3;
    while (d%2==0)
            {
                p++;
                d/=2;
            }
    if(p) k=a[2]/p;
    while (d>1)
      {
            p=0;
            while (d%f==0)
                  {
                        p++;
                        d/=f;
                  }
            if(p)
                if(a[f]/p<k)
                        k=a[f]/p;
            f+=2;
       }
    if(d==initial) k=0;
        fprintf(fout,"%d\n", k);
    return 0;
}
