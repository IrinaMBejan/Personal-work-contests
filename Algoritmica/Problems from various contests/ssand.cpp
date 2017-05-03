#include <fstream>
#define ll long long
using namespace std;
const int MOD=9973;
int t,np,e[80000],nf;
ll p[80000],f[80000];
bool c[1000001];
void ciur()
{
	p[0]=2;
	for(int i=3;i<1000000;i+=2)
		if(!c[i])
		{
			p[++np]=i;
			if(i<1000)
				for(int j=i*i;j<1000000;j+=i<<1)
					c[j]=1;
		}
}
ll pw(ll n,ll p)
{
	ll sol=1;
	while(p)
	{
		if(p&1)
			sol*=n;
		n*=n;
		p=p>>1;
	}
	return sol;
}


ifstream fin("ssnd.in");
ofstream fout("ssnd.out");

int main()
{
	ll n,i,s,nr;
	ciur();
	fin>>t;
	while(t--)
	{
		fin>>n;
		nf=-1;
		for(i=0;i<=np && p[i]*p[i]<=n;++i)
			if(!(n%p[i]))
			{
				f[++nf]=p[i];
				e[nf]=0;
				while(!(n%p[i]))
				{
					n/=p[i];
					++e[nf];
				}
			}
		if(n>1)
		{
			f[++nf]=n;
			e[nf]=1;
		}
		nr=s=1;
		for(i=0;i<=nf;++i)
		{
			nr*=e[i]+1;
			s=(s*( (e[i]==1) ? (f[i]+1) : ((pw(f[i],e[i]+1)-1)/(f[i]-1)) ))%MOD;
		}
		fout<<nr<<" "<<s<<"\n";
	}
	return 0;
}
