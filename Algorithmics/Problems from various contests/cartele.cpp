#include <cstdio>
#include<algorithm>
#define LG 51
using namespace std;
FILE* fin=fopen("cartele.in","r");
FILE* fout=fopen("cartele.out","w");

int car[LG][LG],aux[LG][LG],act[LG][LG];
int n,k;
int verif();
void oglind();
void rot()
{
    int i, j;
    for (i = 1; i <= n; i++)
        for (j = 1; j<= n; j++)
            aux[n-j+1][i] = car[i][j];

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            car[i][j] = aux[i][j];
}

int main()
{
    int i,j,q;
    fscanf(fin,"%d %d",&n,&k);
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            fscanf(fin,"%d",&car[i][j]);
    for(q=1; q<=k; q++)
    {
        int ok=1;
        for(i=1; i<=n; i++)
            for(j=1; j<=n; j++)
            {
                fscanf(fin,"%d",&act[i][j]);
                if ( act[i][j] != car[i][j] ) ok= 0;
            }
        for(i=1;i<=2&&!ok;i++)
        {
            for (j=1;j<=4&&!ok;j++)
            {
                rot();
                if (verif()) ok = 1;
            }
            if (ok==0) oglind();
        }
        fprintf(fout,"%d\n",ok);
    }
    return 0;
}

int verif()
{
    int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            if(car[i][j]!=act[i][j]) return 0;
    return 1;
}

void oglind()
{
    int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=n; j++)
            aux[i][n-j+1]=car[i][j];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            car[i][j] = aux[i][j];
}
