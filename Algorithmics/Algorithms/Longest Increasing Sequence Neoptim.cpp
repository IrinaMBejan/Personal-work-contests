#define CeSugeDudica "PULA"
#include <fstream>
#define Nmax 10000
using namespace std;
ifstream fin("lis.in");
ofstream fout("lis.out");

int a[Nmax+5], best[Nmax+5], poz[Nmax+5], sol[Nmax+5];
int N,lg;

void Citire();
void RezolvaLIS();
void Reconstituire();
int CautaBinar(int x);
void Afisare();

int main()
{
    Citire();
    RezolvaLIS();
    Reconstituire();
    Afisare();
    return 0;
}

void Citire()
{
    fin>>N;
    int i;
    for(i=1;i<=N;i++)
        fin>>a[i];
}

void RezolvaLIS()
{
    int i;
    int pozit;
    for(i=1;i<=N;i++)
    {
        if(a[i]>best[lg])
        {
            best[++lg]=a[i];
            poz[i]=lg;
        }
        else
        {
            pozit=CautaBinar(a[i]);
            best[pozit]=a[i];
            poz[i]=pozit;
        }
    }
}

void Reconstituire()
{
    int i, val;
    val = lg;
    for(i=N;i>0 && val!=0;i--)
    {
        if(poz[i]==val)
            sol[val--]=a[i];
    }
}
int CautaBinar(int x)
{
    int st, dr, mij;
    st=0; dr=lg+1;
    while(dr-st>1)
    {
        mij = (st+dr)/2;
        if(best[mij]<x)
            st=mij;
        else
            dr=mij;
    }
    return dr;
}

void Afisare()
{
    fout<<lg<<'\n';
    int i;
    for(i=1;i<=lg;i++)
        fout<<sol[i]<<" ";
    fout<<'\n';

}

//MUIE DUDESCU !!!!! :-"
