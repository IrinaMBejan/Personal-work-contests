#include <cstdio>
#include<cstring>
using namespace std;
FILE* fin=fopen("momente.in","r");
FILE* fout=fopen("momente.out","w");

int luna[13]={0, 31,28,31,30,31,30,31,31,30,31,30,31};
char palin[1000][8];
char s[8];
char model[8]="195959";
int main()
{
    int ok=1,ok2,i,j,k,n=0;
    for(i=0;i<6;i++) s[i]=48;
    while(ok)
    {
        i=0;
        while(s[i]==48&&i<6) i++;

        ok2=1;
        for(k=i,j=5;k<j;k++,j--)
            if(s[k]!=s[j]) ok2=0;
        if(ok2)
        {
            strcpy(palin[++n],s);/*
            for(k=i;k<=5;k++)
                fprintf(fout,"%c",s[k]);
            fprintf(fout,"\n");*/
        }

        //generare urmatorul
        for(i=5;i>=0&&s[i]==model[i];i--) s[i]=48;
        if(i==-1&&model[0]=='1')
        {
            model[0]='2';
            model[1]='3';
            s[0]='2';
        }
        else if(i==-1) ok=0;
        else s[i]++;
    }
   /*fscanf(fin,"%d",&k);
    int nr,l,z;
    char h[8];
    for(j=1;j<=k;j++)
    {
        fscanf(fin,"%d %d",&l,&z);
        fscanf(fin,"%d", &nr);
        i=0;
        while(nr)
        {
            h[i++]==nr%10;
            nr/=10;
        }
        fscanf(fin,"%c%c %c%c",&h[i],&h[i+1],&h[i+2],&h[i+3]);

    }

*/
    return 0;
}
