#include <fstream>

using namespace std;
ifstream fin("fact.in");
ofstream fout("fact.out");

struct prim
{
    int ok;
    int put;
    int putprod;
}d[40];
int main()
{
    for(i=1;i<=5;i++)
    {
        memset(d,0,sizeof(d));
        fin>>N>>B;
        for(i=2;i*i<=B;i++)
            if(B%i==0)
            {
                d[i][0]=1;
                while(B%i==0)
                {
                    B/=i;
                    d[i][1]++;
                }
            }
        for(i=1;i<=N;i++)

    }
    return 0;
}
