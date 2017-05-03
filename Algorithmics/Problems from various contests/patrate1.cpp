#include <cstdio>
#include<cmath>
#define Nmax 100010
using namespace std;
FILE* fin=fopen("patrate1.in","r");
FILE* fout=fopen("patrate1.out","w");
int A[Nmax], B[Nmax], C[Nmax],p,n,a,b,c;

int verif(int x)
{
    int i,j;
    for(i=1; i<=9999; i++)
    {
        if(x<i*i) break;
        j=int(sqrt((double)x-i*i));
        if(j*j+i*i!=x) continue;
        a=i;
        b=j;
        return 1;
    }
    return 0;
}
int cauta(int x)
{
    int i;
    for(i=1; i<=999; i++)
        if(verif(x+i*i))
        {
            c=i;
            return x+i*i;
        }
    return -1;
}


int main()
{
    int j,lg,i;
    fscanf(fin,"%d %d",&n,&p);
    j=2;
    lg=1;
    A[0] = B[0] = 1;
    for(i=3; i<=n; i++)
    {
        j=cauta(j);
        A[lg]=a;
        B[lg]=b;
        C[lg]=c;
        lg++;
    }
    fprintf(fout,"%d\n",j);
    int k;
    for(i=p; i<=n; i++)
    {
        k=n-i;
        fprintf(fout,"%d %d ",A[k],B[k]);
        for(j=k+1; j<=lg-1; j++) fprintf(fout,"%d ",C[j]);
        fprintf(fout,"\n");
    }
    return 0;
}
