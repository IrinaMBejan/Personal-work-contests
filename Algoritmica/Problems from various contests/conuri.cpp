#include <cstdio>
#include<algorithm>
#define Lgmax 100005
using namespace std;
FILE* fin=fopen("conuri.in","r");
FILE* fout=fopen("conuri.out","w");

struct con
{
    int a, b;
} V[Lgmax];

int Lm[Lgmax];
int N;
int maximus;


int main()
{
    fscanf(fin,"%d",&N);
    int i;
    for(i=1; i<=N; i++)
        fscanf(fin,"%d %d",&V[i].a,&V[i].b);
    int a,b;
    for(i=1; i<=N; i++)
    {
        a = Lm[V[i].b] + 1;
        b = Lm[V [i].a] + 1;
        Lm[V[i].a]=max(Lm[V[i].a],a);
        Lm[V[i].b]=max(Lm[V[i].b],b);
    }
    for(i=0;i<=100000;i++)
        if(Lm[i]>maximus)
            maximus=Lm[i];
    fprintf(fout,"%d\n",maximus);
    return 0;
}
