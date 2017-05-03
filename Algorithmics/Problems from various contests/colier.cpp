#include <cstdio>
#define NMAX 100005
using namespace std;
FILE* fin = fopen("colier.in","r");
FILE* fout = fopen("colier.out","w");

char s[NMAX];
int main()
{
    int T,N,i,ok,r,n;
    fscanf(fin,"%d",&T);
    while(T--)
    {
        r = n = 0;
        fscanf(fin,"%d %s",&N,&s);

        for(i=0;i<N;i++)
            if(s[i] == '0')
                r++;
            else
                n++;
        ok = 1;
        if(N==1)
        {
            if(r == 1)
                ok = 0;
        }
        else
        if(n == 0)
            ok = 0;
        else if(r%2 == 0)
            ok = 0;

        if(ok)
            fprintf(fout,"DA\n");
        else fprintf(fout,"NU\n");

    }
    return 0;
}
