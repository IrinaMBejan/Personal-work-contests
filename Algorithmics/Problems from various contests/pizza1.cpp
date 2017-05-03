#include <fstream>
#include<iostream>
#include<math.h>
using namespace std;
ifstream fin("pizza1.in");
ofstream fout("pizza1.out");

int res[23];

struct locatiepizza
{
    int x;
    int y;
}locatie[21];

struct caminstud
{
    int x;
    int y;
    int loc;
}camin[101];

bool v[21][101],q[101];
int main()
{
   int i,n,m,ok=0,K,M,N;
    double R;
    fin>>K>>R;
    fin>>M;
    for(i=1;i<=M;i++)
        fin>>locatie[i].x>>locatie[i].y;
    fin>>N;
    for(i=1;i<=N;i++)
        fin>>camin[i].x>>camin[i].y>>camin[i].loc;
    double dist;
    for(i=1; i<=M; i++)
        {
                for(int j=1;j<=N;j++)
                {
                    dist=sqrt((double)(pow((double)(camin[j].x-locatie[i].x),2)+pow((double)(camin[j].y-locatie[i].y),2)));
                    if(dist<=R) v[i][j]=1;
                }
        }
    for(i=1; i<=K; i++)
        res[i]=i;
    int nrmax=0,nr;
    while(!ok)
    {
        nr=0;
        for(i=1;i<=K;i++)
        {
            for(int j=1;j<=N;j++)
                    if(v[res[i]][j]) q[j]=1;
        }
        for(i=1;i<=N;i++)
            if(q[i]==1)
            {nr+=camin[i].loc; q[i]=0;}

        if(nr>nrmax) nrmax=nr;
        i=K;
        while(res[i]==M-K+i&&i>=0)
            i--;
        if(i==0) ok=1;
        else
        {            res[i]++;
            for(int k=i+1; k<=K; k++)
                res[k]=res[i]+k-i;
        }
    }
    fout<<nrmax<<'\n';
    return 0;
}

