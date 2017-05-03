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
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define E 2.71828182845904523536
#define long long LL
using namespace std;

int main()
{
    int correctN, testN, counter=0;
    char Input[100000];
    while(gets(Input) != NULL)
    {
        counter++;

        correctN = atoi(Input);
        if (correctN == 0) return 0;
        string CO="", FCO="", TO="", FTO="";

        for (int i=0; i<correctN; i++)
        {
            gets(Input);
            CO += Input;
            if (i > 0) CO += '\n';
            for (int i=0; i<strlen(Input); i++)
                if (isdigit(Input[i])) FCO += Input[i];

        }

        bool AC=true, PE=false;
        gets(Input);
        testN = atoi(Input);

        for (int i=0; i<testN; i++)
        {
            gets(Input);
            TO += Input;
            if (i > 0) TO += '\n';
            for (int i=0; i<strlen(Input); i++)
                if (isdigit(Input[i])) FTO += Input[i];

        }

        if (FTO != FCO) AC = false;
        if (CO != TO) PE = true;

        cout << "Run #" << counter << ": ";
        if (!AC) cout << "Wrong Answer";
        else if (AC && PE) cout << "Presentation Error";
        else cout << "Accepted";

        cout << "\n";

    }
    return 0;
}
