#include <cstdio>
using namespace std;
#define MAXN 10011

FILE* fin=fopen("aranjare.in","r");
FILE* fout=fopen("aranjare.out","w");

int n, sp;
char s[MAXN];


void muta(int k)
{
	fprintf(fout,"%d\n", k + 1);
	s[sp]=s[k];
    s[sp+1]=s[k+1];
	s[k]=s[k+1]='S';
	sp=k;
}

void mutare(int k)
{
	if (s[k + 1]!='S')
		muta(k);
	else
	{
		muta(2*n);
		muta(k);
	}

	int i;
	for (i=k+1; i<2*n+2; i++)
		if (s[i]=='F')
			break;
	if (i!=2*n+1)
		muta(i);
	else
	{
		muta(2 * n);
		muta(k + 2);
		muta(k - 1);
		muta(k + 1);
	}
}


int main()
{
    int i,lim;
    fscanf(fin, "%d", &n);
	fscanf(fin, "%s", s);
	lim=2*n+2;
    for (i=0; i<lim; i++)
        if(s[i]=='S')
        {
            sp=i;
            break;
        }

    for (i=0; i<n; i++)
		if (s[i]!= 'F')
			mutare(i);
	if (s[n]!='S')
		muta(n);
	return 0;
}
