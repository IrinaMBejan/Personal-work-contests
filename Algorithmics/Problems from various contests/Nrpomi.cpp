#include <fstream>

using namespace std;
ifstream fin("nrpomi.in");
ofstream fout("nrpomi.out");

int a[1001],t;
int main()
{
    int n,t,x,y,r,sr=0,resf,i;
    fin>>n>>t;
    for(i=1;i<=n;i++)
        fin>>a[i];
    r=1;
    a[n+1]=a[n-1];
    for(i=2;i<=n;i+=2)
    {
        if(a[i-1]==a[i+1])
			r=(r*(t-1))%1234;
		else
			r=(r*(t-2))%1234;

    }
    fout<<r<<'\n';
    return 0;
}
