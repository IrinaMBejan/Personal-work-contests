#include<cstdio>
#include<cstring>
#define LGMAX 105
#define Max 499999999999999999

typedef short int NRMARE[LGMAX];
FILE* fin=fopen("m4.in","r");
FILE* fout=fopen("m4.out","w");

NRMARE x,y,N,new_X, new_Y, new_N,unu;
int nx,ny,nN,nnew_X, nnew_Y,nnew_N,nunu;

int mat[3][3];
int Valoare();

void fillzero(NRMARE a, int na);
void diferenta (NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc);
void suma (NRMARE a, int &na, NRMARE b, int nb);
void citire(NRMARE a, int& na);
void prodint (NRMARE a, int& na, int b);
int comp(NRMARE a, int na, NRMARE b, int nb);
void impartint(NRMARE a, int na, int b, NRMARE c, int &nc);
void copie(NRMARE a, int na, NRMARE b, int& nb);
void init1(NRMARE a, int &na);


int main()
{
    int T;
    fscanf (fin, "%d", &T);
    mat[0][0] = 0;
    mat[0][1] = 1;
    mat[1][0] = 2;
    mat[1][1] = 3;
    init1(unu,nunu);
    while(T)
    {
        citire(x,nx);
        citire(y,ny);

        init1(N,nN);

        if(comp(x,nx,y,ny) == 1)
        {
            while(comp(N,nN,x,nx)!= 1)
                prodint(N,nN,2);
        }
        else
        {
            while(comp(N,nN,y,ny)!= 1)
                prodint(N,nN,2);
        }

        fprintf ( fout, "%d\n", Valoare() );
        --T;
    }
}

int Valoare()
{
    int ok=0,okx,oky;
    while(!ok)
    {
        if(x[0]<2 && y[0]<2 && nx==1 && ny==1)
            ok=1;
        else
        {
            okx=0, oky=0;
            impartint(N,nN,2,new_N,nnew_N);

            if (comp(x,nx,new_N,nnew_N) == -1) okx = 1 ;
            if( comp(y,ny,new_N,nnew_N) == -1) oky = 1;
            if(!okx && !oky)
            {
              suma(x,nx, unu, 1);

              diferenta(y,ny, new_N, nnew_N, new_X, nnew_X);
              diferenta(N,nN, x,nx, new_Y, nnew_Y);

              copie(new_X, nnew_X, x,nx);
              copie(new_Y, nnew_Y, y,ny);
            }

            if(!okx && oky)
            {
              suma(x,nx, unu, 1);
              suma(y,ny, unu, 1);

              diferenta(N,nN, x,nx, new_X, nnew_X);
              diferenta(new_N,nnew_N, y,ny, new_Y, nnew_Y);

              copie(new_X, nnew_X, x,nx);
              copie(new_Y, nnew_Y, y,ny);
            }

            if(okx && !oky)
            {
               suma(y,ny, unu, 1);

              diferenta(N,nN, y,ny, new_X, nnew_X);

              copie(x, nx, y,ny);
              copie(new_X, nnew_X, x,nx);
            }
        }
        copie(new_N,nnew_N, N, nN);
    }
    return mat[x[0]][y[0]];
}

void copie(NRMARE a, int na, NRMARE b, int& nb)
{
    int i;
    for(i=0;i<na;i++)
        b[i]=a[i];
    nb=na;
}


int comp(NRMARE a, int na, NRMARE b, int nb)
{
    int i;
    if(na>nb) return 1;
    if(nb>na) return -1;
    i=na-1;
    while(a[i]==b[i] && i>=0) i--;
    if (i==-1) return 0;
    if (a[i] > b[i]) return 1;
    return -1;
}

void fillzero(NRMARE a, int na)
{
    int i;
    for(i=na;i<LGMAX;i++)
        a[i]=0;
}
void suma (NRMARE a, int &na, NRMARE b, int nb)
{
    fillzero(a,na);
    fillzero(b,nb);
    int i,t=0,v;
    for(i=0;i<na||i<nb||t;i++)
    {
        v=a[i]+b[i]+t;
        a[i]=v%10;
        t=v/10;
    }
    na=i;
}


void init1(NRMARE a, int &na)
{
    na=1; a[0]=1;
}
void citire(NRMARE a, int& na)
{
    int i;
    char s[LGMAX];
    fscanf(fin,"%s",s);
    na=strlen(s);
    for(i=na-1;i>=0;i--)
        a[i]=s[na-i-1]-'0';
}



void diferenta (NRMARE a, int na, NRMARE b, int nb, NRMARE c, int &nc)
{
        int T=0,i;
        for(i=0;i<na;i++)
        {
            c[i]=a[i]-b[i]+T;
            if(c[i]<0) {c[i]+=10; T=-1;}
            else T=0;
        }
        nc=na;
        while(c[nc-1]==0&&nc>1)
            nc--;
}


void prodint (NRMARE a, int& na, int b)
{
    int i, T=0,prod;
    for(i=0;i<na;i++)
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

void impartint(NRMARE a, int na, int b, NRMARE c, int &nc)
{
    int i,t=0;
    for(i=na-1; i>=0; i--)
    {
        t=t*10+a[i];
        c[i]=t/b;
        t=t%b;
    }
    nc=na;
    for(;c[nc-1]==0&&nc>1;nc--);
}
