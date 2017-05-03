#include <cstdio>
#include<math.h>
using namespace std;
FILE *fin=fopen("prieten.in","r");
FILE*  fout=fopen("prieten.out","w");

int main()
{
    int n,i,k;
    long long int S;
    fscanf(fin,"%d %d",&n,&k);
    for(i=1;i<=k;i++)
        fprintf(fout,"%lld ",(long long int)
                i*(n+1));
    fscanf(fin,"%lld",&S);
    long long int p=sqrt((double)2*S);
    for(i=1;i<=p;i++)
        if((long long int)i*(i-1)*(i+1)==2*S)
            break;
   fprintf(fout,"\n%d\n",i);
    return 0;
}
