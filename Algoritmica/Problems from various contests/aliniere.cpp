#include <fstream>

using namespace std;
ifstream fin("aliniere.in");
ofstream fout("aliniere.out");

int main()
{
    int n, a1=1,a2=2,i,sr,c;
    fin>>n;
    if (n==1)
        fout<<a1<<'\n';
    else if (n==2)
        fout<<a2<<'\n';
         else
            {
                for(i=3;i<=n;i++)
                {
                    a2%=9973;
                    c=a2;
                    a2+=a1;
                    a1=c;
                }
            }
    fout<<a2%9973;
    return 0;
}
