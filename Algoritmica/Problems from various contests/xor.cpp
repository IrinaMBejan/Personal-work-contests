#include<fstream>
#define Nmax 2000
using namespace std ;
int n, a[Nmax+5], x[Nmax+5], x1, x2, x3, smax ;
ifstream fin("xor1.in");
ofstream fout("xor1.out");

void Citire()
{
	int i ;
	fin>>n ;
	for (i=1 ; i<=n ; i++)
	{
		fin>>a[i] ;
		x[i] = x[i-1] ^ a[i] ;
	}
	fin.close() ;
}

void Solutie()
{
	int k, p;
	smax = 0 ;
	for (k = 1 ; k<n ; k++)
		for (p = k+1 ; p<=n ; p++)
		{
			x1 = x[k] ;
			x2 = x[p] ^ x[k] ;
			x3 = x[n] ^ x[p] ;
			if (smax < x1 + x2 + x3)
				smax = x1 + x2 + x3 ;
		}
	fout<<smax<<"\n" ;
	fout.close() ;
}

int main()
{
	Citire() ;
	Solutie() ;

	return 0 ;
}
