#include <cstdio>
#define NMAX 55
#define INF 10010
using namespace std;
FILE* fin = fopen("rfinv.in","r");
FILE* fout = fopen("rfinv.out","w");

int mat[NMAX][NMAX],m[NMAX][NMAX];


int main()
{
    int N,M,j,i,a,b;
    int T;
    fscanf(fin,"%d",&T);
    while(T--)
    {
        fscanf(fin,"%d %d",&N,&M);

        for(i=1;i<=N;i++)
            for(j=1;j<=N;j++)
                m[i][j] = INF;

        for(i=1; i<=M; i++)
        {
            fscanf(fin,"%d %d",&a,&b);
            m[a][b] = 1;
            m[b][a] = 1;
        }

        for(i=1; i<=N; i++)
            for(j=1; j<=N; j++)
                fscanf(fin,"%d",&mat[i][j]);

        for(i=1; i<=N; i++)
            for(j=1; j<=N; j++)
                if(m[i][j])
                {
                    m[i][j] = mat[i][j];
                }

        for(int z = 1; z<=N; z++ )
            for(i = 1; i<=N; i++)
                for(j=1; j<=N; j++)
                    if(m[i][j] > m[i][z] + m[z][j])
                        m[i][j] = m[i][z] + m[z][j];

        bool ok = true;
        for(i=1; i<=N; i++)
            for(j=1; j<=N; j++)
                if(m[i][j] != mat[i][j])
                    ok = false;

        if(ok) fprintf(fout,"DA\n");
        else fprintf(fout,"NU\n");
    }
    return 0;
}
