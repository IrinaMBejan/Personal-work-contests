#include<fstream>
using namespace std;

ifstream fin("joc20.in");
ofstream fout("joc20.out");
int m[1001];
int main()
{
	int n,x=0,y=0, st=0, sa=0, i, j;
	fin>>n;
	for(i=1;i<=n;i++)
		fin>>m[i];
	for(i=1;i<=n;i++)
	{
		fin>>j;
		if(j==1)
		{
			if(i%2==1) sa+=m[1+x];
			if(i%2==0) st+=m[1+x];
			x++;
		}
		else if(j==2)
	    {
			if(i%2==1) sa+=m[n-y];
			if(i%2==0) st+=m[n-y];
			y++;
		}
	}
	if(sa>st) fout<<sa<<" 1";
	if(st>sa) fout<<st<<" 2";
	if(st==sa) fout<<st<<" 0";
	fin.close();
	fout.close();
	return 0;
}
