#include <fstream>
#define NMax 1001

using namespace std;
ifstream fin("taieturi.in");
ofstream fout("taieturi.out");

int Amax, xsMax, ysMax, xdMax, ydMax, n, W, H;
struct gaura
{
    int x,y;
}P[NMax];


void Citire();
void DI(int xs, int ys, int xd, int yd);
int Arie( int xs, int ys, int xd, int yd );
int Cauta( int xs, int ys, int xd, int yd );
void Afisare();


int main()
{
    Citire();
    DI (0,0,W,H);
    Afisare();
    return 0;
}

void Citire()
{
    int i;
    fin>>n;
    fin>>W>>H;

    for(i=1;i<=n;i++)
        fin>>P[i].x>>P[i].y;
}

void DI(int xs, int ys, int xd, int yd)
{
    if( Arie( xs, ys, xd, yd ) < Amax )
        return ;
    int k = Cauta( xs, ys, xd, yd);
    if(k == 0)
        {
            Amax = Arie ( xs, ys, xd, yd);
            xsMax = xs; ysMax = ys; xdMax = xd; ydMax = yd;
        }
    else
        {
            int yi = P[k].y, xi = P[k].x;
            DI( xs, yi, xd, yd );
            DI( xs, ys, xd, yi );
            DI( xs, ys, xi, yd );
            DI( xi, ys, xd, yd );
        }
}

int Arie( int xs, int ys, int xd, int yd )
{
    return ( xd-xs )*( yd-ys );
}

int Cauta( int xs, int ys, int xd, int yd )
{
    int i;
    for( i=1; i<=n ;i++ )
            if( xs < P[i].x && P[i].x < xd && ys < P[i].y && P[i].y < yd)
                return i;
    return 0;
}


void Afisare()
{
    fout<<Amax<<'\n';
    fout<<xsMax<<" "<<ysMax<<" "<<xdMax<<" "<<ydMax<<'\n';
}
