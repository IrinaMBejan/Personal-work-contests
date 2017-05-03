#include <fstream>

using namespace std;
ifstream fin("ciur.in");
ofstream fout("ciur.out");

bool a[2000001];
int main()
{
    int n,i,k,nr=0;
    for(i=4; i<=2000000; i+=2)
        a[i]=1;
    for(i=3; i<=1415; i+=2)
        if(!a[i])
        {
            for(k=i*i; k<=2000000; k+=i)
                a[k]=1;
        }
    fin>>n;
    for(i=2; i<=n; i++)
        if(!a[i]) nr++;
    fout<<nr<<'\n';
    return 0;
}
