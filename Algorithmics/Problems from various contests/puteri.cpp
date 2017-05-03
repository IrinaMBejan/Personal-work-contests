#include <cstdio>
#define bmax 60
using namespace std;
FILE* fin=fopen("puteri.in","r");
FILE* fout=fopen("puteri.out","w");

int T;
long long int a,b;
bool ciur[bmax+5];
void Ciur()
{
    ciur[1]=ciur[0]=1;

    int i,j;
    for (i=2; i*i<=bmax; i++)
    {
       if (ciur[i]==0)
          for (j=i*i; j<=bmax; j+=i)
               ciur[j]=1;
    }
}

long long int putere(long long int x, int p)
{
    long long int rez=1,last;
    while(p)
    {
        last=rez;
        rez*=x;

        if(rez/x!=last)
            return -1;
        p--;
    }
    return rez;

}


long long int radacina(long long int x, int k)
{
    long long int st=1, dr=x, mij,put;
    long long int sol=1;
    while(st<=dr)
    {
        mij = (st+dr)/2;
        put = putere(mij,k);
        if(put<=x && put>0)
        {
            sol=mij;
            st=mij+1;
        }
        else
            dr=mij-1;
    }
    return sol;
}

long long int f(long long int x, int exp=bmax)
{
    if(x==0) return 0;

    long long int rez=1, rad;
    int k;
    for(k=2;k<exp;k++)
        if(!ciur[k])
        {
            rad=radacina(x,k);
            if(rad>1)
                rez=rez+rad-f(rad,k);
        }
    return rez;
}

int main()
{
    fscanf(fin,"%d",&T);
    Ciur();
    while(T)
    {
        fscanf(fin,"%lld %lld",&a,&b);
        fprintf(fout,"%lld\n",f(b)-f(a-1));
        T--;
    }
}
