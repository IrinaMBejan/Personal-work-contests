#include <fstream>
#define Nmax 100000
using namespace std;
ifstream fin("scmax.in");
ofstream fout("scmax.out");

int a[Nmax+5], sol[Nmax+5];
int best[Nmax+5], poz[Nmax+5];
int N,lg;
void Citire();
void Rezolva();
void Reconstituire();
void Afisare();
int CautBin(int x);

int main()
{
    Citire();
    Rezolva();
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

void Rezolva()
{
    int i, loc;
    for(i=1;i<=N;i++)
    {
        if(a[i]>best[lg])
            {
                best[++lg]=a[i];
                poz[i]=lg;
            }
        else
            {
                loc=CautBin(a[i]);
                best[loc]=a[i];
                poz[i]=loc;
            }
    }
}

int CautBin(int x)
{
    int st, dr, mij;
    st=0; dr=lg+1;
    while(dr-st>1)
    {
        mij=(st+dr)/2;
        if(best[mij]>=x)
            dr=mij;
        else
            st=mij;
    }
    return dr;
}

void Reconstituire()
{
    int i,k, val;
    k=0; val=lg;
    for(i=N;i>0 && val!=0; i--)
    {
        if(poz[i]==val)
        {
            sol[++k] = a[i];
            val--;
        }
    }
}

void Afisare()
{
    fout<<lg<<'\n';
    int i;
    for(i=lg;i>0;i--)
        fout<<sol[i]<<" ";
    fout<<'\n';
}
