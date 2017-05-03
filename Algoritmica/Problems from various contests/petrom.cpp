#include <cstdio>
#include <cmath>
#define INFINIT 30000
#define NMAX 1001
#define KMAX 301

FILE * fin = fopen("petrom.in","r");
FILE* fout = fopen("petrom.out","w");

int   d[NMAX];
int   cmin[KMAX][NMAX];
int   cost[NMAX][NMAX];
int   k, n;
int   sol[KMAX+1];
int   poz[KMAX][NMAX];

void Cost();
void DetSubpro();
void Citire();
void Afisare();


int main()
{
    Citire();
    DetSubpro();
    Afisare();
    return 0;
}

void Cost()
{
    int i,j,l,mij,dif;
    for (i=1; i<=n; i++)
        for (j=i+1; j<=n; j++)
        {
            mij = d[(i+j)/2];
            dif = 0;
            for (l=i; l<=j; l++)
                dif += fabs(d[l] - mij);
            cost[i][j] = dif;
        }
}

void DetSubpro()
{
    int i, j, p;
    Cost();
    for (j=1; j<=n; j++)
    {
        cmin[1][j] = cost[1][j];
        poz[1][j] = 1;
    }

    for (i=2; i<=k; i++)
        for (j=1; j <= n; j++)
        {
            cmin[i][j] = INFINIT;
            for (p=i; p<=j; p++)
                if (cost[p][j]+cmin[i-1][p-1] < cmin[i][j])
                {
                    cmin[i][j] = cost[p][j] + cmin[i-1][p-1];
                    poz[i][j] = p;
                }
        }

    sol[k+1]=n+1;
    for (i=k, j=n; i>0; i--)
    {
        sol[i] = poz[i][j];
        j = sol[i]-1;
    }
}

void Citire()
{
    int i;
    fscanf(fin,"%d %d",&n,&k);
    for(i=1; i<=n; i++)
        fscanf(fin,"%d",d+i);
}

void Afisare()
{
    int i, w;
    fprintf(fout,"%d\n",cmin[k][n]);
    for (i=1; i<=k; i++)
        fprintf(fout,"%d\n", (sol[i]+sol[i+1]-1)/2);
}
