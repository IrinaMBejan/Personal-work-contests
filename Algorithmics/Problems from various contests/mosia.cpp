#include <fstream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#define Nmax 205
#define INF 1005
#define PI 3.14159265
using namespace std;
ifstream fin("mosia.in");
ofstream fout("mosia.out");


struct punct
{
    double x,y;
    double val;
    double t,r;
} V[Nmax],fr, st[Nmax];

double d[3][Nmax];

double ds[Nmax];
void Citire();
double Aria(punct a, punct b, punct c);
int compare(punct a, punct b);
int N,po;
void Afisare();
void Dinamica();

double mini;

int main()
{
    Citire();
    sort(V+2,V+N+1,compare);
    int i;

    for(i=N-1;V[i].t==V[N].t;i--);
    int st,dr;
    for(st=i+1,dr=N;st<dr;st++,dr--)
        swap(V[st],V[dr]);

    V[0]=V[N];
    V[N+1]=V[1];
    Dinamica();
    Afisare();
    return 0;
}

void Citire()
{
    int i;
    fin>>N;

    int poz;
    fr.x = fr.y = INF;
    for(i=1;i<=N;i++)
    {
        fin>>V[i].x>>V[i].y>>V[i].val;
        if(V[i].x<fr.x)
            fr=V[i], poz=i;
        else if(V[i].x== fr.x && V[i].y< fr.y)
            fr=V[i], poz=i;
    }
    swap(V[1],V[poz]);

    for(i=2;i<=N;i++)
    {
        V[i].r=(V[i].x-V[1].x)*(V[i].x-V[1].x) + (V[i].y-V[1].y)*(V[i].y-V[1].y);
        if(V[i].x==V[1].x)
            {
                if(V[i].y-V[1].y>0)
                    V[i].t=90.0;
                else
                    V[i].t=-90.0;
            }
        V[i].t=atan((double)(V[i].y-V[1].y)/(V[i].x-V[1].x))*180/PI;
    }

    for(i=1;i<=N;i++)
        fout<<V[i].x<<" "<<V[i].y<<'\n';
}

int compare(punct a, punct b)
{
    return( a.t<b.t || (a.t==b.t && a.r<b.r ));
}


double Aria(punct a, punct b, punct c)
{
 return (a.x - b.x) * (c.y - b.y) - (a.y - b.y) * (c.x - b.x);
}

double Dist(punct a, punct b)
{
    return (double) sqrt((double) ((double)(a.x-b.x)*(a.x-b.x) + (double)(a.y-b.y)*(a.y-b.y)) );
}

void Dinamica()
{
    int i,j,k;
    double S;
    for(i=1; i<=N;i++)
            {
                ds[i]=(double)V[i].val/2*Dist(V[i-1],V[i+1]);
                fout<<ds[i]<<" ";
            }fout<<'\n';


   d[1][N]=ds[N];
   d[1][N-1]=ds[N];
   for( i=N-2; i>=2;i--)
       if(d[1][i+2]+ds[i]>d[1][i+1])
              d[1][i]=d[1][i+2]+ds[i];
       else
          d[1][i]=d[1][i+1];

   double v1=d[1][2];
   d[2][N]=0;
   d[2][N+1]=0;
   for( i=N-1; i>=1;i--)
       if(d[2][i+2]+ds[i]>d[2][i+1])
              d[2][i]=d[2][i+2]+ds[i];
       else
          d[2][i]=d[2][i+1];
    double v2=d[2][1];
    if(v1>v2)
        mini=v1;
    else mini=v2;
}

void Afisare()
{
    int i,j;
    for(i=1;i<=N;i++)
    {for(j=1;j<=2;j++)
            fout<<d[i][j]<<" ";fout<<'\n';}
    fout<<setprecision(4)<<fixed;
    fout<<mini<<'\n';
}
