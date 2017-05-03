#include <fstream>
using namespace std;
ifstream fin("banda10.in");
ofstream fout("banda10.out");
int main()
{
	long long int n,x,i,nr=0,cif=0,m;
	char c;
	fin>>n;
	for(i=n-1;i>=0;i--)
	{
		fin>>c;
		x=c-'0';
		if(x==1)
		{
			m=i-1;
			x=2;
			while(m>0)
			{
				x=x*2;
				m--;
			}
			nr=nr+x;
		}
	}
	while(nr>0)
	{
		nr=nr/10;
		cif++;
	}
	fout<<cif;
	fout.close();
	return 0;
}
