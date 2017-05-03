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
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define E 2.71828182845904523536
using namespace std;

struct app
{
    int SH, SM, EH, EM;
};

bool compareApps(app a1, app a2)
{
    int a1SM = a1.SH*60 + a1.SM;
    int a2SM = a2.SH*60 + a2.SM;
    return a1SM < a2SM;
}
int main()
{

    int n;
    char Input[256];
    int counter=0;
    while(scanf("%d",&n) == 1)
    {
        counter++;
        gets(Input);


        vector<app> apps;

        for (int i=0; i<n; i++)
        {
            gets(Input);
            app a;
            a.SH = (Input[0] - '0')*10 + Input[1]- '0';
            a.SM = (Input[3]- '0')*10 + Input[4]- '0';
            a.EH = (Input[6]- '0') * 10 + Input[7]- '0';
            a.EM = (Input[9]- '0') * 10 + Input[10]- '0';
            apps.push_back(a);
        }

        sort(apps.begin(), apps.end(), compareApps);
        int maxNapTime=-1, maxStartH, maxStartM;
        string output;

        if (apps[0].SH != 10 || apps[0].SM != 0)
        {
            maxNapTime = apps[0].SH*60 + apps[0].SM - 10*60;
            maxStartH = 10;
            maxStartM = 0;

        }
        for (int i=1; i<apps.size(); i++)
        {
            if ((apps[i-1].EH != apps[i].SH || apps[i-1].EM != apps[i].SM) &&
                maxNapTime < apps[i].SH*60 + apps[i].SM - apps[i-1].EH*60 - apps[i-1].EM)
            {
                maxNapTime = apps[i].SH*60 + apps[i].SM - apps[i-1].EH*60 - apps[i-1].EM;
                maxStartH = apps[i-1].EH;
                maxStartM = apps[i-1].EM;
            }
        }


        if (apps.back().EH != 18 && maxNapTime < 18*60 - apps.back().EH*60 - apps.back().EM)
        {
            maxNapTime = 18*60 - apps.back().EH*60 - apps.back().EM;
            maxStartH = apps.back().EH;
            maxStartM = apps.back().EM;

        }

            ostringstream hours;

            if (maxNapTime / 60)
                hours << maxNapTime/60 << " hours and ";

            cout << "Day #" << counter
                << ": the longest nap starts at " << maxStartH/10 << maxStartH%10 << ':' << maxStartM/10 << maxStartM%10 <<
                " and will last for " << hours.str() << maxNapTime%60 << " minutes.\n";


    }
    return 0;
}
