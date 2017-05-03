#include <fstream>
#define NMAX 49001
using namespace std;

ifstream fin("turn.in");
ofstream fout("turn.out");

char v[NMAX];
int k,n;


void citire();
void afisare();
int cautasielimina();

int main()
{
    citire();
    while(cautasielimina());
    afisare();
    return 0;
}

void citire()
{
    int i,x;
    fin>>n>>k;
    for(i=0; i<n; i++)
    {
        fin>>x;
        v[i]=x;
    }
    fin.close();
}
int cautasielimina()
{
    int i,lg=1,j;
    for(i=0; i<n-1; i++)
        if(v[i]==v[i+1])
            lg++;
        else if(lg>=k)
            break;
        else
            lg=1;
    if(lg<k)
        return 0;

    for(j=i+1; j<n; j++)
        v[j-lg]=v[j];
    n-=lg;
    return 1;
}

void afisare()
{
    int i;
    fout<<n<<'\n';
    for(i=0; i<n-1; i++)
        fout<<(int)v[i]<<' ';
    fout<<(int)v[n-1];
    fout<<'\n';
}


/*#include <fstream>
#define NMAX 49001
using namespace std;
ifstream fin("turn.in");
ofstream fout("turn.out");

struct secv
{
    int st,fi,val;
} a[NMAX];

int q;
int main()
{
    int i,n,k,x,nr;
    fin>>n>>k;
    nr=n;
    a[++q].st=1;
    fin>>a[q].val;
    a[q].fi=1;
    for(i=2; i<=n; i++)
    {
        fin>>x;
        if(x==a[q].val)
            a[q].fi++;
        else
        {
            if(a[q].fi-a[q].st+1>=k)
            {
                nr-=(a[q].fi-a[q].st+1);
                q--;
            }
            if(x==a[q].val)
                a[q].fi++;
            else
            {
                a[++q].val=x;
                a[q].st=a[q-1].fi+1;
                a[q].fi=a[q].st;
            }
        }
    }
    while(a[q].fi-a[q].st+1>=k)
            {
                nr-=(a[q].fi-a[q].st+1);
                q--;
            }
    fout<<nr<<'\n';
    for(i=1;i<=q;i++)
        for(int j=1;j<=a[i].fi-a[i].st+1;j++)
            fout<<a[i].val<<" ";
    fout<<'\n';
    return 0;
}
*/
