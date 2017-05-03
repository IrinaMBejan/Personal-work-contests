#include <fstream>
#define NMAX 1001
using namespace std;
ifstream fin("triunghi4.in");
ofstream fout("triunghi4.out");

struct numere
{
    int poz;
    long long int nr;
} q[NMAX];

long long int lin[2][NMAX];

int main()
{
    int n,i,pred,succ,j,c;
    fin>>n;
    for(i=n; i>=1; i--)
        fin>>q[i].poz>>q[i].nr;
    lin[0][q[1].poz]=q[1].nr;
    pred=0;
    succ=1;
    for(i=2; i<=n; i++)
    {
        lin[succ][q[i].poz]=q[i].nr;
        for(j=q[i].poz+1; j<=i; j++)
            lin[succ][j]=lin[pred][j-1]-lin[succ][j-1];
        for(j=q[i].poz-1; j>=1; j--)
            lin[succ][j]=lin[pred][j]-lin[succ][j+1];
        c=pred;
        pred=succ;
        succ=c;
    }
    for(i=1; i<=n; i++)
        fout<<lin[pred][i]<<" ";
    fout<<'\n';
    return 0;
}
