#include <cstdio>
#define NMAX 100005
using namespace std;

FILE* fin = fopen("barca.in","r");
FILE* fout = fopen("barca.out","w");

long long int g,gc;
int N,n,m;

struct pitic
{
    int gr;
    int ord;
}H[NMAX*2],x;

void ExtragereMaxim();
void Inserare(pitic inf);
void Combinare(int i);

int l[20];
int sol[2*NMAX];

int main()
{
    fscanf(fin,"%d %d %d",&n,&g,&m);

    int i;
    for(i=1; i<=10;i++)
        fscanf(fin,"%d",&l[i]);

    for(i=1;i<=n+m;i++)
    {
        while(gc>g)
            ExtragereMaxim();
        fscanf(fin,"%d",&x.gr);
        x.ord = i;
        Inserare(x);
        gc+=x.gr;
    }

    for(i=1;i<=10;i++)
        fprintf(fout,"%d\n",sol[l[i]]);

    return 0;
}

void Inserare(pitic inf)
{
    int fiu, tata;
    fiu = ++N;
    tata = fiu/2;
    while(inf.gr> H[tata].gr && tata>0)
    {
        H[fiu] = H[tata];
        fiu = tata;
        tata = tata/2;
    }
    H[fiu] = inf;
}


void Combinare(int i)
{
    pitic inf = H[i];
    int tata = i, fiu = 2*i;
    while(fiu<=N)
    {
        if(fiu+1<=N && H[fiu].gr<H[fiu+1].gr) fiu++;

        if(H[fiu].gr>inf.gr)
        {
            H[tata] = H[fiu];
            tata = fiu;
            fiu = 2*tata;
        }
        else break;
    }
    H[tata] = inf;
}

int nr = 0;

void ExtragereMaxim()
{
    sol[H[1].ord] = ++nr;
    gc -= H[1].gr;
    H[1] = H[N--];
    Combinare(1);
}
