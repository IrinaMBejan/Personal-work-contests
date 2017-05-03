#include <fstream>
#include<cstring>
using namespace std;
ifstream fin("sl.in");
ofstream fout("sl.out");

struct inst
{
    char s[10];
    int nr;
} Prog[1005];

int stiva[1005];
int store;

int main()
{
    int n,i;
    fin>>n;
    for(i=0; i<n; i++)
    {
        fin>>Prog[i].s;
        if(strcmp(Prog[i].s,"PUSH")==0 || strcmp(Prog[i].s,"IFZERO")==0)
            fin>>Prog[i].nr;
    }
    int st = 1, fi = 0;
    for(i=0; i<n; i++)
    {
        if(strcmp(Prog[i].s,"PUSH") ==0)
            stiva[++fi] = Prog[i].nr;
        else if(strcmp(Prog[i].s,"STORE") ==0)
        {
            store = stiva[fi];
            fi--;
        }
        else if(strcmp(Prog[i].s,"LOAD") ==0)
            {
                fi++;
                stiva[fi] = store;
            }
        else if(strcmp(Prog[i].s,"PLUS") ==0)
        {
            stiva[fi-1] +=stiva[fi];
            fi--;
        }
        else if(strcmp(Prog[i].s,"TIMES") ==0)
        {
            stiva[fi-1] *=stiva[fi];
            fi--;
        }
        else if(strcmp(Prog[i].s,"IFZERO") ==0 && stiva[fi] == 0)
            i = Prog[i].nr-1;
        else if(strcmp(Prog[i].s,"DONE") ==0)
        {
            fout<<stiva[fi]<<'\n';
            i=n+1;
        }
    }
    return 0;
}
