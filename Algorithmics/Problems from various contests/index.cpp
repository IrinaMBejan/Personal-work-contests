#include <fstream>
#include <cstring>
#include <cctype>
#define Nmax 105
#define Lgmax 205
using namespace std;

ifstream fin("index.in");
ofstream fout("index.out");

char vl[Nmax][Lgmax];
int pag[Nmax];
int N,K;

void Citire();
void Paginare();
void ExtrageCuv();
void Sortare();
void Afisare();

int main()
{
    Citire();
    Paginare();
    ExtrageCuv();
    Sortare();
    Afisare();
    return 0;
}

void Citire()
{
    fin>>N;
    fin.get();

    while(!fin.eof())
            fin.getline(vl[++K],Lgmax);
}

void Paginare()
{
    int i, lincur=0, nlpc, nlpt, pg=1;
    for(i=1;i<=K;i++)
    {
        nlpt=nlpc=1;
        while(v[nlpt][0]!='\0')
            nlpt++;

        if(lincur + nlpt-1 == N)
            {
                for(j=i;j<=i+nlpt-1;j++)
                    pag[j]=pg;
                i++;
                pg++;
                lincur = 1;
            }
        else if(lincur +nlpt -1 < N )
        {
              for(j=i;j<=i+nlpt-1;j++)
                    pag[j]=pg;

              lincur+=nlpt;
        }
        else if(lincur+nlpt>N)
        {
            if(lincur == n && nlpc ==1)
            {
                 pg++;
                 lincur=1;
                 i--;
            }
            else
            {

            }


        }

        i+=nlpt;
    }
}
void ExtrageCuv();
void Sortare();
void Afisare();
