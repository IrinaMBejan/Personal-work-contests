#include <iostream>
#include <cstdio>
#include<bitset>
#include<vector>
#include<utility>
#include<cstring>
using namespace std;

const int NMAX = 150;
const int leng = 260;

struct pereche
{
    int nr;
    char sir[leng];
};

bitset<NMAX> vec;
vector< pereche > l[NMAX];
char s[NMAX][leng];
int lg[NMAX];
int m;
void solve();
int main()
{
    int n,v;
    int i,j;

    cin>>v;
    cin.get();
    cin.get();
    n = v;
    while(n--)
    {
        if(n!=v-1)
            cout<<'\n';
        m = 0;
        int sum = 0;
        int N;
        do
        {
            cin.getline(s[++m],256);
            lg[m] = strlen(s[m]);
            sum += lg[m];
        }
        while(s[m][0]== '0' || s[m][0] == '1');
        m--;
        N = sum/(m/2);
        for(i = 1; i<=m; i++)
            l[i].clear();
        pereche a;
        for(i = 1; i<=m; i++)
            for(j = 1; j <= m; j++)
                if(i != j && lg[i] + lg[j] == N)
                {
                    strcpy(a.sir, s[i]);
                    strcat(a.sir, s[j]);
                    a.nr = j;
                    //cout<<sir<<'\n';
                    l[i].push_back(a);
                    a.nr = j;
                    l[j].push_back(a);
                }

        solve();
    }
}

void solve()
{
    int i,j,k,q;
    for(i = 1; i<=m; i++)
    {
        for(j = 0; j<l[i].size(); j++)
        {
            vec.reset();
            //picked one from the list;
            vec[i].flip();
            vec[l[i][j].nr].flip();
            //cout<<i<<" "<<j<<" "<<l[i][j].sir<<'\n';

            for(k = 1; k<=m; k++)
                if(vec[k] == 0)
                {
                    for(q = 0; q<l[k].size(); q++)
                        if(strcmp(l[i][j].sir, l[k][q].sir) == 0)
                        {

                            vec[k].flip();
                            vec[l[k][q].nr].flip();
                            break;
                        }
                    // else
                    //  cout<<l[i][j].sir<<" "<<l[k][q].sir<<'\n';
                }

            int ok = 1;
            for(k = 1; k<=m; k++)
                if(vec[k] == 0)
                {
                    ok = 0;
                    break;
                }

            if(ok)
            {
                cout<<l[i][j].sir<<'\n';
                return;
            }


        }

    }
}
