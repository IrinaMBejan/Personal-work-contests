#include <cstdio>
#include <cstring>
#define Nmax 50
#define Mmax 20
#define Xmax 64
#define INF 0x3f3f
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

FILE* fin=fopen("zidar.in","r");
FILE* fout=fopen("zidar.out","w");

int N, M, X, T, Res;
int a[Nmax][Mmax];
int bst[Mmax][Mmax][Xmax], tmp[Mmax][Mmax][Xmax];

int main()
{
    int i, j, k, x, len, pos, sum;

    fscanf(fin, "%d %d %d %d", &N, &M, &X, &T);

    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
                fscanf(fin,"%d",&a[i][j]);

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
            for (k = j, sum = a[i][j]; k < M; k++, sum += a[i][k])
                for (x = i+k-j+1; x <= X && x <= i*M+k-j+1; x++)
                {
                    bst[j][k][x] = INF;
                    int &p = bst[j][k][x];
                    for (pos = 0; pos <= k; pos++)
                    {
                        len = pos < j ? j-pos : 0;
                        p = min(p, tmp[pos][len][x-(k-j+1)]+sum);
                        if (p <= T && Res < x) Res = x;
                    }
                }

        if (!i) memset(tmp, 0x3f, sizeof(tmp));

        for (j = 0; j < M; j++)
            for (len = 0; len < M; len++)
                for (x = i+1; x <= X && x <= (i+1)*M; x++)
                {
                    tmp[j][len][x] = INF;
                    int &p = tmp[j][len][x];
                    for (k = j+len; k < M; k++)
                        if (x >= i+k-j+1 && x <= i*M+k-j+1)
                            p = min(p, bst[j][k][x]);
                }
    }
    fprintf(fout, "%d\n", Res);

    return 0;
}
