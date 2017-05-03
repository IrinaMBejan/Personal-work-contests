#include <fstream>

using namespace std;
ifstream fin("piata.in");
ofstream fout("piata.out");
int iT, jT, iM,jM,n;
int a[171][171];
int sum(int x);

int main()
{
    int i,j,s,s1,e1,e2;
    fin>>n;
    fin>>iT>>jT>>iM>>jM;
    s=0;
    for(j=jT;j<=jM;j++)
        if(j>=iT) s=s+sum(j-iT+1);
          else s=s+sum(n+j-iT+1);
    s1=s;
    for(i=iT+1;i<=iM;i++)
    {
        if(jM>=i-1) e1=sum(jM-(i-1)+1);
            else e1= sum(n+jM-(i-1)+1);
        if(jT>=i) e2=sum(jT-i+1);
         else e2= sum(n+jT-i+1);
        s=s+s1-e1+e2;
        s1=s1-e1+e2;
    }
    fout<<s<<'\n';
    return 0;
}

int sum(int x)
{
    int s=0;
    while(x>0)
    {
        s+=x%10;
        x/=10;
    }
    return s;
}
