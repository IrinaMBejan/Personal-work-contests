#include <cstdio>
#include<algorithm>
#define NMAX 100005
#define MAX 1000000000

using namespace std;

FILE* fin = fopen("permutare.in","r");
FILE* fout = fopen("permutare.out","w");

int N,M;
int a[NMAX];

long long int solve()
{
    long long int sol = MAX, s = 0;
    long long int drc = N/2, stc = N/2 - (N%2 == 0);
    long long int drs = 0, sts = 0, drn = 0, stn = 0;
    long long int pointer = drc + 1,i;

    for(i=pointer; i>=1;i--)
    {
        drs = drs + drn;
        drn += a[i];
    }
    drn -= a[i];

    for(i=pointer+1; i<=N;i++)
    {
        sts = sts + stn;
        stn += a[i];
    }
    sts += stn;

    s = sts + drs;
    sol = s;

    for(i=2;i<=N;i++)
    {
        pointer++;
        if(pointer > N)
            pointer = 1;
        drs -= drn;
        drn -= a[i];
        drn += a[pointer];
        drs += drc * a[pointer];

        stn -= a[pointer];
        stn += a[i-1];
        sts += stn;
        sts -= a[pointer]*stc;

        s = sts + drs;
        sol = min(sol,s);
    }

    return sol;
}
int main()
{
    fscanf(fin,"%d %d",&N,&M);
    long long int i,x;
    for(i=1;i<=N;i++)
        fscanf(fin,"%lld",&x);
    a[1] = 1;
    for(i=1;i<M;i++)
    {
        fscanf(fin,"%lld",&x);
        x++;
        if(x>N) x = 1;
        a[x]++; //how many times u have a line with dist x
    }
    fclose(fin);

    fprintf(fout,"%lld",solve());
    fclose(fout);
    return 0;
}
