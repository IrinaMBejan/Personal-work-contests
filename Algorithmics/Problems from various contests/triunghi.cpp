#include <fstream>
#define Nmax 70
using namespace std;
ifstream fin("triunghi.in");
ofstream fout("triunghi.out");

struct tarani
{
    int xa,ya,xb,yb,xc,yc;
    double A;
} T[Nmax];
int vec[Nmax];

double arie(int xa, int ya, int xb, int yb, int xc, int yc );
int main()
{
    int max=0, taran,nrfan,N,i,x,y,x1,y1,ok;
    fin>>N;
    for(i=1; i<=N; i++)
    {
        fin>>T[i].xa>>T[i].ya>>T[i].xb>>T[i].yb>>T[i].xc>>T[i].yc;
        T[i].A=(double)arie(T[i].xa,T[i].ya,T[i].xb, T[i].yb, T[i].xc, T[i].yc);
        if(T[i].A>max)
        {
            max=T[i].A;
            taran=i;
        }
    }
    fin>>x>>y;
    nrfan=0;
    ok=1;
    for(i=1; i<=N; i++)
    {
        if(T[i].A==(double)arie(x,y,T[i].xa, T[i].ya,T[i].xb, T[i].yb )+(double)arie(T[i].xb,T[i].yb,x,y,T[i].xc,T[i].yc)+(double)arie(T[i].xc,T[i].yc,x,y,T[i].xa,T[i].ya))
            vec[++nrfan]=i;
        if(i!=taran&&ok)
        {
            x1=T[i].xa, y1=T[i].ya;
            if(T[taran].A!=arie(x1,y1,T[taran].xa, T[taran].ya,T[taran].xb, T[taran].yb )+arie(T[taran].xb,T[taran].yb,x1,y1,T[taran].xc,T[taran].yc)+arie(T[taran].xc,T[taran].yc,x1,y1,T[taran].xa,T[taran].ya))
                ok=0;
            else
            {
                x1=T[i].xb;
                y1=T[i].yb;
                if(T[taran].A!=arie(x1,y1,T[taran].xa, T[taran].ya,T[taran].xb, T[taran].yb )+arie(T[taran].xb,T[taran].yb,x1,y1,T[taran].xc,T[taran].yc)+arie(T[taran].xc,T[taran].yc,x1,y1,T[taran].xa,T[taran].ya))
                    ok=0;
                else
                {
                    x1=T[i].xc;
                    y1=T[i].yc;
                    if(T[taran].A!=arie(x1,y1,T[taran].xa, T[taran].ya,T[taran].xb, T[taran].yb )+arie(T[taran].xb,T[taran].yb,x1,y1,T[taran].xc,T[taran].yc)+arie(T[taran].xc,T[taran].yc,x1,y1,T[taran].xa,T[taran].ya))
                        ok=0;
                }
            }
        }
    }

    fout<<nrfan;
    for(i=1; i<=nrfan; i++)
        fout<<" "<<vec[i];
    fout<<'\n';
    if(ok) fout<<taran;
    else fout<<ok;
    fout<<'\n';
    return 0;
}

double ab(double x)
{
    if(x<0) return x*=-1;
    return x;
}
double arie(int xa, int ya, int xb, int yb, int xc,int yc )
{
    return ab((double)(xa*yb+xb*yc+xc*ya-xc*yb-xb*ya-xa*yc)/2);
}
