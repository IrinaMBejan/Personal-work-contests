#include <cstdio>
#include<math.h>
#define NMAX 10001
using namespace std;
FILE* fin=fopen("cladiri1.in","r");
FILE* fout=fopen("cladiri1.out","w");

int nrv[NMAX];
int main()
{
    int x,y,inte,cx,cy,gr,niv,nra=0,nivmax=-1,i,rmax=-1;
    char ch;
    fscanf(fin,"%d %d %d",&x,&y,&inte);
    while( (ch = fgetc(fin)) != EOF)
    {
        fscanf(fin,"%d %d %d",&cx,&cy,&gr);
        if(fabs((double)cx-x)>fabs((double)cy-y))
            niv=fabs((double)cx-x);
        else niv=fabs((double)cy-y);
        if(inte-niv>=gr) {nra++;nrv[niv]++;}
        if(niv>nivmax) nivmax=niv;
    }
     if(inte-niv>=gr) nra--;
     nrv[niv]--;
     for(i=0;i<=nivmax;i++)
        if(nrv[i]>rmax) rmax=nrv[i];
    if(rmax>0)
     {
        fprintf(fout,"%d\n%d\n",nra,rmax);
      for(i=0;i<=nivmax;i++)
        if(nrv[i]==rmax) fprintf(fout,"%d ",i);
     }
     else fprintf(fout,"%d\n0",nra);
        fprintf(fout,"\n");

    return 0;
}
