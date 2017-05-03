#include <fstream>

using namespace std;
ifstream fin("cifreco.in");
ofstream fout("cifreco.out");

int main()
{
    long long i, n, nr, s, x, y, first=1, nrsol=0;
    int k, nrcif, ucnr;
    fin>>n;
    fin>>x>>y;

    for(i=1; i<n-1; i++)
        first=first*10+1;
    first=first*10+9;

    for(i=(x-first)/9; i<=(y-first)/9; i++)
    {

        nrsol++;
        nr=i;
        nrcif=0;
        while (nr%10==8)
        {
            nr/=10;
            nrcif++;
        }
        if (nr!=i)
        {
            if (nr==0)
                for(s=1,k=1; k<=nrcif; k++)
                    s=s*10+1;
            else
            {
                ucnr=nr%10+1;
                nr++;
                for(k=1; k<=nrcif; k++)
                    nr=nr*10+ucnr;
                s=nr;
            }
            i=--s;
        }
    }
    fout<<nrsol<<"\n";
    return 0;
}
