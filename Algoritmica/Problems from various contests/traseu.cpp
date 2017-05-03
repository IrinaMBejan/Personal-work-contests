#include <cstdio>
#define NMAX 200010
using namespace std;
FILE* fin=fopen("traseu.in","r");
FILE* fout=fopen("traseu.out","w");

struct pozitie
{
    int x,y,z;
} C[NMAX],poz;

int mat[105][105][105];

int dx[6]= {-1,0,0,0,0,1};
int dy[6]= {0,-1,0,0,1,0};
int dz[6]= {0,0,-1,1,0,0};

int main()
{
    int st=1,fi=1;
    int N,M,xs,ys,zs,xf,yf,zf,i,j,x1,y1,z1;
    fscanf(fin,"%d %d",&N,&M);
    fscanf(fin,"%d %d %d",&xs,&ys,&zs);

    C[st].x=xs;
    C[st].y=ys;
    C[st].z=zs;
    mat[xs][ys][zs]=1;

    fscanf(fin,"%d %d %d",&xf,&yf,&zf);

    for(i=1; i<=M; i++)
    {
        fscanf(fin,"%d %d %d",&x1,&y1,&z1);
        mat[x1][y1][z1]=-1;
    }

    for(i=0; i<=N; i++)
        for(j=0; j<=N; j++)
            mat[0][i][j]=mat[i][0][j]=mat[i][j][0]=mat[N+1][i][j]=mat[i][N+1][j]=mat[i][j][N+1]=-1;

    while(!mat[xf][yf][zf])
    {
        poz=C[st++];
        for(i=0; i<6; i++)
            if(mat[poz.x+dx[i]][poz.y+dy[i]][poz.z+dz[i]]==0)
            {
                mat[poz.x+dx[i]][poz.y+dy[i]][poz.z+dz[i]]=1+mat[poz.x][poz.y][poz.z];
                C[++fi].x=poz.x+dx[i];
                C[fi].y=poz.y+dy[i];
                C[fi].z=poz.z+dz[i];
            }
        if(fi==200000) fi=1;
        if(st==200001) st=1;
    }
    fprintf(fout,"%d\n",mat[xf][yf][zf]);

    st=1,fi=1;
    C[st].x=xf;
    C[st].y=yf;
    C[st].z=zf;
    int val=mat[xf][yf][zf];
    for(i=1; i<=mat[xf][yf][zf]; i++)
    {
        poz=C[st++];
        for(j=0; j<6; j++)
            if(mat[poz.x+dx[j]][poz.y+dy[j]][poz.z+dz[j]]==val-1)
            {
                C[++fi].x=poz.x+dx[j];
                C[fi].y=poz.y+dy[j];
                C[fi].z=poz.z+dz[j];
                val--;
                break;
            }
    }
    for(i=mat[xf][yf][zf]; i>=1; i--)
        fprintf(fout,"%d %d %d\n",C[i].x,C[i].y,C[i].z);
    return 0;
}
