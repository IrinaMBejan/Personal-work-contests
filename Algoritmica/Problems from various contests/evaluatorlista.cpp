#include <fstream>
#include <iostream>
#include <stdlib.h>
#define INFILE        "lista.in"
#define OUTFILE       "lista.out"
#define OKFILE        "lista.ok"
#define NMax           100001L

using namespace std;

int L[NMax], p[NMax], N, uz[NMax];
pair<int, int> muchie[NMax];

void load_in ( void )
{
 ifstream fin(INFILE);
 fin >> N;
 int i;
 for (i=1; i<N; i++)
        fin >> L[i];

 fin.close();
}

void load_ok ( void )
{ifstream fin(OKFILE);
 int i;
 for (i=1; i<N; i++)
     fin >>muchie[i].first>>muchie[i].second;
 fin.close();
}

void eror(char *s, int p)
{cout<<p<<' '<<s<<'\n';
 exit(0);
}

int main ( void )
{int i, x, y, j;
 load_in(); load_ok();
ifstream fin(OUTFILE);
if (!fin) eror("Fisier de iesire absent",0);
for (i=1; i<N; i++)
    {fin>>x>>y;
     if (!fin.good()) eror("Fisier de iesire incorect",0);
     if (x>N || x<1)  eror("Fisier de iesire incorect",0);
     if (y>N || y<1)  eror("Fisier de iesire incorect",0);
     for (j=1; j<N; j++)
         if ((muchie[j].first==x && muchie[j].second==y ||
             muchie[j].first==y && muchie[j].second==x ) && !uz[j])
             break;
     if (j<N && uz[j]==0)
        uz[j]=1;
        else
        eror("Arbore incorect",0);
    }
eror ("Corect",10);
return 0;
}
