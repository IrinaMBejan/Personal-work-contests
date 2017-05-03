#include <fstream>
#include<cstring>
using namespace std;
ifstream fin("kpal.in");
ofstream fout("kpal.out");

char s[5001];
int main()
{
    int k,n,i,st,dr,rr,nr=0;
    fin>>k;
    fin>>s;
    n=strlen(s);
    for(i=0;i<n;i++)
    {
        st=i-1; dr=i+1;
        rr=0;
        while(st>=0&&dr<n)
        {
            if(s[st]!=s[dr])
                rr++;
            if(rr==k||(k-rr)%2==1)
                nr++;
            st--;
            dr++;
        }
        st=i;
        dr=i+1;
        rr=0;
        while(st>=0&&dr<n)
        {
            if(s[st]!=s[dr])
                rr++;
            if(rr==k||(k-rr)%2==0)
                nr++;
            st--;
            dr++;
        }
    }
    if(k==1) nr+=strlen(s);
    fout<<nr<<'\n';
    return 0;
}
