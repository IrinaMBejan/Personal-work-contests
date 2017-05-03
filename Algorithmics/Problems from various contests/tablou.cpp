#include <fstream>
#include<math.h>
using namespace std;
ifstream fin("tablou.in");
ofstream fout("tablou.out");


int main()
{
    short int a[11][11],ok=1,n,m,i,j,b,lmax=0,t=0,c;
    long long int n10,nb,max,pb;
    fin>>n>>m;
    while(ok!=0&&n>1&&m>1)
    {
        t++;
        for(i=1; i<=n; i++)
        {
            nb=0;
            b=2;
            for(j=1; j<=m; j++)
            {
                fin>>a[i][j];
                if(a[i][j]>=b) b=a[i][j]+1;
                nb+=(a[i][j]*(pow(10,m-j)));
            }
            pb=1;
            n10=0;
            max=-1;
            do
            {
                n10+=((nb%10)*pb);
                pb*=b;
                nb/=10;
            }
            while(nb!=0);
            if(max<n10) {max=n10; lmax=i;}
            if(t==1) fout<<b<<" ";
        }
        if(t==1) fout<<'\n'<<max<<'\n';
       c=0;
        for(j=1;j<=m;j++)
         if(a[lmax][j]%2==0) { c=j; break;}
        if(c==0) ok=0;
       else
        {
            if(lmax!=n) for(i=lmax; i<n; i++)
                    for(j=1; i<=m; i++)
                        a[i][j]=a[i+1][j];
            n--;
            if(c!=m) for(i=1; i<=n; i++) for(j=c; j<m; j++)
                        a[i][j]=a[i][j+1];
            m--;
        }

    }
   fout<<n<<" "<<m<<'\n';
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
            fout<<a[i][j]<<" ";
        fout<<'\n';
    }

    return 0;
}
