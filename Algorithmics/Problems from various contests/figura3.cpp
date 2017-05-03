#include <cstdio>

using namespace std;
FILE* fin=fopen("figura.in","r");
FILE* fout=fopen("figura.out","w");

bool a[21][21];
struct crop
{
    int x;
    int y;
} q[401];

int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int main()
{
    int D,N,i,j,nr;
    fscanf(fin,"%d %d",&D,&N);
    for(i=1;i<=N;i++)
    {
        fscanf(fin,"%d %d",&q[i].x,&q[i].y);
        a[q[i].x][q[i].y]=1;
    }
    nr=0;
    for(i=1;i<=N;i++)
    {
        for(j=0;j<=3;j++)
            if(a[q[i].x+dx[j]][q[i].y+dy[j]]==0) nr++;
    }
    fprintf(fout,"%d\n", nr);
    return 0;
}
