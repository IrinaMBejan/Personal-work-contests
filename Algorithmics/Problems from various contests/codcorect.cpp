#include<fstream.h>
#include<string.h>
ifstream fin("codcorect.in");
ofstream fout("codcorect.out");
int main()
{
	char s[10],aux;
	int i,n,m;
	fin>>n;
	for(i=1;i<=n;i++)
	{
		fin>>s;
		m=strlen(s);
		if(m%2==0) fout<<s<<" ";
		else 
			if(s[0]>s[m-1]) fout<<s<<" ";
			else
			{
				aux=s[0];
				s[0]=s[m-1];
				s[m-1]=aux;
				fout<<s<<" ";
			}
	}
	fin.close();
	fout.close();
	return 0;
}
	