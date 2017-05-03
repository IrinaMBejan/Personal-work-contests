#include <cstdio>
#include<math.h>
#define LMAX 1001
using namespace std;
FILE* fin=fopen("holo.in","r");
FILE* fout=fopen("holo.out","w");

double init[LMAX], final[2*LMAX];
int main()
{
    int n, m, i, j;
    double d1, d2, sq = 0;
    fscanf(fin,"%d %d",&n,&m);
    d1 = (double)10000 / n;
    d2 = (double)10000 / (n + m);
    for(i = 1; i <= n; i++)
        init[i] = d1 * i;
    for(i = 1; i <= n + m; i++)
        final[i] = d2 * i;
    for(i = 1; i <= n; i++)
    {
        j = 1;
        while(init[i] > final[j])
            j++;
        if(fabs(init[i] - final[j-1]) < fabs( final[j]-init[i]))
            sq += fabs(init[i] - final[j-1]);
        else sq +=fabs( final[j]-init[i]) ;
    }
    fprintf(fout,"%.4lf\n",sq);
    return 0;
}
