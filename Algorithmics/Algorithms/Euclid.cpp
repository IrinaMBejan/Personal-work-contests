#include <cstdio>

using namespace std;

FILE* fin=fopen("cmmdc.in","r");
FILE* fout=fopen("cmmdc.out","w");
int cmmdc(int a, int b);

int main()
{
    int a,b;
    fscanf(fin,"%d %d",&a,&b);
    int k=cmmdc(a,b);
    if(k>1)fprintf(fout,"%d\n",cmmdc(a,b));
    else fprintf(fout,"0\n");
    return 0;
}

int cmmdc(int a, int b)
{

    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;

}
