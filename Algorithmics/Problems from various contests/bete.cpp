#include <fstream>

using namespace std;

ifstream fin("bete.in");
ofstream fout("bete.out");

int main()
{
    int a,b,s,val,maxa,maxb,nrmaxa,nrmaxb,nr,i;
    s=0;
    fin>>nr;
    for(i=1;i<=nr;i++)
    {
        fin>>a;
        if(a>maxa) {maxa=a; nrmaxa=1;}
        else if(a==maxa) nrmaxa++;
        s+=a;
    }
    for(i=1;i<=nr;i++)
    {
        fin>>b;
        if(b>maxb) {maxb=b; nrmaxb=1;}
        else if(b==maxb) nrmaxb++;
        s+=b;
    }


    val=s/nr;
    fout<<val;
     fout<<'\n'<<maxa+maxb<<'\n';
    if(nrmaxb<=nrmaxa) fout<<nrmaxb;
    else fout<<nrmaxa;
    return 0;
}
