#include <fstream>

using namespace std;

ifstream fin("bete1.in");
ofstream fout("bete1.out");
int n,l,k,a,b,i,j,s,ma,mb,na,nb;
int main()
{
    fin>>n;
    fin>>a;
    ma=a;na=1;s=a;
    for(i=2;i<=n;i++)
           {
               fin>>a;
               if(ma<a){ma=a;na=1;}
               else if(ma==a)na++;
               s+=a;
           }
    fin>>b;
    mb=b;nb=1;s+=b;
    for(i=2;i<=n;i++)
           {
               fin>>b;
               if(mb<b){mb=b;nb=1;}
               else if(mb==b)nb++;
               s+=b;
           }
    l=s/n;
    fout<<l<<'\n'<<ma+mb<<'\n'<<min(na,nb)<<'\n';
    fout.close();
    return 0;
}
