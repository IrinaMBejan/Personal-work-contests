#include <fstream>
#include<algorithm>
#define LMAX 1001
using namespace std;
ifstream fin("dreptc.in");
ofstream fout("dreptc.out");

int cautabin(int lin, int x);
void citire();

int a[6][LMAX],N,C;
int main()
{
    int c,nr=0,i,j,poz3,poz4;
    citire();
    for(c=1;c<=C;c++)
    {
        sort(a[c]+1,a[c]+a[c][0]+1);
        for(i=1;i<a[c][0];i++)
            for(j=i+1;j<=a[c][0];j++)
                if(a[c][i]/10000<a[c][j]/10000&&a[c][i]%10000<a[c][j]%10000)
                        if(cautabin(c,(a[c][i]/10000)*10000+a[c][j]%10000)!=0&&cautabin(c,(a[c][j]/10000)*10000+a[c][i]%10000)!=0)
                                              nr++;
    }
    fout<<nr<<'\n';
    return 0;
}

int cautabin(int lin, int x)
{
    int st=0, fi=a[lin][0]+1,mid;
    while(fi-st>1)
    {
        mid=(fi+st)/2;
        if(a[lin][mid]<x)
                st=mid;
        else if(a[lin][mid]>x)
                fi=mid;
        else return mid;
    }
  // if(mid==a[lin][0]+1||a[lin][mid]!=x)
        return 0;
  //  return mid;
}

void citire()
{
    int x,y,c,i;
    fin>>N>>C;
    for(i=1;i<=N;i++)
    {
        fin>>x>>y>>c;
        a[c][++a[c][0]]=x*10000+y;
    }
}
