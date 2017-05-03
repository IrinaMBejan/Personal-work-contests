#include <fstream>

using namespace std;
ifstream fin("triunghi1.in");
ofstream fout("triunghi1.out");

int main()
{
    int L,C,first,q;
    fin>>L>>C;
    long long int before;
    before=(L-1)*L/2;
    first=before%9+1;
    q=C%9+first-1;
    if(q>9) q-=10;
    if(q==0) q=1;
    fout<<q<<'\n';
    return 0;
}
