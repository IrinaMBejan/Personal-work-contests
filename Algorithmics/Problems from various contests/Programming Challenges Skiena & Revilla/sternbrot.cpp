
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

    int m, n;

    while(1)
    {
        cin >> m >> n;
        if (m == 1 && n == 1) return 0;

        int Nm=1, Nn=1, NFm = 0, NFn = 1, NMn = 0, NMm = 1;
        string output ="";
        double value = (double)m/n;


        for(;Nm != m || Nn != n;Nm = NFm + NMm,Nn = NFn + NMn)
            if (value > (double)Nm/Nn)
                NFn = Nn,NFm = Nm,output += "R";
            else
                NMn = Nn,NMm = Nm,output += "L";

        cout << output << endl;

    }
    return 0;
}
