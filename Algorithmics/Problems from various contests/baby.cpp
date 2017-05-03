#include <cstdio>
#include <algorithm>
#define NRT 100005
using namespace std;

FILE* fin=fopen("baby.in","r");
FILE* fout=fopen("baby.out","w");


struct bebe
{
    int a;
    int b;
};

bool compare(bebe a, bebe b)
{
    return a.a+a.b>b.a+b.b;
}
bebe x[NRT];

int main()
{
    int n,m,k,j,i,s=0;
    fscanf(fin,"%d", &n);
    int nrt,dif;
    for(k=1;k<=n;k++)
    {
        fscanf(fin,"%d",&m);
        for(j=1;j<=m;j++)
            fscanf(fin,"%d %d", &x[j].a,&x[j].b);
        x[m+1].a=0;
        x[m+1].b=0;
        sort(x+1,x+m+1,compare);
        s=0;
        for(i=m;i>=1;i--)
        {
            if (x[i].b<=s) break;
            s+=x[i].a;
        }
        if(i==0) fprintf(fout,"1\n");
        else fprintf(fout,"0\n");
    }
    return 0;
}

/* Ana se ocupa de babysitting. Se da un numar N, reprezentand numarul de zile in care se va ocupa
cu babysittingul. Pentru fiecare zi, se va da un numar M, reprezentand numarul de copii pe care-i
ingrijeste,si pe urmatoarele i randuri vor fi doua numere, reprezentand x-timpul in care Ana il adoarme
pe copilul i si y - cat doarme copilul i. Ana adoarme copiii intr-o ordine cat mai eficienta a.i
sa doarma si ea. Daca reuseste afisati 1 pentru ziua respectiva, daca nu afisati 1.
*/
