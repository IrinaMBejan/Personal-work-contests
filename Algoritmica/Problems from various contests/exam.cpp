#include <cstdio>
#define NMAX 1001
FILE* fin=fopen("exam.in","r");
FILE* fout=fopen("exam.out","w");

char a[NMAX][NMAX];
int date[5001];

int main()
{
    int n,m,i,j,x,y,nrm,ok,c,k;
    fscanf(fin,"%d %d",&n, &m);
    for (i=1; i<=m; i++)
    {
        fscanf(fin, "%d %d", &x, &y);
        a[x][y]=49;
        a[y][x]=49;
    }nrm=1;
    int max=0;
    date[1]=1;
    for(i=2;i<=n;i++)
    {
        nrm++;
        date[i]=1;
        ok=0;
        while(!ok)
        {
            ok=1;
            for(j=1;j<nrm;j++)
                if(date[j]==date[i]&&a[i][j]==49) {ok=0; break;}
            if(ok==0) date[i]++;
        }
        if(date[i]>max) max=date[i];
    }
    fprintf(fout,"%d\n",max);
    return 0;
}
