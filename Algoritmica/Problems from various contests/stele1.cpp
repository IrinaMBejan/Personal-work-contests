#include<fstream>
using namespace std;
ifstream fin("stele1.in");
ofstream fout("stele1.out");
int main()
{
	long long int n,k,N;
	fin>>k>>n;
	fout<<1+k*(k-1);
	N=1;
	while(N*N<n) N++;
	fout<<'\n'<<N<<" "<<N*N-n+1<<'\n';
	fin.close();
	fout.close();
	return 0;
}



