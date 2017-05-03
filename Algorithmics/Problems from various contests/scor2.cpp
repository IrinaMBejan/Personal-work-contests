#include <fstream>
#include <cstring>
#include <cstdlib>
#define Lgmax 35
#define Nmax 105
using namespace std;
ifstream fin("scor2.in");
ofstream fout("scor2.out");

struct elev
{
    bool ver;
    int punctaj;
    int def[105];
} C[105];

char P[Nmax][Nmax]; //relatie
char Part2[Nmax];
char Nu[Nmax][Lgmax];
int N,n;
char *s;
int pozi[Nmax];

void Initializare();
void Citire();
int Cauta();
void AdaugaPer(int i);
void PrelucrareRel();
void CalculeazaPunctaje();
void Afisare();

int main()
{
    Citire();
    Initializare();
    PrelucrareRel();
    CalculeazaPunctaje();
    Afisare();

    int i,j;
    for(i = 1; i <= n; i++)
        fout<<pozi[i]<<" ";

    for(i=1;i<=N;i++)
        fout<<i<<" "<<Nu[i]<<'\n';
    return 0;
}

void Initializare()
{
    int i,j;
    for(i = 1; i <= N; i++)
        for(j = 1; j <= N; j++)
            C[i].def[j]  = 9999;
}

void Citire()
{
    int i;

    fin>>n;
    fin.get();
    for(i = 1; i <= n; i++)
    {
        fin.getline(P[i], Nmax);
        s = strchr(P[i],'=');
        strcpy(Part2,s+1);
        *s = 0;
        s = strtok(P[i]," ");
        AdaugaPer(i);
        strcpy(P[i],Part2);
    }
}

void PrelucrareRel()
{
    int i, nr, poz2;
    char *minu, *plu;
    for(i= 1; i <= n; i++)
    {
        minu = strchr(P[i],'-');
        plu = strchr(P[i],'+');

        if(!minu&&!plu)
            C[pozi[i]].punctaj = atoi(strtok(P[i]," "));
        else
        {
            s = strtok(P[i]," +-");
            poz2=Cauta();
            s = strtok(NULL," +-");
            nr=atoi(s);

            if(plu)
                C[pozi[i]].def[poz2] = nr;
            else
                C[pozi[i]].def[poz2] = nr*(-1);
        }
    }
}

int Cauta()
{
    int j;
    for(j = 1; j <= N; j++)
        if(strcmp(s,Nu[j]) == 0)
            return j;
    return 0;
}

void AdaugaPer(int i)
{
    int poz = 0,j;
    for(poz = 1; strcmp(s,Nu[poz]) > 0 && poz<=N; poz++);

    if(strcmp(s,Nu[poz]) !=0)
        {
            for(j = N+1; j>=poz+1; j--)
               {
                    strcpy(Nu[j],Nu[j-1]);
                    pozi[j-1]++;
               }
            strcpy(Nu[poz],s);
            N++;
        }
    pozi[i]=poz;
}

void CalculeazaPunctaje()
{
    bool ok = 1;
    int i,j;
    while (ok)
    {
        ok = 0;
        for( i = 1; i <= N; i++)
            if(C[i].punctaj && !C[i].ver)
            {
                ok=1;
                for(j = 1; j <= N; j++)
                    if(C[j].def[i] != 9999)
                        C[j].punctaj = C[i].punctaj + C[j].def[i];
                C[i].ver= 1;
            }
    }
}

void Afisare()
{
    int i;
    for(i = 1; i <= N; i++)
        fout<<Nu[i]<<" "<<C[i].punctaj<<'\n';
}
