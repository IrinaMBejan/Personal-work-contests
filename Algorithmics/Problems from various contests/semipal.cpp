#include <cstdio>
#define Nmax 65
using namespace std;
FILE* fin=fopen("semipal.in","r");
FILE* fout=fopen("semipal.out","w");
long long int T,n;
long long int k;
char s[65];
int main()
{
    fscanf(fin,"%lld",&T);
    long long int nrc;
    int i;
    while(T)
    {
        fscanf(fin,"%lld %lld",&n,&k);
        nrc=1<<(n-2);
        if(k<=nrc)
        {
            k--;
            fprintf(fout,"a");
            for(i=n-3; i>=0; i--)
            {
                if(k%2==0)
                    s[i]='a';
                else
                    s[i]='b';
                k/=2;
            }
            s[n-2]=0;
            fprintf(fout,"%s",s);
            fprintf(fout,"a");
        }
        else if(k<=2*nrc)
        {
            fprintf(fout,"b");
            k-=nrc;
            k--;
            for(i=n-3; i>=0; i--)
            {
                if(k%2==0)
                    s[i]='a';
                else
                    s[i]='b';
                k/=2;
            }
            s[n-2]=0;
            fprintf(fout,"%s",s);
            fprintf(fout,"b");
        }
        fprintf(fout,"\n");
        --T;
    }
}
