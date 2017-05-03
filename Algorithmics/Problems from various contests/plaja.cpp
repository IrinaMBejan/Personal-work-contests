#include <cstdio>
#define NMAX 2002
using namespace std;
FILE* fin=fopen("plaja.in","r");
FILE* fout=fopen("plaja.out","w");

int mat[NMAX][NMAX], S[NMAX][NMAX];

struct umbrele
{
    int x;
    int y;
} um[101];
int main()
{
    int a,b,N,M,u,i,j,nrt,nrl=0,Z,ok,x1,x2,y1,y2;
    fscanf(fin,"%d %d %d",&a,&b,&u);
    for(i=1; i<=u; i++)
        fscanf(fin,"%d %d",&um[i].x,&um[i].y);
    fscanf(fin,"%d",&N);
    nrt=N;
    for(i=1; i<=N; i++)
    {
        fscanf(fin,"%d %d %d %d",&x1,&y1,&x2,&y2);
        ok=0;
        for(j=1; j<=u; j++)
            if(um[j].x>=x1&&um[j].y>=y1&&um[j].y<=y2&&um[j].x<=x2)
            {
                ok=1;
                break;
            }
        if(ok) nrt--;
        else
       {
           mat[x1][y1]++;
        mat[x1][y2+1]--;
        mat[x2+1][y2+1]++;
        mat[x2+1][y1]--;
       }
    }
    fprintf(fout,"%d ",nrt);

    for(i=1; i<=a; i++)
        for(j=1; j<=b; j++)
            S[i][j]=S[i-1][j]+S[i][j-1]+mat[i][j]-S[i-1][j-1];

    for(i=1; i<=u; i++)
        S[um[i].x][um[i].y]=1;

    for(i=1; i<=a; i++)
        for(j=1; j<=b; j++)
            S[i][j]=S[i-1][j]+S[i][j-1]-S[i-1][j-1]+(S[i][j]!=0);

    fscanf(fin,"%d",&M);
    for(i=1; i<=M; i++)
    {
        fscanf(fin,"%d %d %d %d",&x1,&y1,&x2,&y2);
        Z=S[x2][y2] - S[x2][y1-1] - S[x1-1][y2] + S[x1-1][y1-1];
        if(Z==0) nrl++;
    }
    fprintf(fout,"%d\n",nrl);

    return 0;
}
