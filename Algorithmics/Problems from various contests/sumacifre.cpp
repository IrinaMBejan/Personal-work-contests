#include <cstdio>
using namespace std;
FILE* fin=fopen("sumacifre.in","r");
FILE* fout=fopen("sumacifre.out","w");
int a[10];
int main()
{

    int n,k,p,s=0,nr=0;
    fscanf(fin,"%d %d",&n,&k);
    int c,m;
    while(nr<k)
    {
        p=1;
        c=n%10;
        m=0;
        if(n<10)
                m=c;
        else
        while(n>=10)
        {
            n/=10;
            if(c>n%10) m+=((c-n%10)*p);
            else m+=((n%10-c)*p);
            c=n%10;
            p*=10;
        }

        n=m;
        nr++;
        s+=n;
    }
    fprintf(fout,"%d\n",s);
    return 0;
}

/*
104
14
3
*/
