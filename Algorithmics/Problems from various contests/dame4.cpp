#include <fstream>
#include<string.h>
#include<math.h>
using namespace std;
ifstream fin("dame.in");
ofstream fout("dame.out");

char a[9][9] = { {'.','n','.','n','.','n','.','n'}, {'n','.','n','.','n','.','n','.'}, {'.','n','.','n','.','n','.','n'}, {'-','.','-','.','-','.','-','.'},{'.','-','.','-','.','-','.','-'},{'a','.','a','.','a','.','a','.'}, {'.','a','.','a','.','a','.','a'},{'a','.','a','.','a','.','a','.'}};
int lin[9]={8,7,6,5,4,3,2,1};
char s[52],mut;
int main()
{
    int n,i,lini,coli,linf,colf;

    fin>>n; int k;
    for(i=1;i<=n;i++)
    {
        fin.get();
        fin.get(s,52);
        coli=s[0]-97;
        lini=lin[s[1]-48];
        mut=s[2];
        colf=s[3]-97;
        linf=lin[s[4]-48];
        if(mut=='-'&&a[linf][colf]=='-'&&a[lini][coli]!='-'&&a[lini][coli]!='.'&&fabs(lini-linf)==1&&fabs(coli-colf)==1)
            {a[linf][colf]=a[lini][coli];a[lini][coli]='-';}
        else
        {
            if(a[linf][colf]=='-'&&a[lini][coli]!='-'&&a[lini][coli]!='.'&&fabs(lini-linf)==2&&fabs(coli-colf)==2)
            {
            if(linf>lini&&colf>coli) a[lini+1][coli+1]='-';
            if(linf>lini&&colf<coli) a[lini+1][coli-1]='-';
            if(linf<lini&&colf<coli) a[lini-1][coli-1]='-';
            if(linf<lini&&colf>coli) a[lini-1][coli+1]='-';
            a[linf][colf]=a[lini][coli];a[lini][coli]='-';
            }
            k=5;
            while(s[k]==':')
            {
                lini=linf;
                coli=colf;
                colf=s[++k]-97;
                linf=lin[s[++k]-48];
           if(a[linf][colf]!='a'&&a[linf][colf]!='n'&&a[lini][coli]!='-'&&a[lini][coli]!='.'&&fabs(lini-linf)==2&&fabs(coli-colf)==2)
            {
            if(linf>lini&&colf>coli) a[lini+1][coli+1]='-';
            if(linf>lini&&colf<coli) a[lini+1][coli-1]='-';
            if(linf<lini&&colf<coli) a[lini-1][coli-1]='-';
            if(linf<lini&&colf>coli) a[lini-1][coli+1]='-';
            a[linf][colf]=a[lini][coli];a[lini][coli]='-';
            }
                k++;
            }
            for(k=0;k<strlen(s);k++)
                s[k]=0;
        }
    }
    int j;
    for(i=0;i<=7;i++)
    {
        for(j=0;j<=7;j++)
            fout<<a[i][j];
       fout<<'\n';
    }
    return 0;
}
