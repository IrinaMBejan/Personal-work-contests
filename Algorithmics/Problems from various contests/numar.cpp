#include <fstream>
#define LGMAX 2001
using namespace std;

ifstream fin("numar.in");
ofstream fout("numar.out");

typedef short int NRMARE[LGMAX];
NRMARE x,y;

void afisare(NRMARE c);
void impartint(NRMARE a, int b);

int main()
{
    int n,m,i,nrcin=0,nrdo=0,j;
    fin>>n>>m;
    y[0]=m+1;
    for(i=1; i<=n; i++)
        fin>>x[n+m-i+1];

    for(i=1; i<=m; i++)
        fin>>x[m-i+1];

    x[0]=n+m;
    if (x[n+m]==0)
    {
        x[0]--;
    }
    int st=1;
    j=1;
    while(x[st]==0)
    {
        st++;
        y[0]--;
    }
    for(i=st; i<=x[0]; i++)
    {
        x[j]=x[i];
        j++;
    }
    x[0]=x[0]-st+1;
    y[y[0]]=1;
    while((x[1]%5==0&&y[1]%5==0)||(x[1]%2==0&&y[1]%2==0))
    {
        if(x[1]%5==0)
        {
            impartint(x,5);
            impartint(y,5);
        }
        else if(x[1]%2==0)
        {
            impartint(x,2);
            impartint(y,2);
        }
    }
    afisare(x);
    afisare(y);
    return 0;
}


void afisare(NRMARE c)
{
    int i;
    fout<<c[0]<<'\n';
    for(i=c[0]; i>=1; i--)
        fout<<c[i];
    fout<<'\n';
}

void impartint(NRMARE a,  int b)
{
    int i,t;
    for(t=0,i=a[0]; i>0; i--)
    {
        t=t*10+a[i];
        a[i]=t/b;
        t=t%b;
    }
    while(a[a[0]]==0&&a[0]>0)
        a[0]--;
}
