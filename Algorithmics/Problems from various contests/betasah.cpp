#include <fstream>
#define NMAX 1002
using namespace std;
ifstream fin("betasah.in");
ofstream fout("betasah.out");

struct dame
{
    int x;
    int y;
} d[101];

int dl[9]= {-1,-1,0,1,1,1,0,-1};
int dc[9]= {0,1,1,1,0,-1,-1,-1};

int a[NMAX][NMAX];
int main()
{
    int N,D,K,i,j,x,y,nmax;
    fin>>N>>D>>K;
    for(i=1; i<=N; i++)
        a[i][0]=i;
    for(i=1; i<=D; i++)
    {
        fin>>d[i].x>>d[i].y;
        a[d[i].x][d[i].y]=3;
       // a[i][0]--;
    }
    for(i=1; i<=K; i++)
    {
        fin>>x>>y;
        a[x][y]=7;
        a[x][0]--;
    }
    nmax=a[1][0];
    for(i=2; i<=N; i++)
        if(a[i][0]>nmax) nmax=a[i][0];
    fout<<nmax<<'\n';
    for(i=0; i<=N+1; i++)
    {
        a[i][0]=7;
        a[N+1][i]=7;
    }
    a[1][0]=7;
    j=1;
    i=0;
    while(j<=N+1)
    {
        a[i][j]=7;
        j++;
        i++;
    }
     j=2;
     i=0;
    while(j<=N+1)
    {
        a[i][j]=7;
        j++;
        i++;
    }
    int nr=0;
    for(int q=1; q<=D; q++)
    {
        for(i=0; i<=7; i++)
        {
            x=d[q].x+dl[i];
            y=d[q].y+dc[i];;
            while(a[x][y]<=0)
            {
                if(!a[x][y])nr++;
                a[x][y]=-1;
                x+=dl[i];
                y+=dc[i];
            }
        }
    }
    fout<<nr<<'\n';
    return 0;
}
