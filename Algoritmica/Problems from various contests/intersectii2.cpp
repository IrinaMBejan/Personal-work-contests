#include <cstdio>
#include<bitset>
#define NMAX 2010
using namespace std;
FILE* fin=fopen("intersectii.in","r");
FILE* fout=fopen("intersectii.out","w");

bitset<NMAX> P[NMAX]; //bool P[NMAX][NMAX] - 4MB;
int v[NMAX*2];
int h,w,i,j,x,t;


int main()
{
    fscanf(fin,"%d %d %d",&w,&h,&t);
    int poz=0;
    for(i=1; i<w; i++)
        for(j=1; j<h; j++)
            if(!P[i][j])
            {
                for(int k=1; k*i<w&&k*j<h; k++)
                {
                    P[k*i][k*j]=1;
                    v[k*(i+j-1)]++;
                    if(poz<k*(i+j-1)) poz=k*(i+j-1);
                }
            }
    for(i=1; i<=t; i++)
    {
        fscanf(fin,"%d",&x);
        if(x>poz) fprintf(fout,"0\n");
        else fprintf(fout,"%d\n",(v[x]*4));
    }
    return 0;
}

