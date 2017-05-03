#include <fstream>
#define Nmax 10005
using namespace std;
ifstream fin("gaina.in");
ofstream fout("gaina.out");

int N, i, t;
int h[Nmax], hmax[Nmax], cost[Nmax];
void Citire();
int Costt();

int main()
{
    Citire();//caut max
    hmax[N]=N;
    for( i=N-1; i>=1; i--)
        if(h[i+1]>=h[hmax[i+1]])
            hmax[i]=i+1;
        else
            hmax[i]=hmax[i+1];
    //cauta costuri
    cost[N]=0;
    for(i=N-1; i>=1; i--)
        if(h[i]>=h[hmax[i]])
            cost[i]=Costt();
    fout<<cost[1]<<'\n';
    return 0;
}

void Citire()
{
    int i;
    fin>>N;
    for(i=1; i<=N; i++)
        fin>>h[i];
}

int Costt()
{
    int x;
    if (hmax[i]==i+1&& h[hmax[i]]==h[i])
        x=cost[hmax[i]];
    else
    {
        t=cost[hmax[i]]+(hmax[i]-i-1)-(h[i]-h[hmax[i]]);
        if( hmax[i]==i+1)
            t=t+1;
        if(t<=0)
            x=1;
        else
            x=t;
    }
    return x;
}
