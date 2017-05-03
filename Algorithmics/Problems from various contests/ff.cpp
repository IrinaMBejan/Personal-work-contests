#include <fstream>
#include<cmath>
#include<iomanip>
#define Nmax 110
#define INF 20000
using namespace std;
ifstream fin("ff.in");
ofstream fout("ff.out");

double Dmax=INF;

struct punct
{
    double x, y;
} A[Nmax], B[Nmax];

int N,M;
void Citire();
double DistPuncte(punct a, punct b);
double DistPS(punct a, punct b, punct c);

int main()
{
    Citire();
    int i,k;
    double d;
    for(i=1; i<=N; i++)
    {
        for(k=1; k<M; k++)
        {
            d=DistPS(B[k],B[k+1],A[i]);
            if(Dmax>d) Dmax=d;
        }
    }

    for(i=1; i<=M; i++)
    {
        for(k=1; k<N; k++)
        {
            d=DistPS(A[k],A[k+1],B[i]);
            if(Dmax>d) Dmax=d;
        }
    }

    fout<<fixed;
    fout<<setprecision(5)<<Dmax<<'\n';
    return 0;
}

void Citire()
{
    fin>>N;
    int i;
    for(i=1; i<=N; i++)
        fin>>A[i].x>>A[i].y;

    fin>>M;
    for(i=1; i<=M; i++)
        fin>>B[i].x>>B[i].y;
}

double DistPuncte(punct a, punct b)
{
    return sqrt((double)(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}


double DistPS(punct a, punct b, punct c)
{
    double dist = (double)((b.x-a.x) *(c.y-a.y) - (b.y-a.y)*(c.x-a.x))/DistPuncte(a,b);
    int dot1 = (b.x-a.x)*(c.x-b.x)+(b.y-a.y)*(c.y-b.y); //A B C
    if(dot1 > 0)
        return DistPuncte(b,c);
    int dot2 = (a.x-b.x)*(c.x-a.x)+(a.y-b.y)*(c.y-a.y); //B A C
    if(dot2 > 0)
        return DistPuncte(a,c);
    return abs(dist);
}
