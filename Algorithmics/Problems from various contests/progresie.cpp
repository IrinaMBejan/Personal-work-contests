#include <cstdio>
#define LGMAX 6000000
#define NMAX 20005
using namespace std;
FILE* fin=fopen("progresie.in","r");
FILE* fout=fopen("progresie.out","w");

bool sir[LGMAX];
int prog[NMAX];
int main()
{
    int N,i;
    fscanf(fin,"%d",&N);
    sir[3]=1;
    prog[1]=1;
    prog[2]=2;
    int nrm=2;

    int term=4;
    while(nrm<N)
    {
        while(sir[term]) term++;
        for(i=1; i<=nrm; i++)
            if(2*term-prog[i]<LGMAX)
                sir[2*term-prog[i]]=1;
        prog[++nrm]=term;
        sir[term++]=1;
    }
    for(i=1; i<=nrm; i++)
        fprintf(fout,"%d ",prog[i]);
    fprintf(fout,"\n");
    return 0;
}
