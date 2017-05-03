#include <fstream>

using namespace std;
ifstream fin("euclid3.in");
ofstream fout("euclid3.out");

int EuclidExtins(int a, int b, int &x, int&y);
int main()
{

    int a,b,c,T,x,y,d;

    fin>>T;

    while(T--)
    {
        fin>>a>>b>>c;

        d = EuclidExtins(a,b,x,y);
        if(c%d != 0)
            fout<<"0 0"<<'\n';
        else
            fout<<x*(c/d)<<" "<<y*(c/d)<<'\n';
    }
    return 0;
}

int EuclidExtins(int a, int b, int &x, int&y)
{
    if(b == 0)
    { x = 1; y = 0; return a; }

    int x1,y1;
    int d = EuclidExtins(b,a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
    return d;
}
