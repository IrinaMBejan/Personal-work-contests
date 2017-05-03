#include <cstdio>
#include <algorithm> // std::min, std::max
using namespace std;

int cic(int);
const int CACHE_LEN = 1000001;
short cache[CACHE_LEN] = {0};

int main()
{
    cache[1] = 1;
    int x, y, minNo, maxNo;
    while ( scanf("%d%d", &x, &y) != EOF )
    {
        int resmax = 0;
        minNo = min(x, y);
        maxNo = max(x, y);
        for (int i = minNo; i <= maxNo; ++i )
        {
            int res = cic(i);
            if (res > resmax) resmax = res;
        }
        printf("%d %d %d\n", x, y, resmax);
    }
    return 0;
}

int cic(int start)
{
    if(cache[start])
        return cache[start];

    int res = 1;
    long long int current = start;

    while (current != 1)
    {
        if(current < 1000000)
            if(cache[current])
        {
            return cache[start] = res -1 + cache[current];
        }

        if (current % 2 == 0) current >>= 1;
        else current = 3 * current + 1;
        res++;
    }
    cache[start] = res;
    return cache[start];
}
