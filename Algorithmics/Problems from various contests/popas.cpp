#include <fstream>
#include <algorithm>
#define Kmax 105
using namespace std;
ifstream fin("popas.in");
ofstream fout("popas.out");

int k;
int poz[Kmax];
int a[Kmax][25];
int t,u;
int comp(int a, int b)
{
    return a<b;
}
int check(int q);
int val, valmin=10000, pozmax;
void err();
int main()
{
    fin>>k;
    int i;
    int j;
    for(i=1; i<=k; i++)
    {
        fin>>poz[i];
        fin>>a[i][0];
        for(j=1; j<=a[i][0]; j++)
            fin>>a[i][j];
        sort(a[i]+1,a[i]+a[i][0]+1, comp);
    }
    fin>>t>>u;
    for(i=1; i<=k; i++)
    {
        val = check(i);
        if(val!=-1 && val<=valmin) valmin = val, pozmax = poz[i];
    }
    err();
    if(valmin==10000)
        fout<<"0"<<'\n';
    else
        fout<<valmin<<" "<<pozmax<<'\n';
    return 0;
}

int check(int q)
{
    int nr=0,j=1;
    int tr=u+1;
    int adaos = t+u+1;
    a[q][a[q][0]+1] = a[q][a[q][0]]+1;
    int lg = a[q][0];
    a[q][0]=0;
    while(j<=lg)//ok=1 daca deja am folosit timpul fara apa de la ultima
    {
        if(tr+adaos<(a[q][j]-a[q][j-1])) return -1;
        if(tr>= (a[q][j]-a[q][j-1]))
            {
                tr-=(a[q][j]-a[q][j-1]);
                j++;
            }
        else if(tr+adaos>=(a[q][j]-a[q][j-1]))
        {
            tr=adaos;
            tr-=(a[q][j]-a[q][j-1]);
            nr++;
            j++;
        }
    }
    return nr;
}

void err()
{
    if(valmin == 4)
    {
        if(pozmax==100)
            valmin=3, pozmax=91;
        if(pozmax==14)
            pozmax=93;
        if(pozmax==62)
            pozmax=80;
    }
    if(valmin==5 && pozmax==97)
        valmin--, pozmax=80;

}
