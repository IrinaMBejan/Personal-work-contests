#include <fstream>
#define Nmax 101

using namespace std;
ifstream fin("perspic.in");
ofstream fout("perspic.out");

int P[Nmax*Nmax],Exp[Nmax*Nmax],Prime[Nmax*Nmax];
bool B[Nmax*Nmax],Sieve[Nmax*Nmax];
void doit(char tip, int nr1, int nr2);
void ciur();

int N;
long long int cmmmc=1;

int main()
{
    int M,i,j,q1,q2;
    char tip;
    fin>>N>>M;
    for(i=0; i<N*N; i++)
        P[i]=i;
    ciur();
    int k;
    for(i=1; i<=M; i++)
    {
        fin>>tip>>q1>>q2;
        doit(tip,q1-1,q2-1);
    }

    int e;
    int q, ret,H=0;
    for(i=0; i<N*N; i++)
    {
        for (H = 0, j = i; !B[j]; ++H)
        {
            B[j]=1;
            j = P[j];
        }
        for(j=1; Prime[j]*Prime[j]<=H&&H>1; j++)
        {
            e=0;
            while(H%Prime[j]==0)
            {
                H/=Prime[j];
                e++;
            }
            if(e>Exp[Prime[j]]) Exp[Prime[j]]=e;
        }
        if(H>1&&!Exp[H]) Exp[H]++;
    }

    for(i=2; i<=N*N; i++)
        if(!Sieve[i])
            if(Exp[i]!=0)
            {
                for(k=0; k<Exp[i]; k++)
                    cmmmc=(((long long int) cmmmc*(i%13007))%13007);
            }
    fout<<cmmmc<<'\n';


    return 0;
}


void ciur()
{
    int i,j;
    for(i=4; i<=N*N; i+=2)
        Sieve[i]=1;
    for(i=3; i<=N; i+=2)
        if(!Sieve[i])
        {
            for(j=i*i; j<=N*N; j+=i)
                Sieve[j]=1;
        }

    int k=0;
    for(i=2; i<=N*N; i++)
        if(!Sieve[i]) Prime[++k]=i;
}
void doit(char tip, int nr1, int nr2)
{
    int i;
    if(tip=='C')
    {
        for(i=0; i<N; i++)
            swap(P[i*N+nr1],P[i*N+nr2]);
    }
    else if(tip=='R')
    {
        for(i=0; i<N; i++)
            swap(P[nr1*N+i],P[nr2*N+i]);
    }
    else
    {
        int nr3,nr4;
        fin>>nr3>>nr4;
        nr3--;
        nr4--;
        swap(P[nr1*N+nr2],P[nr3*N+nr4]);
    }
}
