#include <cstdio>
#include <cstring>
#define INF -10000
#define MAX(x,y) ((x)>(y)?(x):(y))
#define Lgmax 2005
using namespace std;
FILE* fin=fopen("suma2.in","r");
FILE* fout=fopen("suma2.out","w");

int N;
char s[Lgmax];
int smax[5][505];
int num[Lgmax];
int main()
{
    char nr[10];
    fscanf(fin,"%d",&N);
    int i;
    for(i=1; i<=N; i++)
    {
        fscanf(fin,"%s",nr);
        strcat(s,nr);
    }
    for(i=0; s[i]; i++)
        num[i+1]=s[i]-'0';
    int Lg = i;

    int laa=0, la=1, lp=2, lc=3;
    int p,n;

    for(n=0; n<=N; n++)
        smax[0][n]=smax[1][n]=smax[2][n]=smax[3][n]=INF;
    smax[lp][0]=0;
    int aux,n1;
    for(p=1; p<=Lg; p++)
    {
        for(n=1; n<=N; n++)
        {
            if(n<=p)
            {
                if(num[p]!=0 && smax[lp][n-1]!=INF)
                    smax[lc][n]=MAX(smax[lc][n],(smax[lp][n-1]+num[p]));
                if(p>1 && num[p-1]!=0 && smax[la][n-1]!=INF)
                    smax[lc][n]=MAX(smax[lc][n],(smax[la][n-1]+num[p-1]*10+num[p]));
                if(p>2 && num[p-2]!=0 && smax[laa][n-1]!=INF)
                    smax[lc][n]=MAX(smax[lc][n],(smax[laa][n-1]+num[p-2]*100+num[p-1]*10+num[p]));

            }
        }
        if(p>3) smax[lc][0]=INF;
        aux = laa;
        laa=la;
        la=lp;
        lp=lc;
        lc=aux;
        for(n1=1;n1<=N;n1++)
            smax[lc][n1]=INF;
    }
fprintf(fout,"%d\n",smax[lp][N]);
return 0;
}
