#include <cstdio>
#define NMAX 200005
using namespace std;

FILE* fin = fopen("heapuri.in","r");
FILE* fout = fopen("heapuri.out","w");

int H[NMAX];
int poz[NMAX], npoz;
int a[NMAX];
int N;

void Inserare(int);
void Combinare(int);

int main()
{
    int n;
    fscanf(fin,"%d",&n);
    int i,cod,nr,j;
    for(i=0;i<n;i++)
    {
        fscanf(fin,"%d",&cod);
        if(cod == 1)
        {
            fscanf(fin,"%d",&nr);
            Inserare(nr); //insert
        }
        else if(cod == 2)
        {
            fscanf(fin,"%d",&nr);
            j = a[nr];
            H[j] = H[N];
            poz[j] = poz[N];
            a[poz[j]] = j;
            N--;
            Combinare(j);
        }
        else if(cod == 3)
        {
            fprintf(fout,"%d\n",H[1]);
        }
    }
}


void Combinare(int i)
{
    int inf = H[i], tata = i, fiu = 2*i;
    int p = poz[i];
    while(fiu<=N)
    {
        if(fiu+1<=N && H[fiu]>H[fiu+1]) fiu++;
        if(H[fiu]<inf)
        {
            H[tata] = H[fiu];
            poz[tata] = poz[fiu];
            a[poz[tata]] = tata;
            tata = fiu;
            fiu = 2*tata;
        }
        else
            break;
    }
    H[tata] = inf;
    poz[tata] = p;
    a[poz[tata]] = tata;
}


void Inserare(int inf)
{
    int fiu, tata;
    fiu = ++N;
    tata = fiu/2;
    while(inf < H[tata] && tata>0)
    {
        H[fiu] = H[tata];
        poz[fiu] = poz[fiu/2];
        a[poz[fiu]] = fiu;
        fiu = tata;
        tata = tata/2;
    }
    H[fiu] = inf;
    poz[fiu] = ++npoz;
    a[poz[fiu]] = fiu;
}
