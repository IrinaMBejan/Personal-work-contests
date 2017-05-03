#include <fstream>

using namespace std;
ifstream fin("elfi.in");
ofstream fout("elfi.out");

int v[14401];
int main()
{
    int n,i,c,p,t,max,x;
    fin>>n;
    for(i=1; i<=n; i++)
    {
        fin>>c>>p;
        t=2*c+p+1;
        x=t;
        while(x<=14401)
        {
            v[x]++;
            x+=t;
        }
    }
    max=0;
    for(i=1; i<=14400; i++)
        if(v[i]>max) max=v[i];
    fout<<max<<'\n';
    return 0;
}
