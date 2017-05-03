#include <fstream>
#define Nmax 1005
#define Tmax 10005

using namespace std;
ifstream fin("farfurii.in");
ofstream fout("farfurii.out");

int t[Nmax],nrmax[2][Tmax],N,T,Nm,Tm;

void Citire();
void DetSol();
void Afisare();

int main()
{
    Citire();
    DetSol();
    Afisare();

    return 0;
}

void Citire()
{
    int i;
    fin>>N>>T;
    for(i=1; i<=N; i++)
        fin>>t[i];
}

void DetSol()
{
    int lp = 0, lc = 1;
    int i,j;

    Nm = 0;
    for(i=t[1];i<=T;i++) nrmax[0][i] = 1;

    for(i=2; i<=N; i++)
    {
        for(j = 1; j<=T; j++)
        {
            nrmax[lc][j] = nrmax[lp][j-1];
            if(j >= t[i] && j-t[i]>=i-1 && 1+nrmax[lp][j-t[i]]>nrmax[lc][j])
                nrmax[lc][j] = 1+nrmax[lp][j-t[i]];
        }

        if(nrmax[lc][T] > Nm)
            {
                Nm = nrmax[lc][T];
                for(Tm = T; nrmax[lc][Tm] == Nm; Tm--);
            }
        else if(nrmax[lc][T] == Nm)
        {
            for(Tm = T; nrmax[lc][Tm] == Nm; Tm--);
        }
        lp = 1-lp;
        lc = 1-lc;
    }
}

void Afisare()
{
    fout<<Nm<<" "<<Tm<<'\n';

}
