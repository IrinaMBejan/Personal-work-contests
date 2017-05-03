#include <fstream>

using namespace std;
ifstream fin("reflex.in");
ofstream fout("reflex.out");

int main()
{
    long long int n,m;
    fin>>n>>m;
    if(n==m)
    {
        fout<<n<<" 3"<<'\n';
        fout<<"0 0"<<'\n';
    }
    else if((m-1)%(n-1)==0)
    {
        if(m/n%2==1)
        {
            fout<<1+((m-1)/(n-1))*2*1LL<<" 2"<<'\n';
            fout<<m/n*2+1<<" 0"<<'\n';
        }
        else
        {
            fout<<1LL*((m-1)/(n-1))*2+n<<" 3"<<'\n';
            fout<<m/n*2<<" 0"<<'\n';
        }
    }
    else
    {
        fout<<1LL*(n-1)*(m/n)*2+n<<" 4"<<'\n';
        fout<<m/n*2<<" 1"<<'\n';
    }
    return 0;
}
