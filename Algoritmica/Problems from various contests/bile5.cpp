#include <cstdio>

using namespace std;
FILE* fin=fopen("bile5.in","r");
FILE* fout=fopen("bile5.out","w");
int n;

int main()
{
    fscanf(fin,"%d",&n);
    int d1=n/2,s1=n/2+1, s2=(3*n+2)/2, d2=s2;
    while(s1!=n)
    {
        fprintf(fout,"%d %d\n",d1,s1);
        s1++; d1--;
        d2++; s2--;
        fprintf(fout,"%d %d\n",s2,d2);
    }
    return 0;
}
