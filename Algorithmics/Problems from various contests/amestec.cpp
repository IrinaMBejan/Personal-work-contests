#include <fstream>
#include<cstring>
#include<cstdlib>
using namespace std;
ifstream fin("amestec.in");
ofstream fout("amestec.out");

int n;
char s[105][105], sir[30];

void nord (int  d,char m)
{
    int min, i, j, t;
    if(d>=n)
        d=n-1;
    for(t=1; t<=d; t++)
        for(j=0; j<n; j++)
        {
            for(i=n-1; i>0; i--)
                if(s[i][j]==m&&s[i][j]+s[i-1][j]=='0'+'1')
                    s[i-1][j]=m, s[i][j]='0'+'1'-m,i--;
        }
}

void est (int  d,char  m)
{
    int min, i, j, t;
    if(d>=n)d=n-1;
    for(t=1; t<=d; t++)
        for(i=0; i<n; i++)
            for(j=0; j<n-1; j++)
                if(s[i][j]==m&&s[i][j]+s[i][j+1]=='0'+'1')
                    s[i][j+1]=m, s[i][j]='0'+'1'-m,j++;
}

void vest (int  d,char  m)
{
    int min, i, j, t;
    if(d>=n)d=n-1;
    for(t=1; t<=d; t++)
        for(i=0; i<n; i++)
            for(j=n-1; j>0; j--)
                if(s[i][j]==m&&s[i][j]+s[i][j-1]=='0'+'1')
                    s[i][j-1]=m, s[i][j]='0'+'1'-m,j--;
}

void sud (int  d,char  m)
{
    int min, i, j, t;
    if(d>=n)d=n-1;
    for(t=1; t<=d; t++)
        for(j=0; j<n; j++)
            for(i=0; i<n-1; i++)
                if(s[i][j]==m&&s[i][j]+s[i+1][j]=='0'+'1')
                    s[i+1][j]=m, s[i][j]='0'+'1'-m,i++;
}

int main()
{
    int k,i,j,lg;
    fin>>n>>k;
    for(i=0; i<n; i++)
        fin>>s[i];
    for(i=1; i<=k; i++)
    {
        fin>>sir;
        int val;
        lg=strlen(sir);
        char w=sir[lg-1],dir=sir[lg-2];
        sir[lg-2]=0;
        val=atoi(sir);

        if(dir=='N') nord(val,w);
        else if(dir=='S') sud(val,w);
        else if(dir=='E') est(val,w);
        else  vest(val,w);
    }
    for(i=0; i<n; i++)
        fout<<s[i]<<'\n';
    return 0;
}
