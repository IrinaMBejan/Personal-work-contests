#include <fstream>
#include<cmath>
#include<algorithm>
#define NMAX 1002
using namespace std;
ifstream fin("poligon4.in");
ofstream fout("poligon4.out");

struct punct
{
    int lin;
    int col;
} A[NMAX*150];

int R[NMAX];

int compare(punct a, punct b)
{
    return a.lin*b.col<a.col*b.lin;
}
int main()
{
    int N,i,p,x,y,k=0;
    fin>>N;
    for(i=1; i<=N; i++)
    {
        fin>>R[i];
        p=R[i]*R[i];
        for(x=1; x<=R[i]-1; x++)
        {
            y=(int)sqrt((double)p-x*x);
            if(y*y+x*x==p)
            {
                A[++k].lin=y;
                A[k].col=x;
            }
        }
    }
    fout<<k<<'\n';

    sort(A+1,A+k+1,compare);

    A[++k].lin=1;
    A[k].col=-1;
    int nr=0;

    for(i=1; i<=k; i++)
        if(A[i].lin*A[i+1].col<A[i].col*A[i+1].lin)
            nr++;

    fout<<nr<<'\n';
    int s=1;
    for(i=1; i<=k; i++)
    {
        if(A[i].lin*A[i+1].col==A[i].col*A[i+1].lin)
            s++;
        else
        {
            fout<<s<<" ";
            s=1;
        }
    }
    return 0;
}
