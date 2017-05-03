#include <cstdio>

using namespace std;
FILE* fin=fopen("binremove.in","r");
FILE* fout=fopen("binremove.out","w");

int a[50005];
int main()
{
    int N,i,P,k,poz,s=0;
    fscanf(fin,"%d",&N);
    for(i=0;i<N;i++)
        fscanf(fin,"%d",&a[N-i-1]);
    fscanf(fin,"%d",&P);
    for(k=1;k<=P;k++)
        {
            fscanf(fin,"%d",&poz);
            s=0;
            a[poz]=0;
            for(i=0;i<poz;i++)
                  s+=a[i]*(i%2+1);
            for(i=poz;i<N;i++)
            {
                a[i]=a[i+1];
                s+=a[i]*(i%2+1);
            }
            if(s%3==0) fprintf(fout,"1\n");
            else fprintf(fout,"0\n");
        }
    return 0;
}
