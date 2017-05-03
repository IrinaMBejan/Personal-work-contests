#include <cstdio>

using namespace std;
FILE* fin=fopen("pavare.in","r");
FILE* fout=fopen("pavare.out","w");

int F1[3][4],F2[4][3],I1[2][1],I2[1][2], m,n;
int a[170][170];
void constr_figF1(int a[3][4],int k, int h)
{
    int i;
    for(i=1; i<=4; i++)
    {
        a[1][i]=k;
        a[3][i]=h;
        if (i%2==0)   a[2][i]=h;
        else a[2][i]=k;
    }
}

void pune_figF1(int F1[3][4], int i0, int j0)
{
    int i,j;
    for(i=1; i<=3; i++)
        for(j=1; j<=4; j++)
            a[i0+i-1][j0+j-1]=F1[i][j];
}

void constr_figF2(int a[4][3], int k, int h)
{
    int i;
    for (i=1; i<=4; i++)
    {
        a[i][1]=h;
        a[i][3]=k;
        if(i%2==0)
            a[i][2]=h;
        else
            a[i][2]=k;
    }
}

void pune_figF2(int F2[4][3],int i0, int j0)
{
    int i,j;
    for(i=1; i<=4; i++)
        for(j=1; j<=3; j++)
            a[i0+i-1][j0+j-1]=F2[i][j];
}

void constr_figI1(int a[2][1],int k)
{
    a[1][1]=k;
    a[2][1]=k;
}

void pune_figI1(int I1[2][1], int i0,int j0)
{
    a[i0][j0]=I1[1][1];
    a[i0+1][j0]=I1[2][1];
}

void constr_figI2(int a[1][2], int k)
{
    a[1][1]=k;
    a[1][2]=k;
}

void pune_figI2(int I2[1][2], int i0, int j0)
{
    a[i0][j0]=I2[1][1];
    a[i0][j0+1]=I2[1][2];
}

void afis2()
{

    int i,j;
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n-1; j++)
            fprintf(fout,"%d ",a[i][j]);
        fprintf(fout,"%d\n",a[i][n]);
    }
}

void afis1()
{
    int i,j;
    for(j=1; j<=n; j++)
    {
        for(i=1; i<=m-1; i++)
            fprintf(fout,"%d ",a[i][j]);
        fprintf(fout,"%d\n",a[m][j]);
    }
}

void rez2()
{
    int r,i,j,k,aria,x,y;
    k=1;
    aria=0;
    j=1;
    while (j<=n-2&&aria< m*n/2)
    {
        i=1;
        while (i<=m-3&&aria< m*n/2)
        {
            constr_figF2(F2,k,k+1);
            aria=aria+12;
            k=k+2;
            pune_figF2(F2,i,j);
            i=i+4;
        }
        j=j+3;
    }
    r=m;
    while (r>0&&a[r][1]==0) r=r-1;
    r=r+1;
    for(x=1; x<=i-2; x++)
        for(y=j; y<=n; y++)
            if(x%2==1)
            {
                constr_figI1(I1,k);
                k=k+1;
                pune_figI1(I1,x,y);
            }
    for(x=i; x<=r-2; x++)
        for(y=j-3; y<=n; y++)
            if(x%2==1)
            {
                constr_figI1(I1,k);
                k=k+1;
                pune_figI1(I1,x,y);
            }
    if(m%2==0)
    {
        for(x=r; x<=m; x++)
            for(y=1; y<=n; y++)
                if(x%2==1)
                {
                    constr_figI1(I1,k);
                    k=k+1;
                    pune_figI1(I1,x,y);
                }
    }
   else
    for(x=r; x<=m; x++)
        for(y=1; y<=n; y++)
                if(y%2==1)
                {
                   constr_figI2(I2,k);
                    k=k+1;
                    pune_figI2(I2,x,y);
                }
}


void rez()
{
    int i,j,aux,sw;
    sw=1;
    if(m>=n)
    {
        rez2();
        afis1();
    }
    else
    {
        aux=m;
        m=n;
        n=aux;
        rez2();
        afis2();
    }
}

int main()
{
    fscanf(fin,"%d %d",&n,&m);
    rez();
}
