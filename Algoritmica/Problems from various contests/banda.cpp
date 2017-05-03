#include<cstdio>
#include<cmath>
using namespace std;

FILE* fin=fopen("banda.in","r");
FILE* fout=fopen("banda.out","w");

int n,c;
char x;
int b[45];
int f1,f2,s1,s2,i,d,cons,k;

int vector_de_semne(int k);
int final(int poz);
int cauta(int n, int i);
int initial(int poz);

int main()
{
    fscanf(fin,"%d\n%d\n%d",&n,&k,&c);
    if( c == 1)
        fscanf(fin,"%d",&s1);
    else
        fscanf(fin,"%d",&f2);

    vector_de_semne(k);
    cons=1;
    for(int i=1;i<=n;i++)
        cons*=2;
    if ( c==1)
    {
        f1=final(s1);
        fprintf(fout,"%d",f1);
    }
    else
    {
        s2=initial(f2);
        fprintf(fout,"%d",s2);

    }
}

int cauta(int n)
{
    int p=1;
    i=0;
    do
        i++,p*=2;
    while(p<n);
    return p;
}
int z;
int initial(int poz)
{
    int put, pas=0,d, val, semn=0;
    if(poz == 1)
        return k;
    else if( poz == 2)
        return cons-k+1;
    else
    {
        put=cauta(poz);
        d=put/2;
        if(poz%2==1)
            semn=b[pas];
        else
            semn=-b[pas];
        pas++;
        return semn*(cons/d)+initial(poz-d);
    }
}

int vector_de_semne(int k)
{
    int d;
    int i;
    b[1]=1;
    d=1;
    for(i=1;i<=n-1;i++)
        d*=2;
    for(i=2; i<=n; i++)
        if(k>d)
        {
            k=k-d;
            b[i]=-1;
            d/=2;
        }
        else
        {
            b[i]=1;
            d/=2;
        }
}

int final(int poz)
{
    int mijloc, b, j, strat, coloana, linie;
    {
        b=1;
        j=cons;
        strat=2;
        coloana=poz;
        linie=1;
        do
        {
            mijloc=(b+j)/2;
            if (k<=mijloc && mijloc<coloana)
            {
                linie=strat+1-linie;
                coloana=b+j- coloana;
                j=mijloc;
            }
            else if (coloana<=mijloc && mijloc<k)
            {
                linie=strat+1-linie;
                coloana=b+j - coloana;
                b=mijloc+1;
            }
            else if (k<=mijloc)
                j=mijloc;
            else
                b=mijloc+1;
            strat=strat*2;
        }
        while(coloana!=k);
        return linie;
    }
}
