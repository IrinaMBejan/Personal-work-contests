# include <fstream>

using namespace std;

ifstream fin("psp.in");
ofstream fout("psp.out");

int n, m, s, x, suma,nr,i;

int main()
{
	fin>>n>>s;
	for(i=1;i<=n;i++)
	{
		fin>>x;
		if(suma+x<=s)
        {
            nr++;
            suma+=x;
        };
	}
	fout<<nr<<' '<<s-suma;
	fout.close();
	return 0;
}
