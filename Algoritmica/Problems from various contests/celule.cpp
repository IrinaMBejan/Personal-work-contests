#include <fstream>
using namespace std;

ifstream fin("celule.in");
ofstream fout("celule.out");
int main()

{
    int n,m,r,a,b,q=0,i,c;
    fin>>n>>m;

        int fn=0, fm=0;
        while(n%2==0) { fn++; n/=2;}
        while(m%2==0) { fm++; m/=2;}
        if(fn>fm) q+=(fn-fm);
        else q+=(fm-fn);
        for( i=3; i<=n||i<=m; i+=2)
        {
            fn=0; fm=0;
            while(n%i==0) {n/=i; fn++; }
            while(m%i==0) {m/=i; fm++;}
            if(fn>fm) q+=(fn-fm);
            else q+=(fm-fn);
        }
        fout<<q<<'\n';
    return 0;
}
