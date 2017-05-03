#include <fstream>
#define NMax 1441
using namespace std;

ifstream fin("consiliu.in");
ofstream fout("consiliu.out");

int x[NMax];
int main()
{
    int n,j,i,hs,ms,hf,mf,in,f,nrt=0;
    fin>>n;
    for(j=1;j<=n;j++)
    {
        fin>>hs>>ms>>hf>>mf;
        in=hs*60+ms;
        f=hf*60+mf;
        if(in<f)
            for(i=in;i<f;i++)
                x[i]++;
        else if(in>f)
        {
            for(i=in;i<1440;i++)
                x[i]++;
            for(i=0;i<f;i++)
                x[i]++;
        }
        else if(in==f)
            for(i=0;i<1440;i++)
                x[i]++;
    }
    for(i=0;i<1440;i++)
        if(x[i]==n) nrt++;
    fout<<nrt<<'\n';

    return 0;
}
