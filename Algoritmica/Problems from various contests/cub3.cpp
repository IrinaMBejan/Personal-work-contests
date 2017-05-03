#include<fstream>

using namespace std;

ifstream fin("cub3.in");
ofstream fout("cub3.out");

int n,nrc[11],a[51],lg[51],b[51];

int main()
{
	int i,nr,max=0,k,j,lgc,lgmax;
	fin>>n;
	for(i=1;i<=n;i++)
	{
		fin>>a[i];
		nrc[a[i]]++;
	}
	for(nr=0,i=1;i<11;i++)
		if(nrc[i]!=0)
			nr++;
	fout<<nr<<'\n';
	for(i=1;i<11;i++)
		if(nrc[i]>max)
			max=nrc[i];
	for(i=1;i<11;i++)
		if(nrc[i]==max)
			fout<<i<<' ';
	fout<<'\n';
	for(i=1;i<=n;i++)
	{
		for(k=j=1;j<=n;j++)
			if(i!=j)
				b[k++]=a[j];
		lgmax=0;
		lgc=1;
		for(j=1;j<n;j++)
			if(b[j]==b[j+1])
				lgc++;
			else
			{
				if(lgc>lgmax)
					lgmax=lgc;
					lgc=1;
			}
		lg[i]=lgmax;
	}
	max=lg[1];
	for(i=2;i<=n;i++)
		if(max<lg[i])
			max=lg[i];
	fout<<max<<'\n';
	for(i=1;i<=n;i++)
		if(max==lg[i])
			fout<<i<<' ';
	fout.close();
	return 0;
}
