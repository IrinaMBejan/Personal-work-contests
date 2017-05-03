#include <cstdio>

using namespace std;
FILE* fin=fopen("bile5.in","r");
FILE* fout=fopen("bile5.out","w");

int main()
{
    int n;
    fscanf(fin,"%d",&n);
    if(n%2==0)
    {
        int d1=n/2,s1=n/2+1, s2=(3*n+2)/2, d2=s2;
        while(s1<=n)
        {
            fprintf(fout,"%d %d\n",d1,s1);
            s1++;
            d1--;
            d2++;
            s2--;
            fprintf(fout,"%d %d\n",s2,d2);
        }
        fprintf(fout,"%d\n",(3*n+2)/2);
    }
    else
    {
            int d1=(n+1)/2,s1=(n+1)/2+1, s2=(3*n+2)/2+1, d2=s2;
            while(s1<=n)
            {
            fprintf(fout,"%d %d\n",d1,s1);
                s1++;
                d1--;
                d2++;
                s2--;
            fprintf(fout,"%d %d\n",s2,d2);
            }
            fprintf(fout,"%d %d\n",d1,s1);
           fprintf(fout,"%d\n",(3*n+2)/2+1);

    }

    return 0;
}
