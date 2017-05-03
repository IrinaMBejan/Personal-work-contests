#include <fstream>
#include <algorithm>
#include <iomanip>
#define Nmax 10005
#define INF 1000000006
using namespace std;
ifstream fin("cetati.in");
ofstream fout("cetati.out");

struct punct
{
    double x,y;
} V[Nmax],fr, st[Nmax];

void Citire();
double Aria(punct a, punct b, punct c);
int compare(punct a, punct b);
void Parcurgere();
int N,po;
void Afisare();

int main()
{
    Citire();
    sort(V+2,V+N+1,compare);
    Parcurgere();
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
        fin>>V[i].x>>V[i].y;
        if(V[i].x<fr.x)
            fr=V[i], poz=i;
        else if(V[i].x== fr.x && V[i].y< fr.y)
            fr.y=V[i].y, poz=i;
    }
    swap(V[1],V[poz]);
}


int compare(punct a, punct b)
{
    return( Aria(a,fr,b)>0);
}

double Aria(punct a, punct b, punct c)
{
 return (a.x - b.x) * (c.y - b.y) - (a.y - b.y) * (c.x - b.x);
}

void Parcurgere()
{
        int i;

        st[1]=fr;
        po=2;

        for(i=po;i<=N;i++)
        {
            while(po>2 && Aria(st[po-2],  st[po-1], V[i]) >=0)
                po--;
            st[po] = V[i];
            po++;
        }

}

void Afisare()
{
    fout<<N-po+1<<'\n';
}

