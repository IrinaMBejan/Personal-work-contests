#include <cstdio>
#define NMAX 10001
using namespace std;
FILE* fin=fopen("rafturi.in","r");
FILE* fout=fopen("rafturi.out","w");

int h[NMAX];
int Smin[5];
int max2(int a,int b);
int max3(int a,int b,int c);
int main()
{
    int C,N,i,a,b,j;
    fscanf(fin,"%d %d",&C,&N);
    for(i=1; i<=N; i++)
    {
        fscanf(fin,"%d %d",&a,&b);
        if(h[a]<b) h[a]=b;
    }
    Smin[1]=h[1];
    Smin[2]=max2(h[1],h[2]);
    Smin[3]=max3(h[1],h[2],h[3]);
    for(i=4; i<=C; i++)
    {
        Smin[4]=h[i]+Smin[3];
        if(max2(h[i],h[i-1])+Smin[2]<Smin[4]) Smin[4]=max2(h[i],h[i-1])+Smin[2];
        if(max3(h[i],h[i-1],h[i-2])+Smin[1]<Smin[4]) Smin[4]=max3(h[i],h[i-1],h[i-2])+Smin[1];
        for(j=1; j<=4; j++)
            Smin[j]=Smin[j+1];
    }
    fprintf(fout,"%d\n",Smin[3]);
    return 0;
}

int max2(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

int max3(int a, int b, int c)
{
    int max=c;
    if(a>max) max=a;
    if(b>max) max=b;
    return max;
}
