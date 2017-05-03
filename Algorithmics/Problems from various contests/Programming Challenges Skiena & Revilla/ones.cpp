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
    long long int N;
    while(scanf("%lld",&N) == 1)
    {
        int nDigits=0, NewMod=0;
            do
            {
                NewMod = (10*NewMod + 1)%N;
                nDigits++;
            }while(NewMod);

        cout << nDigits << endl;
    }


    return 0;
}
