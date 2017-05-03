#include <fstream>
#include<algorithm>
#define NMAX 20
using namespace std;
ifstream fin("bin.in");
ofstream fout("bin.out");

struct NodArbore
{
    int inf;
    NodArbore* st, *dr;
};

typedef struct NodArbore* Arbore;
Arbore R;
Arbore Reconstituie(int st, int dr, int& rad);
void generarePreordine();

int preordine[NMAX];
int N;
int main()
{
    fin>>N;
    generarePreordine();
    return 0;
}

void generarePreordine()
{
    int i,j;
    for(i=1;i<=N;i++)
        preordine[i] = i;
    bool ok = 1;
    while(ok)
    {
          fout<<"Inordine: ";
        for(i=1;i<=N;i++)
            fout<<i<<" ";
        fout<<"Preordine: ";
        for(i=1;i<=N;i++)
            fout<<preordine[i]<<" ";
        fout<<'\n';

        ok = 0;
        for(i=N-1; i>=1 && !ok;i--)
            for(j = i+1; j<=N && !ok;j++)
                if(preordine[j] == preordine[i]+1)
                {
                    swap(preordine[i],preordine[j]);
                    sort(preordine+i+1, preordine+N+1);
                    ok = 1;
                }
    }
}
/*
Arbore Reconstituie(int st, int dr, int& rad)
{
    Arbore r = new NodArbore;
    r->inf = rad;
    int poz;
    for(poz = st; inordine[poz] != rad; poz++);
    if(poz == st)
        r->st = NULL;
    else
        r->st = Reconstituie(st, poz-1, ++rad);

    if(poz == dr)
        r->dr = NULL;
    else
        r->dr = Reconstituie(poz+1, dr, ++rad);

    return r;
}
*/
