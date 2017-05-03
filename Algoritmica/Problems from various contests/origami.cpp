#include <fstream>
#define LGMAX 175
using namespace std;

ifstream fin("origami.in");
ofstream fout("origami.out");
int F[LGMAX][LGMAX];
void indoire(int &n, int &m, int tip,int lin);
int maxim(int n,int m);

int main()
{
	int N,M,Nr,Tip,Lin,Max, i,j;
	fin>>N>>Nr;
	M = N;
	for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
            F[i][j] = 1;
    for(i=1;i<=Nr;i++)
	{
		fin>>Tip>>Lin;
		indoire(N,M,Tip,Lin);
	}
	fout<<N<<" "<<M<<" "<<maxim(N,M)<<'\n';
    return 0;
}

int maxim(int n,int m)
{
    int i,j,max=-1;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(F[i][j]>max) max=F[i][j];
    return max;
}

void indoire(int &n, int &m, int tip,int lin)
{
    int i,j,r,ca,t,k;
    if(tip==1)
    {
        if(2*lin>m)
        {
            ca=m-lin;
            r=lin-ca;
        }
        else
        {
            ca=lin;
            r=0;
        }
        for(k=r;k>=1;k--)
			for(i=1;i<=n;i++)
			{
				t = F[i][k];
				for(j=k;j<m;j++) F[i][j] = F[i][j+1];
				F[i][m] = t;
			}
        for(j=1;j<=ca;j++)
			for(i=1;i<=n;i++)
                F[i][2*ca-j+1] += F[i][j];
        for(i=1;i<=n;i++)
			for(j=1;j<=m-ca;j++)
                F[i][j] = F[i][j+ca];
        m-=ca;
    }
    else
    {
        if(2*lin>n)
        {
            ca=n-lin;
            r=lin-ca;
        }
        else
        {
            ca=lin;
            r=0;
        }
        for(k=r;k>=1;k--)
            for(i=1;i<=m;i++)
        {
            t=F[k][i];
            for(j=k;j<n;j++) F[j][i]=F[j+1][i];
            F[n][i]=t;
        }
        for(i=1;i<=ca;i++)
            for(j=1;j<=m;j++)
                F[2*ca-i+1][j]+=F[i][j];
        for(i=1;i<=n-ca;i++)
            for(j=1;j<=m;j++)
                F[i][j]=F[i+ca][j];
        n-=ca;
    }
}
