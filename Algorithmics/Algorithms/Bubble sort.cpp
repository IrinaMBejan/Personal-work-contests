#include <iostream>
#define DMAX 101

using namespace std;

int nr[DMAX];
int main()
{
   int ok=0, n, i, j, c, poz, max, x;
   cin>>n;
   for(i=1; i<=n;i++)
   {
      cin>>x;
      nr[x]++;

   }
   for(i=0;i<DMAX;i++)
      for(j=0; j<nr[i]; j++)
         cout<<i<<" ";

/* Insert sort
   for (i=2; i<=n; i++)
   {
      cin>>x;
      for(poz=i; poz>1 && x<a[poz-1]; poz--)
         a[poz]=a[poz-1];
      a[poz]=x;

   }
   */
/* Selectie
   for(j=n;j>1;j--)
   {
      max=a[1]; poz=1;
      for (i=2; i<=j; i++)
       if(a[i]>max) { max=a[i]; poz=i;}
      a[poz]=a[j];
      a[j]=max;
   }*/
/* BUBBLE SORT
   j=n-1;
   while (ok!=1)
   {
      ok=1;
      for (i=0; i<j; i++)
         if (a[i]>a[i+1])
         {
            c=a[i];
            a[i]=a[i+1];
            a[i+1]=c;
            q=i;
            ok=0;
         }
         j=q+1;
   }*/

    return 0;
}
