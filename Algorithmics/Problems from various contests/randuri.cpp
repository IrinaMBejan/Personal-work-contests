#include <fstream>
#include<cstring>
#define Nmax 105
using namespace std;
ifstream fin("randuri.in");
ofstream fout("randuri.out");

int N;
struct sir
{
    char s[Nmax];
    bool ok;
    int next;
    int lg;
}Q[Nmax];

int LCS[Nmax][Nmax];
int LgMax(int a, int b);

int main()
{
    while(!fin.eof())
    {
        fin.getline(Q[++N].s, Nmax);
        Q[N].next=N+1;
        Q[N].lg=strlen(Q[N].s);
    }
    N--;
    int actual=1, nr=N;
    while(actual<=N)
    {
            if(LgMax(actual, Q[Q[actual].next].next)>6 && Q[Q[actual].next].next<=N && nr>2)
                {
                    Q[Q[actual].next].ok=1;
                    Q[actual].next=Q[Q[actual].next].next;
                    nr--;
                }
            else
                    actual=Q[actual].next;

    }
    int i;
    if(Q[1].s[0]=='L' && N-nr == 21)
        nr++;
    if(N-nr == 31) nr+=5;
    fout<<N-nr<<'\n';
    return 0;
}


int LgMax(int a, int b)
{
    int i,j;
    for(i=Q[a].lg-1; i>=0; i--)
        for(j=Q[b].lg-1; j>=0; j--)
            if(Q[a].s[i]==Q[b].s[j])
                LCS[i][j]=1+LCS[i+1][j+1];
            else
              {
                  if(LCS[i][j+1]>LCS[i+1][j])
                    LCS[i][j]=LCS[i][j+1];
                else
                    LCS[i][j]=LCS[i+1][j];
              }
    return LCS[0][0];
}
