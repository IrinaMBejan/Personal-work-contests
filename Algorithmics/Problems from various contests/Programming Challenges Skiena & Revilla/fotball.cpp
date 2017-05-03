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

struct Team
{
    int nGames, nWins,nTies,nLoss, nGoals, nGoalsAgainst, nPoints;
    string Name;
    Team(string TN)
    {
        nGames = nWins = nTies = nLoss = nGoals = nGoalsAgainst = 0;
        Name = TN;
    }
    Team()
    {
        nGames = nWins = nTies = nLoss = nGoals = nGoalsAgainst = 0;
    }

};

bool CompareTeams(pair<string,Team> e1, pair<string,Team> e2)
{
    Team a = e1.second;
    Team b = e2.second;
    int PointsA = a.nWins*3 + a.nTies;
    int PointsB = b.nWins*3 + b.nTies;
    int GDA = a.nGoals - a.nGoalsAgainst;
    int GDB = b.nGoals - b.nGoalsAgainst;

    if (PointsA != PointsB) return PointsA > PointsB;

    if (a.nWins != b.nWins) return a.nWins > b.nWins;

    if (GDA != GDB) return GDA > GDB;

    if (a.nGoals != b.nGoals) return a.nGoals > b.nGoals;

    if (a.nGames != b.nGames) return a.nGames < b.nGames;


    for(int i=0; i<(int)a.Name.length(); i++) a.Name[i] = tolower(a.Name[i]);
    for(int i=0; i<(int)b.Name.length(); i++) b.Name[i] = tolower(b.Name[i]);

    return a.Name < b.Name;
}
int main()
{
    int N;
    scanf("%d\n",&N);

    for (int i=0; i<N; i++)
    {
        int nTeams;
        char TournName[1000];
        gets(TournName);
        scanf("%d\n",&nTeams);

        map<string, Team> Teams;

        for (int j=0; j<nTeams; j++)
        {
            char TeamName[1000];
            gets(TeamName);
            Team T(TeamName);
            Teams.insert(make_pair(TeamName,T));
        }
        int nGames;
        scanf("%d",&nGames);
        char Game[1000];

        gets(Game);

        for (int j=0; j<nGames; j++)
        {
            gets(Game);
            char buff;
            stringstream s(Game);
            string TeamNameA, TeamNameB;
            int GoalsA, GoalsB;


            getline(s,TeamNameA,'#');
            s >> GoalsA >> buff >> GoalsB >> buff;
            getline(s,TeamNameB);

            Teams[TeamNameA].nGames++;
            Teams[TeamNameB].nGames++;
            Teams[TeamNameA].nGoals+= GoalsA;
            Teams[TeamNameB].nGoals+= GoalsB;
            Teams[TeamNameA].nGoalsAgainst += GoalsB;
            Teams[TeamNameB].nGoalsAgainst += GoalsA;

            if (GoalsA == GoalsB) Teams[TeamNameA].nTies++, Teams[TeamNameB].nTies++;
            else if (GoalsA > GoalsB) Teams[TeamNameA].nWins++, Teams[TeamNameB].nLoss++;
            else  Teams[TeamNameA].nLoss++, Teams[TeamNameB].nWins++;


        }


        vector< pair<string, Team> > SortedTeams;

        copy(Teams.begin(), Teams.end(), back_inserter(SortedTeams));

        sort(SortedTeams.begin(), SortedTeams.end(), CompareTeams);

        printf("%s\n", TournName);
        for (int j=0; j<SortedTeams.size(); j++)
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
            j+1, SortedTeams[j].first.c_str(), SortedTeams[j].second.nWins*3 + SortedTeams[j].second.nTies, SortedTeams[j].second.nGames,
            SortedTeams[j].second.nWins, SortedTeams[j].second.nTies, SortedTeams[j].second.nLoss,
            SortedTeams[j].second.nGoals - SortedTeams[j].second.nGoalsAgainst, SortedTeams[j].second.nGoals, SortedTeams[j].second.nGoalsAgainst);

        if (i != N-1) printf("\n");
    }
    return 0;
}
