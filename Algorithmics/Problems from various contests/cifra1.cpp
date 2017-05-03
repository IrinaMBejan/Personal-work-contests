#include <cstdio>
#include<cstring>
using namespace std;
FILE* fin=fopen("cifra1.in","r");
FILE* fout=fopen("cifra1.out","w");
int main()
{
    char a[12];
    int n,nr=0,i;
    int k=0;
    fscanf(fin,"%s %d",&a,&n);
   // strrev(a);
    i=0;
    while(nr!=n)
    {

        nr++;
        if(k==a[i]-'0')
        {
            k=1;
            i++;
            if(a[i]-'0'==0) i++;
        }
        else k++;


    }
    fprintf(fout,"%d",a[i]-'0');
    return 0;
}
