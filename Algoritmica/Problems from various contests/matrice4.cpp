#include <fstream>
#include<math.h>
#include<algorithm>
using namespace std;
ifstream fin("matrice4.in");
ofstream fout("matrice4.out");

int a[51][51],x,c[2590];

int compare(int a, int b)
{
    return a<b;
}
int prim(int p)
{
    int i;
    for(i=2;i<=sqrt((double)p);i++)
        if(p%i==0) return 0;
    return 1;
}
int main()
{
    int n,m,nr,i,max,j;
    fin>>n>>m;
    max=0;
    nr=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            fin>>a[i][j];
            x=a[i][j];
            while(!prim(x))
                x++;
            x=x-a[i][j];
            if(x>max) {max=x; nr=1; c[nr]=a[i][j]+max;}
            else if(x==max) { nr++; c[nr]=a[i][j]+max;}
        }
    fout<<max+1<<" "<<nr<<" ";
    fout<<'\n';
    sort(c+1,c+nr+1,compare);
    for(i=1;i<=nr;i++)
        fout<<c[i]<<" ";
    fout<<'\n';

    return 0;
}
