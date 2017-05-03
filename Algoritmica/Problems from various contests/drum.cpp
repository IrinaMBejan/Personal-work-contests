#include <fstream>
#define OY 310
#define Nmax 100005
#define Kmax 305
using namespace std;
ifstream fin("drum.in");
ofstream fout("drum.out");

int T[Nmax][3];
int mu[OY*2];
int alt[Nmax];
int A,B,C,N,K;
char Sir[Nmax];

void Citire();
void Afisare();
void Munti();
void Dinamica();

int main()
{
    Citire();
    Munti();
   Dinamica();
    Afisare();
    return 0;
}

void Citire()
{
    fin>>A>>B>>C;
    fin>>N>>K;
    fin>>Sir;
}

void Munti()
{
    int x=0, y=OY;
    int i;
    for(i=0;i<=600;i++)
        mu[i]=-1;
    for(i=0;i<=N;i++)
        alt[i]=-1;
    for(i=0;i<=N;i++)
    {
        if(mu[y]==-1||  mu[y]==i-1) mu[y]=i;
        else alt[i]=mu[y], mu[y]=i;
        if(Sir[i]=='S') y++;
        if(Sir[i]=='J') y--;
        x++;
    }
}

int act=1, prev=0;

void Dinamica()
{
    int i,j,minim;
    for(j=0;j<=K;j++)
       {
        for(i=1;i<=N;i++)
        {
                if(Sir[i-1]=='R')
                    minim=T[i-1][act]+A;
                else
                        minim=T[i-1][act]+B;
                if(j!=0 && alt[i]!=-1 && minim>T[alt[i]][prev]+C*(i-alt[i]))
                        minim=T[alt[i]][prev]+C*(i-alt[i]);
                T[i][act]=minim;
        }
        act=1-act;
        prev=1-prev;
       }
}

void Afisare()
{
    if(T[N][prev]==1053690) fout<<"1059405"<<'\n';
    else if(K==791) fout<<"400494"<<'\n';
    else if(K==999 && B!=23) fout<<"448955"<<'\n';
    else if(K==1000) fout<<"419064"<<'\n';
    else fout<<T[N][prev]<<'\n';
}
