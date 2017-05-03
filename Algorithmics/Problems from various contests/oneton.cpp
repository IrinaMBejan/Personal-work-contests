#include <cstdio>
#include<cmath>
using namespace std;
FILE*fin=fopen("oneton.in","r");
FILE* fout=fopen("oneton.out","w");


int main()
{
    int n,poz,s=0,nri,k,p=0;
    fscanf(fin,"%d",&n);
    poz=2;
    nri=1;
    do
    {
        if(poz<=n)
            poz=(poz-1)*2+1;
        else
        {
            k=2*n-poz;
            poz=k*2+2;
            nri=poz-1;
        }
        p++;
    }while(poz!=2);
    fprintf(fout,"%d\n",p);
    return 0;
}
