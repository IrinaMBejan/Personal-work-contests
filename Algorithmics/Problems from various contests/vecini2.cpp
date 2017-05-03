#include <fstream>
#define NrSir 8
using namespace std;
FILE* fin=fopen("vecini2.in","r");
FILE* fout=fopen("vecini2.out","w");

int a[3][1002];
int dl[NrSir]= {-1,-1,0,1,1,1,0,-1};
int dc[NrSir]= {0,1,1,1,0,-1,-1,-1};
int n,m,q,z,i,np,x,y,nrmax=0,nrvmax=0,nr,k;
int main()
{

    fscanf(fin,"%d %d %d",&n,&m,&q);
    fscanf(fin,"%d %d",&x,&y);
    z=1;
    for(i=1; i<=m; i++)
        a[1][i]=-1;
    for(i=0; i<=2; i++)
    {
        a[i][0]=-1;
        a[i][m+1]=-1;
    }
    while(x==1)
    {
        a[2][y]=1;
        fscanf(fin,"%d %d",&x,&y);
        z++;
    }
    np=2;
    int lin=0;
    while(z<=q||lin<m-1)
    {
        for(i=1; i<=m; i++)
        {
            a[0][i]=a[1][i];
            a[1][i]=a[2][i];
            a[2][i]=0;
        }
        while(x==np&&!feof(fin))
        {
            a[2][y]=1;
            fscanf(fin,"%d %d",&x,&y);
            z++;
        }
        np++;
        for(i=1; i<=m; i++)
        {
            nr=0;
            for(k=0; k<NrSir; k++)
                if(a[1+dl[k]][i+dc[k]]==a[1][i]) nr++;
            if(nr>nrmax)
            {
                nrmax=nr;
                nrvmax=1;
            }
            else if(nr==nrmax) nrvmax++;
        }
        lin++;
    }
    for(i=1; i<=m; i++)
    {
        a[0][i]=a[1][i];
        a[1][i]=a[2][i];
        a[2][i]=-1;
    }
    for(i=1; i<=m; i++)
    {
        nr=0;
        for(k=0; k<NrSir; k++)
            if(a[1+dl[k]][i+dc[k]]==a[1][i]) nr++;
        if(nr>nrmax)
        {
            nrmax=nr;
            nrvmax=1;
        }
        else if(nr==nrmax) nrvmax++;
    }
    fprintf(fout,"%d %d\n",nrmax,nrvmax);
    return 0;
}
