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
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define E 2.71828182845904523536
using namespace std;


struct Record
{
    int EH, ED, EM, D;
    bool exit;
};

bool compareRecords(Record r1, Record r2)
{
    return r1.ED*24*60 + r1.EH*60 + r1.EM <  r2.ED*24*60 + r2.EH*60 + r2.EM;
}
int main()
{
    int N;
    scanf("%d", &N);
    char Input[5000];
    gets(Input);

    gets(Input);
    for (int i=0; i<N; i++)
    {
        int Fares[24];
        map<string, vector<Record> > Photos;



        gets(Input);
        stringstream s(Input);
        for (int i=0; i<24; i++) s >> Fares[i];


        while(fgets(Input,5000,stdin))
        {
            s.str("");
            s.clear();


            if (Input[0] == '\n') break;
            s << Input;

            string License;
            Record R;
            s >> License;
            int Mo;
            char Buff;
            string stat;
            s >> Mo >> Buff >> R.ED >> Buff >> R.EH >> Buff >> R.EM >> stat >> R.D;
            R.exit = (stat == "exit") ? (true) : (false);
            Photos[License].push_back(R);
        }

        for (map<string, vector<Record> >::iterator it = Photos.begin(); it != Photos.end(); it++)
        {
            sort(it->second.begin(), it->second.end(), compareRecords);
            double TotalCost = 0;
            for (int j=0; j<it->second.size(); j++)
            {
                if (it->second[j].exit == false)
                    if (j < it->second.size() - 1 && it->second[j+1].exit)
                    {
                                int DistanceTravelled = abs(it->second[j].D - it->second[j+1].D);
                                double Cost = Fares[it->second[j].EH]/100.0 * (double)DistanceTravelled;
                                TotalCost += Cost + 1;
                    }

            }

            if (TotalCost != 0)cout << it->first << " $" << setprecision(2) << fixed << TotalCost + 2  << endl;
        }

        if (i != N-1) cout << endl;
    }


    return 0;
}
