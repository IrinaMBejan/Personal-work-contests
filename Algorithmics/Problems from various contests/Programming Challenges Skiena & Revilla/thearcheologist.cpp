
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



int main()
{
    long long int  P;
    long double C = C = logl(10)/logl(2);
    while(scanf("%lld",&P) == 1)
    {
        long double T, LP, LPP;
        LP = logl(P)/logl(2);

        LPP = logl(P+1)/logl(2);
        T = floorl( log10l(P)) + 2;

        for (; ceill(LP + T*C) != floorl(LPP + T*C); T++);

        cout << (long long int)floorl(LPP + T*C) << '\n';



    }


    return 0;
}

