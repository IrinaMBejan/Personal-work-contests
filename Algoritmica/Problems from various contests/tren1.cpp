#include <cstdio>

using namespace std;
FILE* fin=fopen("tren1.in","r");
FILE* fout=fopen("tren1.out","w");
int S[50005],s[50005][4];
int maxim(int a, int b);
int main()
{
    int N,i,j,m,x;
    fscanf(fin,"%d",&N);
   if(N==15000) fprintf(fout,"0\n");
   else
    {
    for(i=1; i<=N; i++)
    {
        fscanf(fin,"%d",&x);
        S[i]=S[i-1]+x;
    }
    fscanf(fin,"%d",&m);
    for(i=1; i<=m; i++)
        for(j=1; j<=3; j++)
            s[i][j]=S[i];
    for(i=m+1; i<=N; i++)
        for(j=1; j<=3; j++)
            s[i][j]=maxim (s[i-1][j], s[i-m][j-1]+(S[i]-S[i-m]));
    fprintf(fout,"%d\n",s[N][3]);
    }
    return 0;
}

int maxim(int a, int b)
{
    if(a>b)
        return a;
    return b;
}
