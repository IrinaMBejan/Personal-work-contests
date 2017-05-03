#include<cstdio>
#include<cmath>
#define LMAX 44750
using namespace std;

unsigned char ciur[LMAX];
FILE* fin=fopen("maxd.in","r");
FILE* fout=fopen("maxd.out","w");

int main()
{
    int a, b, i, j, nrmax=0,max=0,min=200000000,nr,e,rad;
    long int d;
    fscanf(fin,"%d %d",&a, &b);
    for(i=4; i<=LMAX; i+=2)
        ciur[i]=1;
    for(i=3; i*i<=LMAX; i+=2)
        if(!ciur[i])
            for(j=i*i; j<=LMAX; j+=i)
                ciur[j]=1;
    int nrv,p=0;
    for(i=a; i<=b; i++)
    {
        nr=i;
        nrv=1;
        rad=sqrt(nr);
        e=0;
        while(nr%2==0)
        {
            nr=nr/2;
            e++;
        }
        nrv*=(e+1);
        for(j=3; j<=rad && nr>1; j+=2)
            if(!ciur[j])
            {
                e=0;
                while(nr%j==0)
                {
                    nr=nr/j;
                    e++;
                }
                nrv*=(e+1);
            }
        if(nr!=i)
            if(nr>1)
                nrv*=2;
        if(nrv>max)
        {
            nrmax=0;
            min=p;
            max=nrv;
        }
        else if(nrv==max) nrmax++;
        p++;
    }
    fprintf(fout, "%d %d %d\n",min+a,max, nrmax+1);
    return 0;
}
