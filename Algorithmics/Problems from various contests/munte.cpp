#include <cstdio>
#define Nmax 64005
#define MOD 12343
using namespace std;
FILE* fin=fopen("munte.in","r");
FILE* fout=fopen("munte.out","w");

void Citire();
void Afisare();
void Combinari();
void DetS();
int N;
int v[Nmax];
int MAX;
int rez;
int main()
{
    int k;
    Citire();
    DetS();
    Afisare();
    return 0;
}

void Citire()
{
    fscanf(fin,"%d",&N);
    int i;
    MAX=0;
    int x;
    for(i=1;i<=N;i++)
        {
            fscanf(fin,"%d",&x);
            v[x]++;
            if(x>MAX) MAX=x;
        }
}

void Afisare()
{
    fprintf(fout,"%d\n",rez);
}

void DetS()
{
    int i;
    rez=1;
    bool disj=1;
    if(v[MAX]>=2)
        rez=0;
    else
        for(i=1;i<MAX;i++)
            if(v[i]!=0)
            {
                    if(v[i]>2)
                        rez=0;
                    else
                        {
                            if(v[i]==2)
                                    disj=0;
                            else
                                rez=(rez*2)%MOD;
                        }
            }
    if(disj==1 && rez!=0)
        rez-=2;
}
