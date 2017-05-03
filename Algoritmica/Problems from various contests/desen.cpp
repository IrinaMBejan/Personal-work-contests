#include <cstdio>
#define NMAX 1002
using namespace std;
FILE* fin=fopen("desen1.in","r");
FILE* fout=fopen("desen1.out","w");

int a[NMAX][NMAX],b[NMAX][NMAX],n,m;
int verif(int i, int j);
int main()
{
    int i,j;
    fscanf(fin,"%d %d",&n,&m);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            fscanf(fin,"%d",&a[i][j]);

    for(i=2; i<n; i++)
        for(j=2; j<m; j++)
            if(verif(i,j)!=a[i-1][j])
                b[i][j]=1-b[i-1][j];
            else
                b[i][j]=b[i-1][j];

    for(i=1; i<=n; i++)
    {
        fprintf(fout,".");
        for(j=2; j<=m; j++)
        {
            if(b[i][j-1]!=b[i][j])
                fprintf(fout,"|");
            else
                fprintf(fout,".");
            if(b[i+1][j]!=b[i][j])
                fprintf(fout,"_");
            else
                fprintf(fout,".");
        }
        fprintf(fout,"\n");
    }
    return 0;
}

int verif(int i,int j)
{
	int c=0;

	if(b[i-1][j]+b[i-1][j-1]==1) c++;
	if(b[i-1][j]+b[i-2][j]==1) c++;
	if(b[i-1][j]+b[i-1][j+1]==1) c++;
	return c;
}
