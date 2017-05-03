#include <cstdio>
#include <algorithm>
#include <cstring>
#define Nmax 50005
#define Lgmax 17
using namespace std;
FILE* fin=fopen("aperm.in","r");
FILE* fout=fopen("aperm.out","w");

struct val
{
    char s[Lgmax];
    unsigned short poz;
} Perm[Nmax];

int comp(val a, val b)
{
    int rez=strcmp(a.s,b.s);
    return (rez<0 || (rez==0 && a.poz<b.poz));
}
int n,p;
int main()
{

    fscanf(fin, "%d %d",&n,&p);
    int i,j,x;

    for(i=1; i<=n; i++)
    {
        Perm[i].poz=i;
        for(j=0; j<p; j++)
        {
            fscanf(fin,"%d",&x);
            if(x<10)
                Perm[i].s[j]=x+'0';
            else
                Perm[i].s[j]=x-10+'A';
        }
    }

    sort(Perm+1,Perm+n+1,comp);

    for(i=1; i<=n; i++)
        fprintf(fout,"%d\n",Perm[i].poz);
    return 0;
}
