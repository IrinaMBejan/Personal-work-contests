#include <cstdio>
#define NMAX 1001
using namespace std;
FILE* fin=fopen("intersectii.in","r");
FILE* fout=fopen("intersectii.out","w");

int P[NMAX][NMAX];
int v[NMAX*NMAX*4];
int cmmdc(int a, int b);
int main()
{
    int n,m,h,w,i,j,x;
    fscanf(fin,"%d %d",&h,&w);
    n=h/2;
    m=w/2;

    P[1][1]=1;
    for(i=1;i<=n;i++)
        for(j=i+1;j<=m;j++)
            if(P[i][j]==0)
                if(cmmdc(i,j)==1)
                    {
                            P[i][j]=1;
                            v[i+j-1]=1;
                            for(int k=2;k<=n/2&&k<=m/2;k++)
                                    {P[k*i][k*j]=k*(i+j-1); v[k*(i+j-1)]++;}

                    }
    fscanf(fin,"%d",&n);
    for(i=1;i<=n;i++)
        {
            fscanf(fin,"%d",&x);
            fprintf(fout,"%d\n",v[x]*4);
        }
    return 0;
}

int cmmdc(int a, int b)
{
    int r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
