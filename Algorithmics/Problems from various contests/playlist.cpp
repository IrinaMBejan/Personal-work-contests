#include <cstdio>
#define Nmax 15
using namespace std;
FILE* fin=fopen("playlist.in","r");
FILE* fout=fopen("playlist.out","w");


int sol[Nmax], uz[Nmax];
bool mat[Nmax][Nmax];
void Citire();
void Gen(int k);
void Afisare();
int N,M;
bool ok=0;

int main()
{
    Citire();
    Gen(1);
    return 0;
}

void Citire()
{
    fscanf(fin,"%d %d",&N,&M);
    int i,x,y;
    for(i=1; i<=M; i++)
    {
        fscanf(fin,"%d %d",&x,&y);
        mat[x][y]=1;
        mat[y][x]=1;
    }
}

void Gen(int k)
{
    if(!ok)
    {
        if(k==N+1)
        {
            Afisare();
            ok=1;
        }
        else
        {
            int i;
            for(i=1; i<=N; i++)
                if(!mat[i][sol[k-1]] && uz[i]==0)
                {
                    sol[k]=i;
                    uz[i]=1;
                    Gen(k+1);
                    uz[i]=0;
                }
        }
    }
}

void Afisare()
{
    int i;
    for(i=1; i<=N; i++)
        fprintf(fout,"%d ",sol[i]);
    fprintf(fout,"\n");
}
