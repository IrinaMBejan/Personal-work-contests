#include<fstream>
#include<algorithm>


using namespace std;
ifstream fin("nkd.in");
ofstream fout("nkd.out");
int a[20001], n, k, d, r;
char s[20001];
int t[14];
long long rez;

int main()
{
	int i, q;
	fin>>s;
	fin>>k;
	fin>>d;
	for (i=0; s[i]; i++)
		a[i+1] = s[i] - '0';
	n = i;

	r = 0;
	for (i =1; i<=n-k; i++)
	{
		r=r*10+a[i];
		q=r/d;
		r=r-q*d;
	}

	int j, gata, aux;
	j=1;
	for (i=n- k+1; i<=n; i++)
		t[j++]=a[i];
	sort(t+1, t+k+1);

	gata=0;
	t[0]=-1;
	while (!gata)
	{
		rez=r;
		for (i=1; i<=k; i++)
			rez=rez*10 + t[i];
		if (rez%d==0)
		{
			for (i =1; i<=n-k; i++)
				fout<<a[i];
			for (i =1; i<=k; i++)
				fout<<t[i];
			fout<<"\n";
			return 0;
		}
		i=k - 1;
		while (t[i]>=t[i + 1]) i--;
		if (i==0) gata=1;
		else
		{
			for (j=i+1; t[j]>t[i]; j++) ;
			j--;
			aux=t[i];
			t[i]=t[j];
			t[j]=aux;
			sort(t+i+1, t+k+1);
		}
	}
	fout<<"-1\n";
	return 0;
}
