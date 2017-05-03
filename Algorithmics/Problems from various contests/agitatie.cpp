#include <fstream>
#define LGMAX 3005
#define LIM 3000
using namespace std;
ifstream fin("agitatie.in");
ofstream fout("agitatie.out");

struct candidat
{
    int ag;
    int se;
} A[LGMAX];

long long int Smin[2][LGMAX];
int ag(int ord, int timp);
int min(int a, int b);
int main()
{
    int N,i,S=0,t,succ=1,prev=0;

    //citire
    fin>>N;
    for(i=1; i<=N; i++)
        fin>>A[i].ag>>A[i].se;

    //recurenta
    for(i=1; i<=N; i++)
    {
        S+=A[i].ag; //suma ag initiale a candidatilor 1,2...i;
        Smin[succ][0]=S;
        for(t=1; t<=LIM; t++)
            Smin[succ][t]=min(ag(i,t)+Smin[prev][t],Smin[succ][t-1]);
        succ=1-succ;
        prev=1-prev;
    }
    fout<<Smin[prev][LIM]<<'\n';;
    return 0;
}

int ag(int ord, int timp)
{
    int res=A[ord].ag*A[ord].se+timp;
    if(res<0)
        return -res;
    return res;
}

int min(int a, int b)
{
    if (a>b) return a;
    return b;
}
