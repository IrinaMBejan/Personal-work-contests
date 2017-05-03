#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define MMAX    2000000001
using namespace std;

int table[700000];
int size = 0;

void gen_numbers()
{
    table[0] = 1;
    table[1] = 2;
    table[2] = 4;
    int i = 1;
    for (; table[table[i] - 1] < MMAX; ++i)
        for (int j = table[i]; j < table[i + 1]; ++j)
            table[j] = table[j - 1] + i + 1;
    size = table[i] - 1;
}

int main(int argc, char* argv[])
{
    //freopen("input.in", "r", stdin);
    //freopen("output.out", "w", stdout);
    int n;
    gen_numbers();
    while (cin >> n && n)
    {
        cout << upper_bound(table, table + size, n) - table << endl;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
