#include <cstdio>

#define NMAX 1000001
#define qMax 1001

using namespace std;

FILE* fin=fopen("ausoara.in","r");
FILE* fout=fopen("ausoara.out","w");

int nr[NMAX], val[NMAX];
int N, M, i, j, x, valx, nrx;

int main()
{
    fscanf(fin,"%d",&N);
    for(i=1; i<NMAX; i++)
        nr[i]=qMax;
    for (i = 1; i <= N; i++)
    {
        fscanf(fin,"%d", &M);
        valx=nrx=0;
        for (j = 1; j <= M; j++)
        {
            fscanf(fin,"%d", &x);
            if (x == valx)
                nrx++;
            else
            {
                if (valx > 0&&val[valx] == i - 1)
                {
                    val[valx] = i;
                    if (nrx < nr[valx])
                        nr[valx] = nrx;
                }

                valx = x;
                nrx = 1;
            }
        }

        if (valx > 0&&val[valx] == i - 1)
        {
            val[valx] = i;
            if (nrx < nr[valx])
                nr[valx] = nrx;
        }
    }

    M = 0;
    for (i = 1; i < NMAX; i++)
        if (val[i] == N)
            M += nr[i];

    fprintf(fout,"%d ", M);
    for (i = 1; i < NMAX; i++)
        if (val[i] == N)
            for (j = 1; j <= nr[i]; j++)
                fprintf(fout,"%d ", i);
    fprintf(fout,"\n");
    return 0;
}
