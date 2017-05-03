#include <fstream>

using namespace std;
ifstream fin("cabina.in");
ofstream fout("cabina.out");
int main()
{
    int n,i,x=0,alt,pers,a,b,nr=0,cost=0;
    fin>>n;
    fin>>alt>>pers;
    for(i=1;i<n;i++)
    {
        fin>>a>>b;
        pers+=b;
        if(alt>a)
        {
            if(x==3) nr++;
            x=1;
            cost+=(alt-a);

        }
        else
        {
            if(x==1) nr++;
            x=3;
            cost+=((a-alt)*x);
        }
        alt=a;
    }
    fout<<pers<<'\n'<<cost<<'\n'<<nr<<'\n';
    return 0;
}
