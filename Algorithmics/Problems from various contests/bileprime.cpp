#include <fstream>
#define NMAX 1000000

using namespace std;

ifstream fin("bileprime.in");
ofstream fout("bileprime.out");

int ciur[NMAX];

void ciurul()
{
    int i,j;
    ciur[1]=ciur[0]=1;
    for(i=4;i<=NMAX;i+=2)
        ciur[i]=1;
    for(i=3;i<=1000;i+=2)
    {
        if(ciur[i]==0)
            for(j=i*i;j<=NMAX;j+=i)
                ciur[j]=1;
    }
}
int main()
{
    int a,n,b,x,p,i,q;
    ciurul();

    fin>>n>>a>>b;
    for(p=1;p<=n;p++)
    {
        fin>>x;
        if(x<=NMAX) q=ciur[x];
        else q=1;
        if(q==0&&x<=a) {b+=x; a-=x;}
        if(q==1&&x<=b) {b-=x; a+=x;}

    }
    fout<<a<<'\n';
    return 0;
}
