#include <cstdio>
#include <algorithm>
#define pMax 10
#define Nmax 1005
using namespace std;

FILE* fin = fopen("xcmmdc.in","r");
FILE* fout = fopen("xcmmdc.out","w");
int D[pMax][Nmax][Nmax];
int a[Nmax][Nmax];
int nr[1<<pMax];
int power[pMax];
int N,M,K,Q;

int cbLMAX(int,int);
int cbLMIN(int,int);
int cmmdc4(int a, int b, int c, int d);
int cmmdc(int L, int i, int j);
int Euclid(int a, int b);
void Citire();
void Queries();
void DP();

int main()
{
    Citire();

    power[0] = 1;
    for(int i = 1; i<=pMax;i++)
        power[i] = power[i-1]*2;

    DP();
    int i,j,lmax,lmin;

    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
            {
                lmax = cbLMAX(i,j);
                lmin = cbLMIN(i,j);
                nr[lmax+1]-=1;
                nr[lmin]+=1;
            }
    for(i=1;i<=N;i++)
        nr[i]+=nr[i-1];

    Queries();
    return 0;
}

void Queries()
{
    int i,q;
    for(i=1;i<=Q;i++)
    {
        fscanf(fin,"%d",q);
        fprintf(fout,"%d\n",nr[q]);
    }
}

void DP()
{
    int i,j,p;
    for(p = 1; p<pMax; p++)
        for(i=1;i<=N;i++)
            for(j=1;j<=M;j++)
                D[p][i][j] = cmmdc4(D[p-1][i][j],D[p-1][i+power[p-1]][j],D[p-1][i][j+power[p-1]],D[p-1][i+power[p-1]][j+power[p-1]]);

}

int cmmdc4(int a, int b, int c, int d)
{
    return Euclid(Euclid(a,b),Euclid(c,d));
}


int cmmdc(int L, int i, int j)
{
    int p,x;
    for(p = pMax; p>=0 && L < power[p]; p--);
    x = L - power[p];
    if(p == -1) return D[0][i][j]]
    return cmmdc4(D[p][i][j],D[p][i+x][j],D[p][i][j+x],D[p][i+x][j+x]);
}

int cbLMAX(int i,int j)
{
    int lmax = 0;
    int st = 0, dr = min(M,N)+1,mij;
    while(st<dr)
    {
        mij = (st+dr)>>1;
        if(cmmdc(mij,i,j) >= K)
        {
            lmax = mij;
            st = mij+1;
        }
        else
            dr = mij-1;
    }
    return lmax;
}

int cbLMIN(int i,int j)
{
    int lmin = 0;
    int st = 0, dr = min(M,N)+1,mij;
    while(st<dr)
    {
        mij = (st+dr)>>1;
        if(cmmdc(mij,i,j) > K)
        {
            lmin = mij;
            st = mij+1;
        }
        else
        {
            dr = mij-1;
        }
    }
    return lmin+1;
}



int Euclid(int a, int b)
{
    int r;
    while(b!=0)
    {
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

void Citire()
{
    fscanf(fin,"%d %d %d %d",&N,&M,&K,&Q);
    int i,j;
    for(i=1;i<=N;i++)
        for(j=1;j<=M;j++)
            fscanf(fin,"%d",&D[0][i][j]);
}
