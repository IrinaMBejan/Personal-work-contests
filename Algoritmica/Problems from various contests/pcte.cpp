#include <cstdio>
#define NMAX 1001
using namespace std;
FILE* fin = fopen("puncte.in","r");
FILE* fout = fopen("puncte.out","w");

bool Po[NMAX][NMAX];
int Vy[NMAX],Vx[NMAX];
int N,M;
int C[NMAX][NMAX];
int nrmin[NMAX][NMAX];
void Citire();

int main()
{
    Citire();
    int xn,yn, sumx=0, sumy=0, pozcaut = (N*N-M)/2+(N*N-M)%2;

    for(xn=0;xn<N && sumx <= pozcaut; xn++)
        sumx+=N-Vx[xn];
    xn--;

    for(yn=0;yn<N && sumy <= pozcaut; yn++)
        sumy+=N-Vy[yn];
    yn--;

    Po[xn][yn] = 1;


    return 0;
}
//max ( (max(xi+yi)-min(xi+yi)), (max(xi-yi) - min(xi-yi)) )

void Citire()
{
    int x,y;
    fscanf(fin,"%d %d",&N,&M);
    for(int i = 1; i<=M; i++)
    {
        fscanf(fin,"%d %d",&x,&y);
        Vy[y]++;
        Vx[x]++;
        Po[x][y]=1;
    }
}

void Calculeaza()
{
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if(Po[i][j])
            {
                if(i+j>summax)
                {
                    summax = i+j;
                    xsummax = i;
                    ysummax = j;
                }
                if(i-j>difmax)
                {
                    difmax = i-j;
                    xdifmax = i;
                    ydifmax = j;
                }
            }
            else
            {
                if(i+j<summin)
                {
                    summin = i+j;
                    xsummin = i;
                    ysummin = j;
                }
                if(i-j<difmin)
                {
                    difmin = i-j;
                    xdifmin = i;
                    ydifmin = j;
                }
            }
}
