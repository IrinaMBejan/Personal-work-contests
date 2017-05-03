#include <fstream>
#include<math.h>
using namespace std;

ifstream fin("galbeni.in");
ofstream fout("galbeni.out");

int poz[1000],i,k,n,s,a1,a2,a3,w[1000];
int main()
{
    fin>>s>>k>>n;
    int ok=0;
    i=1;
    poz[s]=1;
    while(ok==0&&i<n)
        {
            if(k==1)
                s=(s*s*8/9)%10;
            else if(k==2)
            {
                a2=s%10;
                a1=s/10;
                if(a2==0) a2=1;
                s=(s*a1*a2*8/9)%100;
            }
            else if(k==3)
            {
                a3=s%10;
                a2=(s/10)%10;
                a1=s/100;
                s=(s*a1*a2*a3*8/9)%1000;
            }
            if(log10(s)!=k)
            {
                for(int j=1;j<=k-log10(s);j++)
                    s=s*10+9;
            }
          if(poz[s]) ok=1;
          else poz[s]++;
          i++;
          if(ok==1)

        }
     if(i=n) fout<<s;


    return 0;
}
