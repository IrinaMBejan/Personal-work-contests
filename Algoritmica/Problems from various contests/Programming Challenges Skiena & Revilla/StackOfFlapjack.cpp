include <iostream>
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


bool isSorted(vector<int> Pancakes)
{
    for (int i=0; i<Pancakes.size()-1; i++)
        if (Pancakes[i] > Pancakes[i+1]) return false;

    return true;
}

bool moveLargestToFirst(vector<int> &Pancakes,int end, string &Moves)
{
    int Largest = -1;
    for (int i=0; i< end; i++)
    {
        if (i == 0 || Pancakes[i] > Pancakes[Largest]) Largest = i;
    }
    if (Largest == 0) return true;
    if (Largest == end-1) return false;

    reverse(Pancakes.begin(), Pancakes.begin() + Largest + 1);
    ostringstream s;
    s << Pancakes.size() - Largest;
    Moves+= s.str() + " ";

    return true;
}
int main()
{
    char Input[5000];
    while(gets(Input))
    {
        string Moves="";
        vector<int> Pancakes;
        stringstream s(Input);

        while(!s.eof())
        {
            int T;
            s >> T;
            cout << T << " ";
            Pancakes.push_back(T);
        }
        cout.seekp((int)cout.tellp()-1);
        cout << endl;
        s.clear();
        for (int i=Pancakes.size(); !isSorted(Pancakes); i--)
        {
            if(moveLargestToFirst(Pancakes,i, Moves))
                {
                    ostringstream ss;
                    ss << Pancakes.size() - i  + 1;
                    reverse(Pancakes.begin(), Pancakes.begin() + i);

                    Moves+= ss.str()  + " ";
                }
        }

        cout << Moves << "0\n";

    }

    return 0;
}
