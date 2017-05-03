#include <cstdio>
#include<cstring>
using namespace std;
FILE* fin=fopen("exp.in","r");
FILE* fout=fopen("exp.out","w");

int max(int a);
int min(int a);
char s[64001];
int main()
{
    int n,e,i,x,y;
    fscanf(fin,"%d\n%s",&n,&s);
    e=0;
    for(i=0;i<n;i++)
            {
                fscanf(fin,"%d %d",&x,&y);
                if(s[i]=='-')
                    e=e-min(x)*min(y);
              else
                    e=e+max(x)*max(y);
            }
    fprintf(fout,"%d\n",e);

    return 0;
}


int min(int a)
{
    int m=a%10;
    while(a>0)
    {
        a/=10;
        if(a%10<m&&a!=0) m=a%10;
    }
    return m;
}

int max(int a)
{
    int m=a%10;
    while(a>0)
    {
        a/=10;
        if(a%10>m&&a!=0) m=a%10;
    }
    return m;
}
