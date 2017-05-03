#include <cstdio>
#include <algorithm>
#define NMAX 200005
#define MMAX 400005
using namespace std;
FILE* fin=fopen("apm.in","r");
FILE* fout=fopen("apm.out","w");

struct muchie
{
    int x,y,cost;
};

muchie Mu[MMAX];
int puse[NMAX];
int C[NMAX];
void CitireListe();
void KruskalNeop();
bool compare(muchie a, muchie b);
void Schimba(int cautat, int valnoua);
int N,M;
int costMin;
void Afisare();

int main()
{

    CitireListe();
    sort(Mu+1, Mu+M+1,compare);
    KruskalNeop();
    Afisare();
    return 0;
}

void CitireListe()
{
    int i;
    muchie a;
    fscanf(fin,"%d %d",&N,&M);

    for(i = 1; i <= M ; i++)
    {
        fscanf(fin,"%d %d %d",&Mu[i].x,&Mu[i].y,&Mu[i].cost);
    }
}

bool compare(muchie a, muchie b)
{
    return (a.cost < b.cost);
}

void KruskalNeop()
{
    int i;
    int j = 1;
    for(i=1; i<=N; i++)
        C[i] = i;

    for(i=1; i<=N-1; i++)
    {
        while (C[Mu[j].x]==C[Mu[j].y])
            j++;
        if(C[Mu[j].x]<C[Mu[j].y])
            Schimba(C[Mu[j].y],C[Mu[j].x]);
        else
            Schimba(C[Mu[j].x],C[Mu[j].y]);
        puse[i] = j;
        costMin += Mu[j].cost;
        j++;
    }
}

void Schimba(int cautat, int valnoua)
{
    int i;
    for(i=1; i<=N; i++)
        if(C[i] == cautat)
            C[i] = valnoua;
}

void Afisare()
{
    fprintf(fout,"%d\n%d\n",costMin,N-1);
    int i;
    for(i=1; i<=N-1; i++)
        fprintf(fout,"%d %d\n",Mu[puse[i]].x,Mu[puse[i]].y);
}
