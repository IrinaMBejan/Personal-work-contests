#include <fstream>

using namespace std;
ifstream fin("vanatoare.in");
ofstream fout("vanatoare.out");

int main()
{
    int a=1,b=2,c,ok=1,ka,kb,i=0,na,nn;
    fin>>ka>>kb;
    while (ok)
    {
        if (a%2==1)
            {
                na=a/2+1;
                nn=a-na;
            }
        else
            {
                na=a/2;
                nn=na;
            }
        if (na<=ka&&nn<=kb)
            {
                ka-=na;
                kb-=nn;
            }
        else ok=0;
        c=a;
        a=b;
        b=a+c;
        i++;
    }
    fout<<i-1<<'\n'<<ka<<'\n'<<kb<<'\n';
    return 0;
}
