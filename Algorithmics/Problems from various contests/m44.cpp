#include<cstdio>
#include<cstring>
#define LGMAX 105

typedef short int NRMARE[LGMAX];
FILE* fin=fopen("m4.in","r");
FILE* fout=fopen("m4.out","w");

NRMARE x,y,N,unu,a,b;
int nx,ny,nN,na,nb;

int mat[3][3];
int Valoare();

void fillzero(NRMARE a, int na);
void diferenta (NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc);
void suma (NRMARE a, int &na, NRMARE b, int nb);
void citire(NRMARE a, int& na);
void prodint (NRMARE a, int& na, int b);
int comp(NRMARE a, int na, NRMARE b, int nb);
void impartint(NRMARE a, int& na, int b);
void Copie(NRMARE a, int na, NRMARE b, int& nb);

int main()
{
    int T;
    fscanf (fin, "%d", &T);
    mat[1][1] = 0;
    mat[1][2] = 1;
    mat[2][1] = 2;
    mat[2][2] = 3;
    unu[0]=1;
    for (int i = 1; i <= T; i++)
    {
        citire(x,nx);
        citire(y,ny);
        suma(x,nx,unu,1);
        suma(y,ny,unu,1);
        if(comp(x,nx,y,ny) == 1)
        {
            N[0]=1;
            nN=1;
            while(comp(N,nN,x,nx)==-1)
                prodint(N,nN,2);
        }
        else
        {
            N[0]=1;
            nN=1;
            while(comp(N,nN,y,ny)==-1)
                prodint(N,nN,2);
        }
        impartint(N,nN,2);
        fprintf ( fout, "%d\n", Valoare() );
    }
}

int Valoare()
{
    if(x[0]<=2&&y[0]<=2&&nx==1&&ny==1)
        return mat[x[0]][y[0]];
    int l=1,c=1;
    if (comp(x,nx,N,nN) > 0) l=2,diferenta(x,nx,N,nN,x,nx);
    if( comp(y,ny,N,nN) > 0) c=2, diferenta(y,ny,N,nN,y,ny);

    if(!(l==1 && c==1))
    {
        Copie(x,nx,a,na);
        Copie(y,ny,b,nb);
        if(l == 2 && c == 2)
        {
            Copie(y,ny,a,na);
            diferenta(N,nN,x,nx,b,nb);
            suma(b,nb,unu,1);
        }
        if(l == 2 && c == 1)
        {
            diferenta(N,nN,x,nx,a,na);
            suma(a,na,unu,1);
            diferenta(N,nN,y,ny,b,nb);
            suma(b,nb,unu,1);
        }
        if(l == 1 && c == 2)
        {
            diferenta(N,nN,y,ny,a,na);
            suma(a,na,unu,1);
            Copie(x,nx,b,nb);
        }

        Copie(a,na,x,nx);
        Copie(b,nb,y,ny);
    }
    impartint(N,nN,2);
    return Valoare();
}

void Copie(NRMARE a, int na, NRMARE b, int& nb)
{
    nb=na;
    for(int i=0; i<LGMAX; i++)
        b[i]=a[i];
}
int comp(NRMARE a, int na, NRMARE b, int nb)//--
{
    int i;
    if(na>nb) return 1;
    if(nb>na) return -1;
    i=na-1;
    while(a[i]==b[i]&&i>=0) i--;
    if (i==-1) return 0;
    if(a[i]>b[i]) return 1;
    return -1;
}

void fillzero(NRMARE a, int na)
{
    int i;
    for(i=na; i<LGMAX; i++)
        a[i]=0;
}
void suma (NRMARE a, int &na, NRMARE b, int nb)
{
    fillzero(a,na);
    fillzero(b,nb);
    int i,t=0,v;
    for(i=0; i<na||i<nb||t; i++)
    {
        v=a[i]+b[i]+t;
        a[i]=v%10;
        t=v/10;
    }
    na=i;
}


void citire(NRMARE a, int& na)
{
    int i;
    char s[LGMAX];
    fscanf(fin,"%s",s);
    na=strlen(s);
    for(i=na-1; i>=0; i--)
        a[i]=s[na-i-1]-'0';
}



void diferenta (NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc)
{
    //a>=b;
    int T=0,i;
    for(i=0; i<na; i++)
    {
        int w=a[i]-b[i]+T;
        if(w<0)
        {
            w+=10;
            T=-1;
        }
        else T=0;
        c[i]=w;
    }
    nc=na;
    while(c[nc-1]==0&&nc>1)
        nc--;
}


void prodint (NRMARE a, int& na, int b)
{
    int i, T=0,prod;
    for(i=0; i<na; i++)
    {
        prod=a[i]*b+T;
        a[i]=prod%10;
        T=prod/10;
    }
    while (T)
    {
        a[na]=T%10;
        T/=10;
        na++;
    }
}

void impartint(NRMARE a, int &na, int b)
{
    int i,t=0;
    for(i=na-1; i>=0; i--)
    {
        t=t*10+a[i];
        a[i]=t/b;
        t=t%b;
    }
    for(; a[na-1]==0&&na>1; na--);
}
