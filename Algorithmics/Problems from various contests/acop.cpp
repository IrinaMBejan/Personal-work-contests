#include <cstdio>
#include <algorithm>
#define Nmax 30
#define MIN(x,y) ((x)<(y)?(x):(y))
#define MAX(x,y) ((x)>(y)?(x):(y))
#define INF 2000009
using namespace std;
FILE* fin=fopen("acop.in","r");
FILE* fout=fopen("acop.out","w");

int N;
struct drept
{
    int poz,x1,y1,x2,y2;
} DW[Nmax], DH[Nmax];

int W,H;
int nr, in1, in2;
int nrmax, nrsol;
int v[Nmax];

int comp2(drept a, drept b)
{
    return (a.y1<b.y1 || (a.y1==b.y1 && a.y2<=b.y2));
}

int comp1(drept a, drept b)
{
    return (a.x1<b.x1 || (a.x1==b.x1 && a.x2<=b.x2));
}

void BKT(int k);

int main()
{
    int T;
    fscanf(fin,"%d",&T);
    int i;
    while(T)
    {
        fscanf(fin,"%d %d",&W,&H);
        fscanf(fin,"%d",&N);
        for(i=1; i<=N; i++)
        {
            fscanf(fin,"%d %d %d %d",&DW[i].x1,&DW[i].y1,&DW[i].x2,&DW[i].y2);
            DW[i].poz=i;
            DH[i]=DW[i];
        }
        sort(DW+1,DW+N+1, comp1);
        sort(DH+1,DH+N+1, comp2);
        nrmax = INF;
        nrsol = 0;
        BKT(1);
        if(nrmax==INF && nrsol==0)
            fprintf(fout,"-1\n");
        else
            fprintf(fout,"%d %d\n",nrmax,nrsol);
        --T;
    }
    return 0;
}

void BKT(int k)
{
    if(k-1==N)
    {
        int i;
        in1=in2=-1;
        for(i=1; i<=N; i++)
            if(v[DW[i].poz])
            {
                if(in1==-1)
                    in1 = DW[i].x1, in2 = DW[i].x2;
                else
                {
                    if(DW[i].x2>=in1 && DW[i].x1<in1)
                        in1=DW[i].x1, in2=MAX(DW[i].x2,in2);
                    if(DW[i].x1<=in2 && DW[i].x2>in2)
                        in1 = MIN(DW[i].x1, in1), in2 = DW[i].x2;
                }
            }
        if(in1 == 0 && in2 == W)
        {
            nr=0;
            in1=in2=-1;
            for(i=1; i<=N; i++)
                if(v[DH[i].poz])
                {
                    nr++;
                    if(in1==-1)
                        in1 = DH[i].y1, in2 = DH[i].y2;
                    else
                    {
                        if(DH[i].y1<in1 && DH[i].y2>=in1)
                            in1=DH[i].y1, in2=MAX(DH[i].y2,in2);
                        if(DH[i].y1<=in2 && DH[i].y2>in2)
                            in1 = MIN(DH[i].y1, in1), in2 = DH[i].y2;
                    }
                }
            if(in1 == 0 && in2 == H)
            {
                if (nr==nrmax)
                    nrsol++;
                else if(nr<nrmax)
                {
                    nrmax=nr;
                    nrsol=1;
                }
            }
        }
    }
    else
    {
        v[k]=1;
        BKT(k+1);

        v[k]=0;
        BKT(k+1);

    }
}
