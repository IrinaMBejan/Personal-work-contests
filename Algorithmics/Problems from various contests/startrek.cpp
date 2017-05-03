#include <fstream>
#include<algorithm>
using namespace std;
ifstream fin("startrek.in");
ofstream fout("startrek.out");


int compare(int a, int b)
{
    return a<b;
}
int t[4001];
int main()
{
    int n,tt,i,tr,nr,x;
    fin>>n>>tt;
    for(i=1;i<=n;i++)
        fin>>t[i];
    for(i=1;i<=n;i++)
    {
        fin>>x;
        t[i]/=x;
    }
    sort(t+1,t+n+1,compare);
    nr=1;
    tr=tt;
    for(i=2;i<=n;i++)
        if(t[i]>=tr){nr++; tr+=tt;}
    fout<<nr<<'\n';
    return 0;
}
