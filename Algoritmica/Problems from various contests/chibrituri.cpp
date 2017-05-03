#include <fstream>

using namespace std;

ifstream fin("chibrituri.in");
ofstream fout("chibrituri.out");
int a1,a2,a3,a4,min;
void calc(int x)
{
    a1=(x%60)%10;
    a2=(x%60)/10;
    a3=(x/60)%10;
    a4=(x/60)/10;
}

int main()
{
    int nro, nrv,min=0,sv=0,so=0, nrmin,nrmax, nrs=0;
    int v[11]={4,2,2,2,3,2,3,2,4,3};
    int o[11]={2,0,3,3,1,3,3,1,3,3};
    fin>>nrv>>nro;
    for(min=0;min<=1439;min++)
    {
        calc(min);
        sv=v[a1]+v[a2]+v[a3]+v[a4];
        so=o[a1]+o[a2]+o[a3]+o[a4];
        if(sv==nrv&&nro==so)
        {
            if(nrs==0) nrmin=min;
            nrs++;
            nrmax=min;
        }
    }
   fout<<nrs<<'\n';
    calc(nrmin);
    fout<<a4<<a3<<":"<<a2<<a1<<'\n';
    calc(nrmax);
    fout<<a4<<a3<<":"<<a2<<a1<<'\n';
    return 0;
}
