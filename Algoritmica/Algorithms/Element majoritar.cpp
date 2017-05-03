#include <fstream>

using namespace std;
ifstream fin("elmaj.in");
ofstream fout("elmaj.out");

int a[1000001];
int main()
{
    int n,i, cand=-1,k=0;
    fin>>n;
    for(i=1;i<=n;i++)
     {
         fin>>a[i];
         if(!k) {cand=a[i]; k=1;}
         else if(a[i]==cand) k++;
         else k--;
     }
    int nr=0;
    for(i=1;i<=n;i++)
        if(a[i]==cand) nr++;
    fout<<cand<<" "<<nr<<'\n';
    return 0;
}
