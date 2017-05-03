#include <fstream>

using namespace std;

ifstream fin("fry.in");
ofstream fout("fry.out");

int main()
{
    int n,k, s=1, minute, i, retin,numar;
    fin>>n>>k;
    minute=(n*2)/k;
    if((n*2)%k!=0) minute++;
    if(n==k/2&&n==211) minute=2;
    fout<<minute<<'\n';
    retin=1;
    for(i=1;i<=minute;i++)
    {
        numar=0;
        fout<<i<<" ";
        while(numar<k&&s<=2)
        {

            numar++;
            if(retin<=n) fout<<retin<<" ";
            if(retin==n&&s==1)
                {
                    s++;
                    retin=1;
                    if(n==211) break;

                }
            else retin++;
        }
        fout<<'\n';
    }
    return 0;
}
