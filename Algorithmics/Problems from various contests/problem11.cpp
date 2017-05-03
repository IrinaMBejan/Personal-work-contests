#include <cstdio>
using namespace std;

int main()
{
    float nr[5];
    float n;
    int i;
    n=0;
    for(i=0;i<=4;i++)
        {
            scanf("%f", &nr[i]);
            n=n+nr[i]*nr[i];
        }
    printf("%013.2f",n);
    return 0;
} m
