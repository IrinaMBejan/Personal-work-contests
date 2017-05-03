#include <fstream>
#include <algorithm>
#define Nmax 7
#define Lgmax 1<<14
using namespace std;

ifstream fin("volei.in");
ofstream fout("volei.out");

int N;
int nrmin[Lgmax], uz[Lgmax];
int C[Lgmax];

struct punct
{
    double x,y;
} V[Nmax],fr, st[Nmax];

double Aria(punct a, punct b, punct c);
int compare(punct a, punct b);
void Infasuratoare(punct V[Nmax], &lg, punct res[Nmax]);
bool eseparabil(int c);
void Lee();
void Citire();
void Afisare();


int main()
{
    Citire();
    Lee();
    Afisare();
    return 0;
}


void Citire()
{
}

void Afisare()
{
}

void Lee()
{
    int st=1,fi=1, gata=0;
    C[st]=ci;
    nrmin[ci]=1;
    uz[ci]=-1;
    int cu=0,c=0;
    while(!gata)
    {
        c=C[st++];
        for(i=0; i<2*N; i++)
            if((c>>i)&1)
                for(j=0;j<2*N;j++)
                    if(!((c>>i)&1))
                    {
                        cu = c&~(1<<i);
                        cu = cu | (1<<j);
                        if(nrmin[cu])
                        {
                            C[++fi]=cu;
                            uz[cu]=i*100+j;
                            nrmin[cu]=nrmin[c]+1;
                            if(eseparabil(cu))
                            {
                                gata=1;
                                cf=cu;
                                return;
                            }
                        }
                    }
    }
    fout<<nrmin[cf]<<'\n';
    return 0;
}

int compare(punct a, punct b)
{
    return( Aria(a,fr,b)>0);
}

double Aria(punct a, punct b, punct c)
{
 return (a.x - b.x) * (c.y - b.y) - (a.y - b.y) * (c.x - b.x);
}

bool eseparabil(int c)
{
    Infasuratoare(F, lgf, resf);
    Infasuratoare(B, lgb, resb);
    resf[lgf]=resf[0];
    resb[lgb]=resb[0];
    int i,j;
    for(i=0;i<lgf;i++)
        for(j=i+1;j<lgb;j++)
            if(intersect(resf[i],resf[i+1],resb[i],resb[i+1]))
                return 0;
    return 1;
}


void Infasuratoare(punct V[Nmax],int &lg, punct res[Nmax])
{
    int poz;
    fr.x = fr.y = INF;
    for(i=0;i<N;i++)
    {
        if(V[i].x<fr.x)
            fr=V[i], poz=i;
        else if(V[i].x== fr.x && V[i].y< fr.y)
            fr.y=V[i].y, poz=i;
    }
    swap(V[1],V[poz]);
    sort(V+1,V+N,compare);

    res[0]=fr;
    lg=1;
    for(i=lg;i<N;i++)
    {
            while(lg>1 && Aria(res[lg-2],  res[lg-1], V[i])>=0)
                lg--;
            res[lg] = V[i];
            lg++;
    }
    lg--;
}
