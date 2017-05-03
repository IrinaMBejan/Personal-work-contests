#include <fstream>
#define Nmax 25

using namespace std;
ifstream fin("gradina.in");
ofstream fout("gradina.out");
int N,M;
int mat[Nmax][Nmax];
int b[Nmax*Nmax];
int T[Nmax][Nmax];

void Citire();
void Back(int i, int j);
int Conv(int a, int i);
int Maxim();
int Ns, Amax, Ar,Lr,Cr,Ir=4,nr=1;
void Afisare();
void Bordare();
void Solve();

int dl[4]= {0,-1,0,1};
int dc[4]= {-1,0,1,0};
char d[6]="VNESX";
int main()
{
    Citire();
    Bordare();
    Solve();
    Amax=Maxim();
    Afisare();
    return 0;
}

void Solve()
{
    int i,j;
    for(i=1; i<=N; i++)
        for(j=1; j<=M; j++)
            if(T[i][j]==0)
            {
                Back(i,j);
                if(nr>Ns) Ns=nr;
                nr++;
            }
    int k;
    for(i=1; i<=N; i++)
        for(j=1; j<=N; j++)
        {
            for(k=0; k<4; k++)
                if(T[i+dl[k]][j+dc[k]] !=99999)
                    if(Conv(mat[i][j],k) && T[i][j]!=T[i+dl[k]][j+dc[k]] )
                    {
                        if(b[T[i][j]]+b[T[i+dl[k]][j+dc[k]]]>Ar)
                            Ar=b[T[i][j]]+b[T[i+dl[k]][j+dc[k]]],Lr=i,Cr=j,Ir=k;
                        else if(b[T[i][j]]+b[T[i+dl[k]][j+dc[k]]]==Ar && (k==0 || k==2) && (Ir==1 || Ir==3))
                            Lr=i,Cr=j,Ir=k;
                    }
        }
}

void Citire()
{
    fin>>N>>M;
    int i,j;
    for(i=1; i<=N; i++)
        for(j=1; j<=M; j++)
            fin>>mat[i][j];
}

void Bordare()
{
    int i;
    for(i=0; i<=N+1; i++)
        T[i][0]=T[i][M+1]=99999;
    for(i=0; i<=M+1; i++)
        T[0][i]=T[N+1][i]=99999;
}
void Back(int i, int j)
{
    T[i][j]=nr;
    b[nr]++;
    int k;
    for(k=0; k<4; k++)
        if(T[i+dl[k]][j+dc[k]]==0 && !Conv(mat[i][j],k))
            Back(i+dl[k],j+dc[k]);
}

int Conv(int a, int i)
{
    if(a&(1<<i))
        return 1;
    return 0;
}

int Maxim()
{
    int max=b[1];
    int i;
    for(i=2; i<=Ns; i++)
        if(max<b[i]) max=b[i];
    return max;
}
void Afisare()
{
    fout<<Ns<<'\n';
    fout<<Amax<<'\n';
    fout<<Ar<<" "<<Lr<<" "<<Cr<<" "<<d[Ir]<<'\n';
}
