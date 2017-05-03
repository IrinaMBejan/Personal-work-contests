#include <cstdio>
#include<cstring>
#define NMAX 5001
using namespace std;
typedef short int NRMARE[NMAX];

FILE* fin=fopen("div.in","r");
FILE* fout=fopen("div.out","w");

int p[NMAX],z[NMAX],s[NMAX];
NRMARE x,maxc;
int nx,nmaxc;
void citire(NRMARE a, int& na);
void impartint(NRMARE a, int st, int fi, int b, int&rest);


int main()
{
    int M,i,q;
    fscanf(fin,"%d",&M);
    citire(x,nx);
    impartint(x,0,nx-1,M,q);
    if(q==0)
        fprintf(fout,"0 0\n");
    else
    {
        //restul impartirii la M a puterilor lui 10;
        z[0]=1;
        for(i=1; i<=nx; i++)
            z[i]=(z[i-1]*10)%M;
        for(i=0; i<nx; i++)
        {
            impartint(x,0,i,M,q);
            p[i]=q;
        }
        for(i=0; i<nx; i++)
        {
            impartint(x,i,nx-1,M,q);
            s[i]=q;
        }
        for(int lg=1; lg<=nx; lg++)
            for(i=0; i<=nx-lg; i++)
                if((p[i-1]*z[nx-i-lg]+s[i+lg])%M == 0)
                {
                    fprintf(fout,"%d %d\n",nx-i-lg+1,nx-i);
                    return 0;
                }
    }
    return 0;
}

void citire(NRMARE a, int& na)
{
    int i;
    char s[NMAX];
    fscanf(fin,"%s",s);
    na=strlen(s);
    for(i=na-1; i>=0; i--)
        a[i]=s[na-i-1]-'0';
}

void impartint(NRMARE a, int st, int fi, int b, int&rest)
{
    if(!b) return ;
    int i,t;
    for(t=0,i=fi; i>=st; i--)
    {
        t=t*10+a[i];
        t=t%b;
    }
    rest=t;
}
