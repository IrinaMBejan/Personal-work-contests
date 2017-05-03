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
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define E 2.71828182845904523536
using namespace std;


int main()
{
    int N;

    cin >> N;

    for (int i=0; i<N; i++)
    {
        vector<int> streets;

        int R;
        cin >> R;

        for (int j=0; j<R; j++)
        {
            int T;
            cin >> T;
            streets.push_back(T);
        }
        sort(streets.begin(), streets.end());
        int best;

        best = streets[ streets.size()/2 ];

        long long int TotalDistance=0;
        for (int j=0; j<streets.size(); j++) TotalDistance += abs(best - streets[j]);
        cout << TotalDistance;
        cout << endl;
    }

    return 0;
}
