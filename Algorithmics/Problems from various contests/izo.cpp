#include <fstream>
#include <algorithm>
#define NMAX 205
using namespace std;

ifstream fin("izo.in");
ofstream fout("izo.out");

struct nod
{
    int nrod, grad;
}e1[NMAX], e2[NMAX];

int N;
int sol[NMAX];

int comp(nod a, nod b)
{
    return a.grad < b.grad;
}

int main()
{
    fin>>N;
    int i,a;
    for(i=1;i<=N;i++)
    {
        fin>>a;
        e1[i].nrod = i;
        if(a == 0)
            continue;
        else
            e1[i].grad++,e1[a].grad++;
    }

    for(i=1;i<=N;i++)
    {
        fin>>a;
        e2[i].nrod = i;
        if(a == 0)
            continue;
        else
            e2[i].grad++,e2[a].grad++;
    }

    sort(e1+1, e1+N+1, comp);
    sort(e2+1, e2+N+1, comp);

    for(i=1;i<=N;i++)
        sol[e1[i].nrod] = e2[i].nrod;

    for(i=1;i<=N;i++)
        fout<<sol[i]<<" ";
    fout<<'\n';

    return 0;
}
