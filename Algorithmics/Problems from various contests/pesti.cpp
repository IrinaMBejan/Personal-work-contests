# include <fstream>
# include <cmath>

using namespace std;
ifstream fin("pesti.in");
ofstream fout("pesti.out");

unsigned long n,x,a,b,c,z,u,p,zi=1;
long double r;

int main()
{
    fin>>n>>x;
    int z=1, pp=2;
    while(pp<n)
    {
        pp*=2;
        z++;
    }
    fout<<z-1<<" ";
    a=1;
    b=n;
    u=0;
    do
    {
        p=x;
        if((x-a)%2==0)
        {
            b=(a+b)/2;
            x=a+(x-a)/2;
        }
        else
        {
            c=(a+b)/2;
            x=c+(x-a+1)/2;
            a=c+1;
        }
        u++;
        if(x!=p) zi=u;
    }
    while (b-a>1);
    fout<<x<<' '<<zi<<'\n';
    fin.close();
    fout.close();
    return 0;
}
