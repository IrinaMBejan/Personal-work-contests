#include <cstdio>
#define LGMAX 10001
using namespace std;
FILE* fin=fopen("subsets.in","r");
FILE* fout=fopen("subsets.out","w");
typedef short int NRMARE[LGMAX];

NRMARE s;
int ns;

void prodint (NRMARE a, int& na, int b);
void afisare(NRMARE c, int nc);

int main()
{
    int n,i;
    fscanf(fin,"%d",&n);
    ns=1;
    s[0]=1;
    for(i=1;i<n;i++)
        prodint(s,ns,2);
    prodint(s,ns,n);
    afisare(s,ns);
    return 0;
}

void prodint (NRMARE a, int &na, int b)
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

void afisare(NRMARE c, int nc)
{
    int i;
    for(i=nc-1;i>=0;i--)
        fprintf(fout,"%d",c[i]);
    fprintf(fout,"\n");
}
