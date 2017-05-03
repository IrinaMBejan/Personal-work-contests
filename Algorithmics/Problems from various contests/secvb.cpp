#include <fstream>

using namespace std;
ifstream fin("secvb.in");
ofstream fout("secvb.out");
int nrbit(int n);
int a[50001];

int main()
{
    int n,S,i;
    fin>>n>>S;
    for(i=1; i<=n; i++)
    {
        fin>>a[i];
        a[i]=nrbit(a[i]);
    }
    int st=1,fi=1,nrsecv=0,s=a[1];
    while(fi<=n)
    {
        if(s<S)
            s+=a[++fi];
        else if(s==S)
        {
            nrsecv++;
            s-=a[st++];
        }
        else if(s>S) s-=a[st++];
    }
    fout<<nrsecv<<'\n';
    return 0;
}

int nrbit(int n)
{
    int nr=1;
    while(n&=(n-1))
        nr++;
    return nr;
}
