#include<cstdio>
using namespace std;
FILE* fin=fopen("cmmdcsecv.in","r");
FILE* fout=fopen("cmmdcsecv.out","w");
int ciur[1000],a[100001];
int main()
{
    int n,i,j,l,lmax=-1;
    fscanf(fin,"%d",&n);
    for(i=1;i<=n;i++)
    fscanf(fin,"%d",&a[i]);
     for (j=4; j<=1000; j+=2)
        ciur[j]=1;
    for (i=3; i*i<=1000; i+=2)
    {
       if (ciur[i]==0)
          for (j=i*i; j<=1000; j+=i)
               ciur[j]=1;
    }
    for(i=2;i<=1000;i++)
     if(ciur[i]==0)
     {
         for(j=1;j<=n;j++)
         {
             l=j;
             while(a[j]%i==0&&j<=n)
                 j++;
             if(j-l>lmax) lmax=j-l;
         }
     }
     fprintf(fout,"%d\n",lmax);
}
