#include <cstdio>
#include<algorithm>
#include<cstring>
#define Nmax 248833
using namespace std;

FILE* fin=fopen("zimeria.in","r");
FILE* fout=fopen("zimeria.out","w");

int p, N;
int crt[30];
int frecv[Nmax];
char s[15];
int nr;
int factor = 12;
char cmin[6],cmax[6];
int vmin = Nmax, vmax=-1;
char cuv[6],rcuv[6];

int val(char *c)
{
    int Sum=0,p=1,i;
    for(i=4;i>=0;i--)
    {
        Sum+=p*crt[c[i]-'a'];
        p*=factor;
    }
    return Sum;
}

char* cuvant(int x)
{
  int i;
  rcuv[5]=0;
  for(i=4;i>=0;i--)
   {
       rcuv[i]=s[x%12];
       x/=12;
   }
   return rcuv;
}

int main()
{
    fscanf(fin,"%d",&p);
    fscanf(fin,"%d",&N);
    fscanf(fin,"%s",s);
    int i=0;
    for(i=0;i<12;i++)
        crt[s[i]-'a']=i;

    int va;
    for(i=1;i<=N;i++)
    {
        fscanf(fin,"%s",cuv);
        va=val(cuv);
        if(va>vmax) vmax=va;
        if(va<vmin) vmin=va;
        if(frecv[va]==0) nr++;
        frecv[va]++;
    }

    if(p==1)
        fprintf(fout,"%d\n",nr);
    else
    {
        int j;
        rcuv[5]=0;
        for(i=vmin;i<=vmax;i++)
             if(frecv[i]!=0)
             {
                strcpy(rcuv,cuvant(i));
                for(j=1;j<=frecv[i];j++)fprintf(fout,"%s\n",rcuv);
             }
    }
    return 0;
}
