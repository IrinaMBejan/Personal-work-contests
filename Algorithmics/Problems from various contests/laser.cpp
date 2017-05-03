#include <fstream>
#include<cmath>
#define Nmax 75
#define INF 100000
using namespace std;
ifstream fin("laser.in");
ofstream fout("laser.out");
struct punct
{
    double x,y;
}P[Nmax],C;

double DistPuncte(punct a, punct b);
double DistPS(punct a, punct b, punct c);

int main()
{
    int N,i,R;
    fin>>N;
    for(i=1;i<=N;i++)
        fin>>P[i].x>>P[i].y;
    fin>>C.x>>C.y>>R;
    P[N+1]=P[1];
    int a,b,c,ok=1;
    for(i=1;i<=N;i++)
    {
            a=P[i+1].y-P[i].y;
            b=P[i].x-P[i+1].x;
            c=P[i].y*P[i+1].x-P[i].x*P[i+1].y;
            if(a*C.x+b*C.y+c<0) ok=0;
    }
    if(ok==1) fout<<0<<'\n';
    else
    {
        double rmin=INF;
        for(i=1;i<=N;i++)
            {
                double dis=DistPS(P[i],P[i+1],C);
                if(rmin>dis) rmin=dis;
            }
        rmin=(double) rmin- R;
        if(rmin<0) fout<<0<<'\n';
        else fout<<fixed<<rmin<<'\n';
    }
    return 0;
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
