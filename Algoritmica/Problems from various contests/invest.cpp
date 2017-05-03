#include <cstdio>
#define NMAX 101
using namespace std;
FILE* fin=fopen("invest.in","r");
FILE* fout=fopen("invest.out","w");

double TB[NMAX],SB[NMAX],TT[NMAX],ST[NMAX];
double Sm[NMAX];
double max1(double a, double b);
double max2(double a,double b,double c);
int main()
{
    int N,i;
    fscanf(fin,"%d",&N);
    for(i=1;i<=N;i++)
        fscanf(fin,"%lf",&TB[i]);
    for(i=1;i<=N;i++)
        fscanf(fin,"%lf",&SB[i]);
    for(i=1;i<=N;i++)
        fscanf(fin,"%lf",&TT[i]);
    for(i=1;i<=N;i++)
        fscanf(fin,"%lf",&ST[i]);
    Sm[0]=100;
    for(i=1;i<=5;i++)
        Sm[i]=max1(Sm[i-1],(Sm[i-1]-TB[i])*SB[i]);
    for(i=6;i<=N;i++)
        Sm[i]=max2(Sm[i-1],(Sm[i-1]-TB[i])*SB[i],(Sm[i-6]-TT[i-5])*ST[i-5]);
    fprintf(fout,"%lf",Sm[N]);
    return 0;
}

double max1(double a, double b)
{
    if(a>b) return a;
    return b;
}

double max2(double a,double b,double c)
{
    double max=a;
    if(b>max) max=b;
    if(c>max) max=c;
    return max;
}
