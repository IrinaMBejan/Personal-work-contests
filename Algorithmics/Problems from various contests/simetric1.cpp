#include <cstdio>

using namespace std;
FILE* fin=fopen("simetric1.in","r");
FILE* fout=fopen("simetric1.out","w");

int M,N,a[401][401],SM[401][401],frecv[401];

int minim(int a, int b)
{
    if(a<b) return a;
    return b;
}

int main()
{
    fscanf(fin,"%d %d",&M,&N);
    int nr=0,j,i;
    for(i=1; i<=M; i++)
        for(j=1; j<=N; j++)
            fscanf(fin,"%d",&a[i][j]);

    int k;
    for (i = M; i; --i)
        for (j = N; j; --j)
        {
            for (k = 1; i+k <= M && j+k <= N && a[i+k][j] == a[i][j+k]; ++k);
            SM[i][j]=minim(SM[i+1][j+1]+1,k);
            if (SM[i][j] > nr)
                nr = SM[i][j];
            ++frecv[SM[i][j]];
        }

    for (i = nr-1; i; --i)
        frecv[i] += frecv[i+1];
    for (i = 1; i <=nr; ++i)
        fprintf(fout,"%d\n",frecv[i]);
    return 0;
}
