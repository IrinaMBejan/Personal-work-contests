#include<cmath>
#include<iostream>

using namespace std;


int Euclid(int a, int b, int &x, int &y)
{
    int x1,y1;
    int q;
    if(b>a) return Euclid(b,a,y,x);
    if(b == 0) {x = 1; y = 0; return a;}
    q = Euclid(b, a%b, x1, y1);
    x = y1;
    y = (x1 - floor(a/b)*y1);
    return q;
}

int main()
{
        int A,B;
        int x = -1, y=-1,q;
        while(cin>>A>>B)
        {
            q = Euclid(A,B,x,y);
            cout<<x<<" "<<y<<" "<<q<<'\n';
        }
        return 0;
}
