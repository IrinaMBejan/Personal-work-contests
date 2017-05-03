#include <cstdio>
#include<cmath>
#define N 600
using namespace std;

int a[N][N];

int lung(int x)
{
    int nr=0;
    while(x){nr++; x/=10;}
    return nr;
}

FILE* fin=fopen("rombul.in","r");
FILE* fout=fopen("rombul.out","w");

int main()
{
    int n,i,j,k=1,ii;
    fscanf(fin,"%d",&n);
    for(i=0;i<=n-1;i++)
    {
        for(j=i;j<=n-1;j++) a[n-1-j+i][j]=k++;
        for(j=i+1;j<=n-1;j++) a[j][n+j-1-i]=k++;
        for(j=n;j<=2*n-2-i;j++) a[j][3*n-3-j-i]=k++;
        for(j=n-2;j>=i+1;j--)a[j+n-1-i][j]=k++;
    }

    fprintf(fout,"%d\n",k-1);
    k=lung(k-1);
    for(i=0;i<=2*n-2;i++)
    {
        for(j=0;j<=2*n-2;j++)

          if(a[i][j])
               fprintf(fout,"%*d",k+1,a[i][j]);
        else if(j-i<=n-1 && i+j<=3*n-3)
                for(ii=0;ii<k+1;ii++) fprintf(fout,"%c",' ');
        fprintf(fout,"\n");
    }
  return 0;
}
