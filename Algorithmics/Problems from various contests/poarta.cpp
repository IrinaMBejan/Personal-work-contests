#include <cstdio>
#define DMAX 251
using namespace std;
FILE* fin=fopen("poartas.in","r");
FILE* fout=fopen("poartas.out","w");

int a[DMAX][DMAX];
struct echipaj
{
    int xb,yb;
};

echipaj p[5001];
int dep[5001];
int main()
{
    int pnr,nrmutari=0,i,k,xa,ya;
    fscanf(fin,"%d",&pnr);
    for(i=1; i<=pnr; i++)
    {
        fscanf(fin,"%d %d %d %d",&xa,&ya,&p[i].xb,&p[i].yb);
        a[xa][ya]=i;
    }
    int nrc=0;
    for(i=1; i<=pnr; i++)
            {
                dep[i]=a[p[i].xb][p[i].yb];
                if(dep[i]==i) {dep[i]=0; nrc--;}
            }
    int j, m, aux;
    for(i=1; i<=pnr; i++)
    {
        if(dep[i])
        {
            nrc++;
            j=dep[i];
            dep[i]=0;
            while(j!=i)
            {
                 if(dep[j]==0) {nrc--; break;}
                aux=dep[j];
                dep[j]=0;
                j=aux;
            }
        }
    }
    fprintf(fout,"%d\n",nrc+pnr);
    return 0;
}
