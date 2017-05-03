#include <fstream>

using namespace std;
ifstream fin("interviu.in");
ofstream fout("interviu.out");

int main()
{
    int n,i,x,max=0;
    fin>>n;
    for(i=1;i<=3;i++)
    {
        fin>>x;
        if(x>max) max=x;
    }
    fin>>x;
    i=4;
    while(x<=max&&i<n)
    {
        fin>>x;
        i++;

    }
    fout<<i<<'\n';

    return 0;
}
