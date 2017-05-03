#include <fstream>

using namespace std;

ifstream fin("romane.in");
ofstream fout("romane.out");
int n, L, V, I, C, X, p, pi;

int main()
{
	fin>>n;
	p=1;
	while(p<=n)
	{
		pi=p;
		while(pi>=100)
		{
			C=C+1; pi=pi-100;
		}
		if(pi>=90)
		{
			X=X+1; C=C+1; pi=pi-90;
		}
		if(pi>=50)
		{
			L++; pi=pi-50;
		}
		if(pi>=40)
		{
			X++; L++; pi=pi-40;
		}
		while(pi>=10)
		{
			X++; pi=pi-10;
		}
		if(pi>=9)
		{
			X++; I++; pi=pi-9;
		}
		if(pi>=5)
		{
			V++; pi=pi-5;
		}
		if(pi>=4)
		{
			I++; V++; pi=pi-4;
		}
		while(pi>=1)
		{
			I++; pi=pi-1;
		}
		p++;
	}
	fout<<I<<' '<<V<<' '<<X<<' '<<L<<' '<<C<<' '<<'\n';
	fout.close();
	return 0;
}
