#include <cstdio>
#include<cmath>
#include<cstring>
using namespace std;
FILE* fin=fopen("cuvinte2.in","r");
FILE* fout=fopen("cuvinte2.out","w");

int cuv1[58],cuv2[58];
char s1[1001],s2[1001];
int main()
{
    int max=0,i,nr1=0,nr2=0;
    fscanf(fin,"%s",&s1);
    fscanf(fin,"%s",&s2);
    for(i=0; i<strlen(s1); i++)
        cuv1[s1[i]-'A']++;
    for(i=0; i<strlen(s2); i++)
        cuv2[s2[i]-'A']++;
    for(i=0; i<=26; i++)
    {
        if(cuv1[i]+cuv2[i]+cuv1[i+32]+cuv2[i+32]>max) max=cuv1[i]+cuv2[i]+cuv1[i+32]+cuv2[i+32];
        if(cuv1[i]+cuv1[i+32]!=cuv2[i]+cuv2[i+32]) nr1+=fabs((double)cuv1[i]+cuv1[i+32]-cuv2[i]-cuv2[i+32]);
    }
    fprintf(fout,"%d\n%d\n",max,nr1);
    i=0;
    while(s1[i]==s2[i]&&i<strlen(s1)&&i<strlen(s2))
        i++;
    if(i==strlen(s1))
        fprintf(fout,"%d\n",strlen(s1));
    else   if(i==strlen(s2))
        fprintf(fout,"%d\n",strlen(s2));
    else fprintf(fout,"0\n");
    return 0;
}
