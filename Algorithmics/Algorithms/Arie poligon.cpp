#include <cstdio>
#include<cmath>
using namespace std;
FILE* fin=fopen("aria.in","r");
FILE* fout=fopen("aria.out","w");

struct punct
{
    double x;
    double y;
} a[100005];
double arie;

int main()
{
    int n,i;
    fscanf(fin,"%d",&n);
    for(i=0;i<n;i++)
        fscanf(fin,"%lf %lf",&a[i].x,&a[i].y);
    a[n]=a[0];
    for(i=0;i<n;i++)
        arie+=(a[i].x*a[i+1].y-a[i+1].x*a[i].y);
    fprintf(fout,"%lf",fabs(arie/2.0));
    return 0;
}
