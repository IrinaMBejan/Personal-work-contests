#include <cstdio>

using namespace std;
FILE* fin=fopen("dame.in","r");
FILE* fout=fopen("dame.out","w");

char a[9][9] = { {'.','n','.','n','.','n','.','n'}, {'n','.','n','.','n','.','n','.'}, {'.','n','.','n','.','n','.','n'}, {'-','.','-','.','-','.','-','.'},{'.','-','.','-','.','-','.','-'},{'a','.','a','.','a','.','a','.'}, {'.','a','.','a','.','a','.','a'},{'a','.','a','.','a','.','a','.'}};
char lin[9]={'a','b','c','d','e','f','g','h'};
int col[9]={8,7,6,5,4,3,2,1};

int main()
{
    int n,i,pin,pjn,pif,pjf;
    char iinit,jinit,ifin,jfin,mut,q;
    fscanf(fin,"%d\n",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(fin,"%c%c%c%c%c\n",&iinit,&jinit,&mut,&ifin,&jfin);
        pjn=col[jinit-49];
        pin=iinit-97;
        pif=ifin-97;
        pjf=col[jfin-49];
        if(mut=='-') {a[pif][pjf]=a[pin][pjn];a[pin][pjn]='-';}
        else
        {
            if(a[pin][pjn]=='n')
            {
                if(pif>pin&&pjf>pjn) a[pin+1][pjn+1]='-';
                if(pif>pin&&pjf<pjn) a[pin+1][pjn-1]='-';
                a[pif][pjf]=a[pin][pjn];a[pin][pjn]='-';
            }
            else if(a[pin][pjn]=='a')
            {
                if(pif<pin&&pjf<pjn) a[pin-1][pjn-1]='-';
                if(pif<pin&&pjf>pjn) a[pin-1][pjn+1]='-';
                a[pif][pjf]=a[pin][pjn];a[pin][pjn]='-';
            }
        }
    }
    return 0;
}
