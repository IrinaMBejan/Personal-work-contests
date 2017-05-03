#include <fstream>
#define Nmax 1005
using namespace std;

ifstream fin("unionfind.in");
ofstream fout("unionfind.out");

int n, tata[Nmax],h[Nmax];
int Find(int x);
void Union(int x, int y);

int main()
{
    int i,m,x,y,rx,ry;
    fin>>n>>m;

    for(i=1;i<=m;i++)
    {
        fin>>x>>y;
        rx = Find(x);
        ry = Find(y);
        if(rx!=ry)
            Union(x,y);
    }
    //afisare
    int nr = 0,j;
    for(i = 1; i<=n;i++)
        if(!tata[i]) //i radacina unui arbore
        {
            nr++;
            fout<<"Comp conexa "<<nr<<" ";
            for(j=1;j<=n;j++)
                if(Find(j) == i)
                    fout<<j<<" ";
            fout<<'\n';
        }
    return 0;
}

void Union (int x, int y) //regula de ponderare union // h[i] = 0 initial
{
    int rx,ry;
    //x tata lui y doar daca x si y sunt reprezentati ai multimilro din care fac parte //radacini
    rx = Find(x);
    ry = Find(y);
    if(h[rx]>h[ry])
        tata[ry] = rx;
    else if(h[rx]<h[ry])
        tata[rx] = ry;
    else if(h[rx] == h[ry])
    {
        tata[ry] = rx;
        h[rx]++;
    }
    //Se poate dmeonstra matematic ca aplicand regula de ponderare la operatia union, inaltimea maxima a unui arbore este de ordinul log n
}


int Find(int x) //Regula de compresie: cand execut o operatie find - find(x) - eu identific radacina rx a arborelui in care face parte x
    //dupa identificarea rad, mai facem o parcurgere pt a compresa drumul de la x la radacina,transformand fiecare nod de pe acest drum
    //in fiu al radacinii
{
    int rx = x,y;
    while(tata[rx])
        rx = tata[rx];
    //compresia
    while(x!=rx)
    {
        y = tata[x];
        tata[x] = rx;
        x = y;
    }
    return rx;
}
