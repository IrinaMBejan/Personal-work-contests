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

    while(1)
    {
        int m,n;
        cin >> m >> n;
        if (m == 0 && n == 0) break;
        int carry=0, ncarries =0;
        while( m > 0 || n > 0)
        {
            carry =  (m%10 + n%10 + carry)/10;
            m/= 10;
            n /= 10;
            if (carry) ncarries++;
        }

        if (ncarries == 0) cout << "No carry operation.\n";
        else cout << ncarries << " carry operation" << ((ncarries > 1) ? ("s.\n") : (".\n"));
    }
    return 0;
}
