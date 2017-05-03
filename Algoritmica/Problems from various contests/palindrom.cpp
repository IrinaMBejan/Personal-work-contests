#include <fstream>
#include<cstring>
#define Nmax 11
using namespace std;
ifstream fin("palindrom1.in");
ofstream fout("palindrom1.out");
typedef short int NRMARE[1000005];

int mat[Nmax][Nmax];
int vals[Nmax][Nmax];
int T[Nmax], Tmax[Nmax];

NRMARE a;
int na;
void citire(NRMARE a, int& na);
void afisare(NRMARE a, int na);
int impartire(NRMARE a, int na, int k);
int main()
{
    int i,cif,k,r;
    for(i=0; i<=9; i++)
        fin>>T[i];
    for(i=0; i<=9; i++)
    {
        cif=T[i];
        k=0;
        while(mat[i][cif]==0)
        {
            vals[i][++k]=cif;
            if(cif>Tmax[i]) Tmax[i]=cif;
            mat[i][cif]=1;
            cif=T[cif];
        }
        vals[i][0]=k;
    }
    citire(a,na);
    fin>>k;
    //cerinta 1
    for(i=0; i<na; i++)
      {
          fout<<Tmax[a[na-i-1]];
          a[i]=Tmax[a[i]];
      }
    fout<<'\n';



    r=impartire(a,na,k);
    //fout<<r<<" ";

    //cerinta 2
    int med1,rat,poz,start;
    med1=na/2-1;
    poz=med1;
    int nrs=0;
      while(r!=0)
    {
            nrs++;
            for(i=poz;i>=0;i--)
            {
                start=a[i];
                a[i]=vals[a[i]][nrs+1];
                a[med1+1+poz-i]=a[i];
                if(impartire(a,na,k)==0)
                { afisare(a,na); return 0;}
                a[i]=start;
                a[med1+1+poz-i]=start;
            }
    }

    return 0;
}

void citire(NRMARE a, int& na)
{
    char s[1000005];
    fin>>s;
    int i,lg=strlen(s);
    for(i=0; i<lg; i++)
        a[i]=s[lg-i-1]-'0';
    na=lg;
}

void afisare(NRMARE a, int na)
{
    int i;
    for(i=na-1; i>=0; i--)
        fout<<a[i];
    fout<<'\n';
}

int impartire(NRMARE a, int na, int k)
{
    int i, T=0;
    for(i=na-1; i>=0; i--)
    {
        T=T*10+a[i];
        T%=k;
    }
    return T;
}
