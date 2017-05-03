#include <fstream>
#define Nmax 55
using namespace std;
ifstream fin("patrate.in");
ofstream fout("patrate.out");

int a[Nmax][Nmax];
int main()
{
    int N;
    fin>>N;
    int i,j;
    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
            {
                fin>>a[i][j];
                if(a[i][j]==0) a[i][j]=2;
            }

    int di, dj, sol=0,k=0;
    for(i=1;i<=N;i++)
        for(j=1;j<=N;j++)
            for(dj=1;dj<=N;dj++)
                for(di=0;di<=N;di++)
                   if(i+di<=N &&j+dj<=N && i+di+dj<=N && j+dj-di<=N && i+dj-di>=0 && i+dj<=N && j-di>=0)
                    if( a[i][j]==a[i+di][j+dj] && a[i+di][j+dj]==a[i+di+dj][j+dj-di] && a[i+di][j+dj]==a[i+dj][j-di] )
                            {
                                fout<<i<<" "<<j<<" e "<<i+di<<" "<<j+dj<<" e "<<i+di+dj<<" e "<<j+dj-di<<" e "<<i+dj<<" "<<j-di<<'\n';
                                sol++;
                            }
    fout<<sol<<'\n';
    return 0;
}
