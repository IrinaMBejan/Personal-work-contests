#include <cstdio>
#include <vector>
#define Nmax 1025
using namespace std;
FILE* fin=fopen("patrate4.in","r");
FILE* fout=fopen("patrate4.out","w");

struct solutie
{
    int x, y, L;
}Sol1;

bool Foaie[Nmax][Nmax];
int Sum[Nmax][Nmax];
void DIV(int x1,int y1, int x2,int y2);
vector < solutie> Sol;
int N,k;

int main()
{
    int x, y;
    fscanf(fin,"%d %d",&N,&k);
    int i;
    for(i=1;i<=N;i++)
    {
        fscanf(fin,"%d %d",&x,&y);
        Foaie[x][y]=1;
    }

    int j;
    for(i=1;i<Nmax;i++)
        for(j=1;j<Nmax;j++)
            Sum[i][j] = Sum[i][j-1]+Sum[i-1][j]+Foaie[i][j]-Sum[i-1][j-1];

    DIV(1,1,Nmax-1,Nmax-1);

    fprintf(fout,"%d\n",Sol.size());
    for(i=0;i<Sol.size();i++)
        fprintf(fout,"%d %d %d\n",Sol[i].x, Sol[i].y, Sol[i].L);
    return 0;
}

void DIV(int x1,int y1, int x2,int y2)
{
    int nrp = Sum[x2][y2] - Sum[x2][y1-1]-Sum[x1-1][y2]+Sum[x1-1][y1-1];
    int S = (x2-x1+1)*(y2-y1+1);
    if(nrp*k>=S && nrp*k<4*S)
        {
            Sol1.x = x1;
            Sol1.y = y1;
            Sol1.L = (x2-x1+1);
            Sol.push_back(Sol1);
        }
    else if(nrp!=0 && nrp*k<S)
    {
        int mijx = x1+(x2-x1)/2;
        int mijy = y1+(y2-y1)/2;

        DIV(x1,y1,mijx,mijy);
        DIV(mijx+1, y1, x2, mijy );
        DIV(x1, mijy+1, mijx, y2);
        DIV( mijx+1, mijy+1, x2, y2);
    }

}
