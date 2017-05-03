
C++ source code
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <time.h>
#include <fstream>
#include <limits>
#include <iomanip>
#include <iterator>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define E 2.71828182845904523536
using namespace std;


long long int fact(int n)
{
    return ((n > 1) ? (n*fact(n-1)) : (1));
}
int main()
{
    int n,k;
    while(scanf("%d %d", &n, &k) == 2)
    {
        long long int T, output=1;
        for (int i=0; i<k; i++)
        {scanf("%lld", &T); output *= fact(T);}

        output = fact(n)/output;
        cout << output << endl;
    }
    return 0;
}
