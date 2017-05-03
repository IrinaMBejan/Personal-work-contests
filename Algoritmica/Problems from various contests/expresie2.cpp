#include <fstream>
#include <string>
#include<cstdlib>
#define nmax 100001

using namespace std;
ifstream fin("expresie2.in");
ofstream fout("expresie2.out");

string s,s1;
int i, poz;
char sym;
int ok[150];

string init(string s)
{
	string s1;
	int i, len = s.size();
	for (i=0;i<len;i++)
		if (s[i]>='a' && s[i]<='z')
		{
			s1 = s1 + s[i] + "+1";
			ok[s[i]] = 0;
		}
		else
			s1 = s1+s[i];
	return s1;
}

string transform(string s)
{
	short int ct[150];
	int i,j,len,semn=1,numar=0,semnnum;
	string s1;
	char sym,buf[10];

	for (i='a';i<='z';i++)
		ct[i]=0;

	len = s.size();
	for(i=0;i<len;i++)
	{
		if (s[i]=='-')
			semnnum=-1;
		if (s[i]=='+')
			semnnum=+1;
		if (s[i]=='/')
		{
			ct[sym] += semn*semnnum*numar;
			semn = -1;
			numar=0;
		}
		if (s[i]=='*')
		{
			ct[sym] += semn*semnnum*numar;
			semn = +1;
			numar=0;
		}
		if (s[i]<='z' && s[i] >='a')
		{
			ct[sym] += semn*semnnum*numar;
			numar=0;
			sym = s[i];
		}
		if (s[i]>='0'&&s[i]<='9')
			numar = 10*numar + (s[i]-48);
	}
	ct[sym] += semn*semnnum*numar;
	for (sym='a';sym<='z';sym++)
		if (ct[sym]!=0)
		{
		s1 = s1 + sym;
		sprintf(buf,"%d",ct[sym]);
		if (ct[sym] >= 0)
			s1 = s1 + '+' + buf;
		else
			s1=s1+buf;
		}
	return s1;
}


int main()
{

	for (i=0;i<150;i++)
		ok[i] = -1000000000;
	fin >> s;
	s = init(s);
	while ((poz = s.find(')')) >=0)
	{
		for(i=poz-1;i>=0;i--)
			if (s[i]=='(' )
				break;
		s1 = s.substr(i+1,poz-1-(i+1)+1);
		s1 = transform(s1);
		s.erase(i,poz-i+1);
		s.insert(i,s1);
	}

	s = transform(s);


	int len = s.size();
	int numar = 0;
	int semn;
	for (i=0;i<len;i++)
	{
		if (s[i]>='a' && s[i] <='z')
		{
			ok[sym] = semn*numar;
			numar=0;
			sym = s[i];
		}
		if (s[i]=='+')
			semn = +1;
		if (s[i]=='-')
			semn=-1;
		if (s[i]>='0' && s[i] <='9')
			numar = 10*numar + (s[i]-48);
	}
	ok[sym] = semn*numar;

	for (sym='a';sym<='z';sym++)
		if (ok[sym]>-1000000000)
			fout << sym << ' ' << ok[sym] << endl;
	return 0;
}
