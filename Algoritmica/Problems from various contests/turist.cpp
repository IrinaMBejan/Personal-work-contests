#include <cstdio>

using namespace std;
FILE* fin=fopen("turist.in","r");
FILE* fout=fopen("turist.out","w");

int dd[8];

int main()
{
    int N,M,x,y,n,a,b,max,i;
    fscanf(fin,"%d %d",&N,&M);
    fscanf(fin,"%d %d",&x,&y);
    fscanf(fin,"%d",&n);
    for(i=1; i<=n; i++)
    {
        fscanf(fin,"%d %d",&a,&b);
        if(a<x&&b==y) dd[0]++;
        else if(a<x&&b>y&&x-a==b-y) dd[1]++;
        else if(a==x&&b>y) dd[2]++;
        else if(a>x&&b>y&&a-x==b-y) dd[3]++;
        else if(a>x&&b==y) dd[4]++;
        else if(a>x&&b<y&&a-x==y-b) dd[5]++;
        else if(a<x&&b<y&&x-a==y-b) dd[7]++;
        else if(a==x&&b<y) dd[6]++;
    }
    max=dd[0];
    for(i=1; i<=7; i++)
        if(dd[i]>max) max=dd[i];
    fprintf(fout,"%d\n",max);
    return 0;
}
