#include <fstream>
#define Nmax 105
using namespace std;
ifstream fin("windows.in");
ofstream fout("windows.out");

struct fereastra
{
    int ls,ld,cs,cd;
}f[Nmax];
int N;
int in[Nmax];
int rez;

void Citire();
int peste(int a, int b);
void Citire();
void Afisare();
void Inchide();
void rezolv();

int main()
{
    Citire();
    rezolv();
    Afisare();
    return 0;
}

void Citire()
{
    int i;
    fin>>N;
    for(i=0;i<N;i++)
        fin>>f[i].ls>>f[i].cs>>f[i].ld>>f[i].cd;
}

void Inchide(int nr)
{
    int i;
    for(i=N-1;i>=nr+1;i--)
        if(!in[i] && peste(i,nr))
            Inchide(i);
    in[nr]=1;
    ++rez;
}

int peste(int a, int b)
{
    if(f[a].ls<=f[b].ls && f[a].ld>=f[b].ls && f[a].cs<=f[b].cd && f[a].cd>=f[b].cd)
        return 1;
    return 0;
}

void rezolv()
{
    rez=0;
    Inchide(0);
}

void Afisare()
{
    fout<<rez<<'\n';
}
