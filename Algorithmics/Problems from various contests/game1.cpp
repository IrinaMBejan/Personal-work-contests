#include <cstdio>
#include <cstring>
#include <cstdlib>
#define DIM 460000

FILE *fin = fopen("game1.in","r");
FILE *fout = fopen("game1.out","w");


char V[DIM], U[DIM];
int N, log, i, j, ok, L, p, lpd, marc, a, b;

int main()
{
    fscanf(fin,"%d",&N);
    for (log = 1,i=1; log<N; log*=2,i++);
    fprintf(fout,"%d\n",i-1);

    log = i-1;

    L = 1;
    p = 1;
    V[N+1] = 2;
    for(; log; log--)
    {

        L = 1;
        p = 1;
        ok = 1;
        for (i=2; i<=N+1; i++)
            if (V[i] == V[i-1])
                L++;
            else
            {

                if (L>1)
                {

                    ok = 0;
                    marc = 1-V[p-1];
                    lpd = (L>>1);
                    a = p+lpd-1;
                    if (V[j]!=marc)
                        for (j=p; j<=a; j++)
                            V[j] = marc;
                    marc = 1-marc;
                    b = p+L-1;
                    if (V[p+lpd] != marc)
                        for (j=p+lpd; j<=b; j++)
                            V[j] = marc;
                }
                L = 1;
                p = i;
            }

        for (i=1; i<=N; i++)
        {
            if (V[i] && !U[i])
            {
                fprintf(fout,"%d ",i);
                if (V[i]!=V[i-1] && V[i]!=V[i+1])
                    U[i] = 1;
            }
        }
        fprintf(fout,"0\n");
    }
    return 0;
}
