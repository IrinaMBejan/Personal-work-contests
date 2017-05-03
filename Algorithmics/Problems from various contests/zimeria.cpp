//solutia de 90 de pct

#include <cstdio>
#include<algorithm>
#include<cstring>
#define Nmax 400005
using namespace std;
FILE* fin=fopen("zimeria.in","r");
FILE* fout=fopen("zimeria.out","w");

int p, N;
int crt[30];
char s[15];
int nr;
struct cuvant
{
    char p[6];
}cuv[Nmax];

int comp(cuvant a, cuvant b)
{
    int i;
    for(i=0; a.p[i]!='\0'&& b.p[i]!='\0'; i++)
    {
        if(crt[a.p[i]-'a']<crt[b.p[i]-'a']) return 1;
        if(crt[a.p[i]-'a']>crt[b.p[i]-'a']) return 0;
    }
}
int main()
{
    fscanf(fin,"%d",&p);
    fscanf(fin,"%d",&N);
    fscanf(fin,"%s",s);
    int i=0;
    for(i=0;i<12;i++)
        crt[s[i]-'a']=i;
    for(i=1;i<=N;i++)
        fscanf(fin,"%s",cuv[i].p);
    sort(cuv+1,cuv+N+1,comp);
    int st;
    if(p==1)
    {
    nr=0;
    i=1;
    while(i<=N)
    {
        nr++; st=i;
        while(strcmp(cuv[i].p,cuv[st].p)==0) i++;
    }
    fprintf(fout,"%d\n",nr);
    }
    else
    {
        for(i=1;i<=N;i++)
            fprintf(fout,"%s\n",cuv[i].p);
    }
    return 0;
}
