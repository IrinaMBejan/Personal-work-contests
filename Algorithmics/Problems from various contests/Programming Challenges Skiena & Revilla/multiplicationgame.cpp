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


int main()
{

    long long int n;

    while(scanf("%lld",&n) == 1)
    {
         long long int lo;
         long double lg = logl(n)/logl(18);
        lo = floorl(lg);
        if (lg - lo < 0.00000000001) {cout << "Ollie wins.\n";continue;}
        if ( n/powl(18.0,lo) > 9.0 ) cout << "Ollie wins.\n";
        else cout << "Stan wins.\n";
    }
    return 0;
