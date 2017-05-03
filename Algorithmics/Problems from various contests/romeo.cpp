#include <fstream>

using namespace std;
ifstream fin("romeo.in");
ofstream fout("romeo.out");

int main()
{
    int x,y;
    fin>>x>>y;
    if(x>y-1) fout<<x+y<<'\n';
    else
    {
        int M,N,Z,tot=x;
        Z=y/(x+1);
        N=y-Z*(x+1);
        M=x+1-N;
        tot+=M*Z*(Z+1)/2;
        tot+=N*(Z+1)*(Z+2)/2;
        fout<<tot<<'\n';
    }
    return 0;
    return 0;
}
