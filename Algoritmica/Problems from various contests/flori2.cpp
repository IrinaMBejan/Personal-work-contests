#include <fstream>

using namespace std;
ifstream fin("flori2.in");
ofstream fout("flori2.out");

int main()
{
    int n, s=0,a1=1,a2=2,c;
    {
        fin>>n;
        int i=1;
        if(n==1) fout<<"1";
        else if(n==2) fout<<"2";
        else
        while(i<n-1)
        {
            c=a1;
            a1=a2%9001;
            a2=a1+c;
            s+=a1;
            s%=9001;
            i++;
        }
        fout<<(s+2)%9001<<'\n';
    }
    return 0;
}
