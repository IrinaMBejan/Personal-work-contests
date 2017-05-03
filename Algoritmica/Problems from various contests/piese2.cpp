#include <cstdio>
#define NMAX 100005
using namespace std;
FILE* fin = fopen("piese2.in","r");
FILE* fout = fopen("piese2.out","w");

int T,N,K,sp;
int blue[NMAX],red[NMAX];
int main()
{
    int i;
    fscanf(fin,"%d %d %d",&T,&N,&K);
    while(T--)
    {
        sp = 0;
        for(i = 1; i<=K;i++)
            fscanf(fin,"%d",&red[i]);
        for(i=1;i<=K;i++)
        {
            fscanf(fin,"%d",&blue[i]);
            if(i!=K)
                sp += (red[i+1] - blue[i] -1);
        }
        sp+=red[1] - 1;
        sp+=N - blue[K];
        if(sp%2 == 0)
            fprintf(fout,"Aglaia\n");
        else
            fprintf(fout,"Miruna\n");
    }
    return 0;
}
