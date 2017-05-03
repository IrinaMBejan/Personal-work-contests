#include <fstream>
#include <cstring>
#define Nmax 100005
#define Mod 100003
using namespace std;
ifstream fin("spion1.in");
ofstream fout("spion1.out");

char a[Nmax];
int T[2][Nmax];
int comb(int N,int M);

int main()
{
    int i, p, n, x=0, y=0;
    fin>>p;
    fin.get();
    fin.getline(a,Nmax);
    n=strlen(a);
    for(i=0; i<n; i++)
    {
        if(a[i]=='E') y++;
        x++;
    }
    if(p==1)
        fout<<y+1<<"\n";
    else fout<<comb(n, y)<<"\n";
}

int comb(int N,int M)
{
    int i,j,cur=1,prev=0;
    T[0][0]=T[1][0]=T[0][1]=1;
    for(i=2; i<=N; i++)
    {
        T[cur][i]=1;
        for(j=1; j<i; j++)
            T[cur][j]=(T[prev][j-1]%Mod+T[prev][j]%Mod)%Mod;
        prev=1-prev;
        cur=1-cur;
    }
    return T[prev][M];
}
