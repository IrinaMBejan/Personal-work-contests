#include <algorithm>
#include <cstdio>
#define Nmax 405
using namespace std;
FILE* fin=fopen("ferma1.in","rt");
FILE* fout=fopen("ferma1.out","wt");

int n, m, nrz;
char a[Nmax][Nmax],color;
int  b[Nmax][Nmax], dx[]= {-1, 0, 1, 0}, dy[]= {0, 1, 0, -1}, d[Nmax*Nmax],p;
bool c[Nmax*Nmax];

void filll(int x, int y)
{
    b[x][y]=nrz;
    d[nrz]++;
    for(int i=0; i<4; i++)
    {
        if(!b[x+dx[i]][y+dy[i]]&&a[x][y]==a[x+dx[i]][y+dy[i]]) filll(x+dx[i], y+dy[i]);
    }
}

int main()
{
    freopen("ferma.in", "r", stdin);
    freopen("ferma.out", "w", stdout);
    int i, j, k, l, sol=0, s=0,task,ma=0,p=0;
    pair<int, int> soli;

    fscanf(fin,"%d\n%d%d",&task, &n, &m);
    for(i=1; i<=n; i++)
       fscanf(fin, "%s", a[i]+1);

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(!b[i][j])
            {
                nrz++;
                filll(i, j);
                if(ma<d[nrz])
                    ma=d[nrz];
            }
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            char aux=a[i][j];
            for(k=0; k<4; k++)
            {
                a[i][j]=a[i+dx[k]][j+dy[k]];
                for(l=0, s=0; l<4; l++)
                    if(!c[b[i+dx[l]][j+dy[l]]]&&a[i][j]==a[i+dx[l]][j+dy[l]])
                    {
                        c[b[i+dx[l]][j+dy[l]]]=1;
                        s+=d[b[i+dx[l]][j+dy[l]]];
                    }
                if(!c[b[i][j]]) s++;
                if(s>sol)
                {
                    sol=s;
                    color=a[i][j];
                    soli=make_pair(i, j);
                }
                for(l=0; l<4; l++)
                    c[b[i+dx[l]][j+dy[l]]]=0;
            }
            a[i][j]=aux;
        }

    if(task==1) fprintf(fout,"%d\n",ma);
    else
    {
        fprintf(fout,"%d %d\n", soli.first, soli.second);
        fprintf(fout,"%c\n",color);
    }
}
