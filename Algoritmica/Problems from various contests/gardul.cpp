#include <fstream>


using namespace std;
ifstream fin("gardul.in");
ofstream fout("gardul.out");
int main()
{
    int n,q,p,r,nr,na,nv,p1,q1,cmmmc;
    fin>>n>>p>>q;
    p1=p;
    q1=q;
    while(q1)
    {
        r=p1%q1;
        p1=q1;
        q1=r;
    }
    cmmmc=(p*q)/p1;
    nv=n/cmmmc;
    nr=n/p-nv;
    na=n/q-nv;
    fout<<n-nv-na-nr<<'\n'<<nr<<'\n'<<na<<'\n'<<nv<<'\n';
    return 0;
}
