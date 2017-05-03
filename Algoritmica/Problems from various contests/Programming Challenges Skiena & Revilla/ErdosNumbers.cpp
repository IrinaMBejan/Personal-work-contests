#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<cstdio>
#include<sstream>
#include<algorithm>
using namespace std;

vector<int> G[1000];
queue<int> Q;

map<string,int> ErdosNumbers;
map<string,bool> Visited;


void ComputeErdosNumbers(map<string,vector<string> > CoAuthors, bool start)
{
    vector<string> oldList, newList;

    for (int i=0; i<CoAuthors["Erdos, P."].size(); i++)
        ErdosNumbers[CoAuthors["Erdos, P."][i]] = 1;
    newList = CoAuthors["Erdos, P."];

    while(!newList.empty())
    {
        for (int i=0; i<newList.size(); i++)
            for (int j=0; j< CoAuthors[newList[i]].size(); j++)
                if (ErdosNumbers[CoAuthors[newList[i]][j]]  >  ErdosNumbers[newList[i]] + 1
                        || ErdosNumbers[CoAuthors[newList[i]][j]] == -1)
                {
                    ErdosNumbers[CoAuthors[newList[i]][j]] = ErdosNumbers[newList[i]] + 1;
                    oldList.push_back(CoAuthors[newList[i]][j]);
                }

        newList = oldList;
        oldList.clear();
    }
}

vector < string > extract_name(string &line)
{
    vector < string > list;
    string::size_type begin(0);
    string::size_type end = line.find(".,", begin);

    while (end != string::npos)
    {
        list.push_back(line.substr(begin, end - begin + 1));

        begin = end + 3;
        end = line.find(".,", begin);
    }

    if (begin < (line.length() - 1))
        list.push_back(line.substr(begin));

    return list;
}

int main()
{
    int tests,N,P;
    char PaperString[10000];
    string names;
    int r = 0;
    scanf("%d",&tests);
    while(tests--)
    {
        r++;
        scanf("%d%d\n",&P,&N);
        map<string,vector<string> > CoA;

        int i, k = 1;
        for(i = 1; i <= P; i++)
        {
            gets(PaperString);
            vector<string> PaperAuthors;
            stringstream s(PaperString);

            getline(s,names,':');
            PaperAuthors = extract_name(names);

            for(k = 0; k<PaperAuthors.size(); k++)
                ErdosNumbers[PaperAuthors[k]] = -1;

            for(k = 0; k<PaperAuthors.size(); k++)
                for(int h = 0; h<PaperAuthors.size(); h++)
                    if(PaperAuthors[h]!=PaperAuthors[k])
                    {
                        if(find(CoA[PaperAuthors[k]].begin(), CoA[PaperAuthors[k]].end(), PaperAuthors[h]) == CoA[PaperAuthors[k]].end())
                            CoA[PaperAuthors[k]].push_back(PaperAuthors[h]);
                    }
        }
        ErdosNumbers["Erdos,P."] = 0;


        char name[10000];
        vector<string> ANames;
        for(int j = 0; j<N; j++)
        {
            gets(name);
            ANames.push_back(name);
        }

        ComputeErdosNumbers(CoA,true);
        cout<<"Scenario "<<r<<'\n';
        for(int j = 0; j<N; j++)

        {
            cout<<ANames[j]<<" ";
            map<string,int>::iterator it = ErdosNumbers.find(extract_name(ANames[j])[0]);
            if(it == ErdosNumbers.end() || it->second == -1)
                cout<<"infinity";
            else cout <<it->second;
            cout<<'\n';
        }

    }
}
