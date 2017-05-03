#include<cstdio>
using namespace std;

FILE* fin=fopen("sstabil.in","r");
FILE* fout=fopen("sstabil.out","w");
int a[1000005],b[1000005];
int n,i,j,r,p,k,s,t;

int main()
{
	fscanf(fin,"%d\n",&n);
	for (i=1;i<=n;i++)
		fscanf(fin,"%d",&a[i]);
	a[0]=9; a[n+1]=9; b[0]=9;//asiguram capetele
	k=0; r=n;//incepem sa cautam de la ultima pozitie si nu avem momentan nici o cifra in vec solutie
	while (r>0)
	{
		j=r;  s=0;
		do
		{
			s=s+a[j];
			j--;
		}
		while (s<10);

        p=r; t=a[p];    //luam drept solutie ultimul element neparcurs

		while (s-t>9 || t+b[k]<10) //daca acesta "reactioneaza" cu ultima cifra din solutie sau termenul urm e mai mare ca 9
		{
			p--;
			t=t+a[p];
		}
		k++;
		b[k]=t;
		r=p-1;
	}
	for (i=k;i>=1;i--)
        fprintf(fout,"%d",b[i]);
    fprintf(fout,"\n");
	return 0;
}

