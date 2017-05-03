#include <fstream>

using namespace std;
ifstream fin("kafka.in");
ofstream fout("kafka.out");

struct office
{
    int cul;
    int ok;
    int birou;
} a[4001];

int main()
{
    int nc,nb,bs,t,c,b,poz,i,gasit=0,k;
    fin>>nb>>nc>>bs>>t;
    c=1;
    b=bs;
    int nrp;
    for(i=1; i<=nb*nb; i++)
        fin>>a[i].cul>>a[i].birou;
    for(i=1; i<t&&!gasit; i++)
    {
        poz=(b-1)*nc+c;
        if(a[poz].ok==0)
        {
            c=a[poz].cul;
            b=a[poz].birou;
            a[poz].ok=i;
  //          fout<<poz<<'\n';
        }
        else
        {
            gasit=1;
            nrp=(t-a[poz].ok+1)%(i-a[poz].ok);
   //         fout<<"!!!"<<poz<<'\n';
        }
    }
    if(gasit)
        for(k=1; k<nrp; k++)
        {
            poz=(b-1)*nc+c;
            c=a[poz].cul;
            b=a[poz].birou;
       //     fout<<b<<" "<<poz<<'\n';

        }
    fout<<b<<'\n';
    return 0;
}
