#include <cstdio>
#define NMAX 100000
using namespace std;
FILE* fin=fopen("pachete.in","r");
FILE* fout=fopen("pachete.out","w");

int castig[NMAX];
int main()
{
    int N,i,a,b,max=0,Tminnou,Tminvechi=0;
    fscanf(fin,"%d",&N);
    for(i=1;i<=N;i++)
    {
        fscanf(fin,"%d %d",&castig[i],&b);
        Tminnou=b+Tminvechi-castig[i-1];
        if(Tminnou>max) max=Tminnou;
        Tminvechi=Tminnou;
    }
    fprintf(fout,"%d\n",max);
    return 0;
}
