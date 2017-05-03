#include <fstream>
#define Nmax 105
#define Lmax 10
using namespace std;
ifstream fin("grindina.in");
ofstream fout("grindina.out");

struct punct
{
    double x,y;
} Ma[Nmax][Lmax],bob;

int val[Nmax];
double ar[Nmax];
double Aria(punct a, punct b, punct c)
{
    return (a.x - b.x) * (c.y - b.y) - (a.y - b.y) * (c.x - b.x);
}

double absi(double x)
{
    if(x<0)
        return ((double) -x);
    return x;
}

bool point(punct a,punct b, punct c)
{
    return (((b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x)) == 0);
}
int nr[Nmax];
int main()
{
    int i,N,G,j;
    fin>>N;
    for(i=1; i<=N; i++)
    {
        fin>>nr[i];
        for(j=1; j<=nr[i]; j++)
        {
            fin>>Ma[i][j].x>>Ma[i][j].y;
        }
    }
    for(j=1; j<=N; j++)
        Ma[j][nr[j]+1]=Ma[j][1];
    for(i=1; i<=N; i++)
    {
        for(j=1; j<=nr[i]; j++)
            ar[i]+=Ma[i][j].x*Ma[i][j+1].y - Ma[i][j+1].x*Ma[i][j].y;
    }

    fin>>G;
    int k;
    bool ok;
    for(i=1; i<=G; i++)
    {
        fin>>bob.x>>bob.y;
        for(k=1; k<=N; k++)
        {
            double s=0;
            ok=1;
            for(j=1; j<=nr[k]; j++)
            {
                s+=absi(Aria(Ma[k][j], bob, Ma[k][j+1]));
                if(point(Ma[k][j],Ma[k][j+1],bob))
                    ok=0;
            }
            if(s==ar[k] && ok)
                val[k]++;
        }
    }
    int mx=0;
    int nrmx=0;
    int nrze=0;
    for(i=1; i<=N; i++)
    {
        if(val[i]>mx) mx=val[i], nrmx=1;
        else  if(val[i]==mx)nrmx++;
        if(val[i]==0) nrze++;
    }

    fout<<nrmx<<'\n';
    if(nrmx==0) fout<<"0"<<'\n';
    else
    {
        for(i=1; i<=N; i++)
            if(val[i]==mx) fout<<i<<" ";
        fout<<'\n';
    }
    fout<<nrze<<'\n';
    if(nrze==0) fout<<"0"<<'\n';
    else
    {
        for(i=1; i<=N; i++)
            if(val[i]==0)
                fout<<i<<" ";
        fout<<'\n';
    }
    return 0;
}

