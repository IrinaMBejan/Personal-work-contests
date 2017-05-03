#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm> // std::min, std::max
#include <cmath>
using namespace std;

double a[10005];
int main()
{
    int x, y,i,j,k, counter = 0;
    scanf("%d", &x);
    while(x)
    {
        double s = 0;
        for(i = 1; i<=x; i++)
        {
            scanf("%lf",&a[i]);
            s+=a[i];
        }
        double per = (double)s/x;
        double negativeSum = 0 , positiveSum = 0, delta= 0;

        for(i = 1; i<=x;i++)
        {
            delta = (double) (long) ((a[i] - per) * 100.0) / 100.0;
            if (delta < 0) {
				negativeSum += delta;
			} else {
				positiveSum += delta;
			}
        }

        printf("$%.2lf\n",(-negativeSum > positiveSum) ? -negativeSum : positiveSum);

        scanf("%d", &x);

    }
    return 0;
}
