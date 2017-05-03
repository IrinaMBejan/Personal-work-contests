#include <fstream>

using namespace std;
ifstream fin("adunscad.in");
ofstream fout("adunscad.out");

bool c[21];
int a[21];

int main()
{
    int N,M,q,s,i,ok;
    fin>>N>>M;
    q=0;
    for(i=1;i<=M;i++)
    {
        fin>>a[i];
        q+=a[i];
    }
    ok=1;
    while(ok)
    {
            s=q;
            for(i=1;i<=M;i++)
                if(c[i]==0) s-=(2*a[i]);
            if(s==N) break;
            else
            {
                for(i=M;i>0&&c[i]==1;i--) c[i]=0;
                if(i!=0)
                        c[i]=1;
                else ok=0;
            }
    }
    if(s==N)
    {
    if(c[1]==0) fout<<'-'<<a[1];
    else fout<<a[1];
    for(i=2;i<=M;i++)
    {
        if(c[i]==0) fout<<'-'<<a[i];
        else fout<<'+'<<a[i];
    }
    }
    else fout<<'0';
    fout<<'\n';
    return 0;
}
