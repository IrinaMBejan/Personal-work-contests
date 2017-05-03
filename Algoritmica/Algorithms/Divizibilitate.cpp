#include <iostream>
#include<cmath>
using namespace std;

/* Test de primalitate:
int prim(int n)
{
   int i,rad;
   rad=sqrt(n);
   if (n==2) return 1;
   if (n%2==0) return 0;
   for (i=3; i<=rad; i+=2)
    if(n%i==0) return 0;
   return 1;
}*/
#define NMAX 100000
int ciur[NMAX];

int main()
{
    int d,i,n,j;
    cin>>n;


    /* Ciurul
    for (j=4; j<=n; j+=2)
        ciur[j]=1;
    for (i=3; i*i<=n; i+=2)
    {
       if (ciur[i]==0)
          for (j=i*i; j<=n; j+=i)
               ciur[j]=1;
    }
    for(i=2;i<=n;i++)
     if(ciur[i]==0) cout<<i<<" ";
     /*

    /*cin>>n>>m;
    p=m*n;
    while (m)
          {
           r=n%m;
           n=m;
           m=r;
          }
     cout<<n<<'\n';
     cout<<p/n;
     */
    /* Descompunerea in factori primi a lui a;
    int p=0,i=3;
    ok=0;
    while (a%2==0)
         {
            a/=2;
            p++;ok++;
         }
    if(p) cout<<"2 "<<p<<'\n';

    while (a>1)
          {
             if (i*i>a && !ok) break;
             p=0;
             while (a%i==0)
                   {
                     p++; ok++;
                     a/=i;
                   }

             if (p)
                cout<<i<<" "<<p<<'\n';
             i+=2;
          }
     if (a>1) cout<<a<<" 1";
     */
    /* Toti divizorii
    cout<<"1 "<<n<<" ";
    for (d=2; d*d<n; d++)
         if (n%d==0)
               cout<<d<<" "<<n/d<<" ";
    if (d*d==n)
        cout<<d<<" ";
    */
    return 0;
}
