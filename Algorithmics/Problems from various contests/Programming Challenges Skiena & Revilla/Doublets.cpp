#include<iostream>
#include<cstring>
#include <vector>
#include <queue>
using namespace std;
const int NMAX = 25200;

char dic[NMAX][17];
int viz[NMAX];
vector<int> G[NMAX];
queue<int> Q;
int m;
int lg[NMAX];
void BFS(int st, int target);
bool matches(int a, int b)
{
    if(lg[a] != lg[b]) return 0;
    int i, dif = 0;
    for(i = 0; i<lg[a]; i++)
        {
            if(dic[a][i] != dic[b][i]) dif++;
            if(dif>1) return 0;
        }
    return 1;

}
int main()
{
    m = 0;
    do
    {
        cin.getline(dic[++m], 16);
        lg[m] = strlen(dic[m]);
    }while(dic[m][0] != '\0');
    m--;
    int i,j;
    for(i = 1; i<=m;i++)
        for(j=1;j<=m;j++)
        if(i!=j && matches(i, j))
    {
        G[i].push_back(j);
        G[j].push_back(i);
    }

    char s[50],s1[20],s2[20];
    char*p;
    int nr = 0;
    while(1)
    {
        if(nr !=0 )
            cout<<'\n';
        nr++;
        cin.getline(s,49);
        if(s[0] == '\0')
            return 0;

        p = strchr(s,' ');
        *p = 0;
        strcpy(s1,s);
        strcpy(s2,p+1);

        int poz1, poz2;
        for(i = 1; i<=m;i++)
        {
            if(strcmp(s1, dic[i]) == 0)
            {
                poz1 = i;
            }
            if(strcmp(s2,dic[i])==0)
            {
                poz2 = i;
            }
        }

        BFS(poz2,poz1);

    }
    return 0;
}

void BFS(int st, int target)
{
    while(!Q.empty())
        Q.pop();
    memset(viz,0,sizeof(viz));
    viz[st] = -1;
    Q.push(st);
    bool ok = 0;
    int x, i;
    while( !Q.empty() && !ok)
    {
        x = Q.front(); Q.pop();
        for(i = 0; i<G[x].size();i++)
            if(viz[G[x][i]] == 0)
        {
            Q.push(G[x][i]);
            viz[G[x][i]] = x;
            if(G[x][i] == target)
            {
                int nod = target;
                while(viz[nod] != -1)
                {
                    cout<<dic[nod]<<'\n';
                    nod = viz[nod];
                }
                cout<<dic[st]<<'\n';
                return;
            }
        }
    }
    cout<<"No solution."<<'\n';
}
